#include "migration/qemu-file.h"
#include "hw/android/goldfish/device.h"
#include "hw/android/goldfish/nand.h"
#include "hw/android/goldfish/vmem.h"
#include "hw/hw.h"
#include "hw/irq.h"
#include "android/utils/path.h"
#include "android/utils/tempfile.h"
#include "android/qemu-debug.h"
#include "android/android.h"
#include "android/skin/event.h"

extern int SDL_SendCustomEvent(int code, void* data);

#define KVSSD_READY	0
#define KVSSD_BUSY	1
#define KVSSD_WAIT	2


#define READ_CMD	0
#define WRITE_CMD	1

#define CMD_PUT		3
#define CMD_GET		4
#define CMD_ERASE	5
#define CMD_EXIST	6

#define WAIT_FOR_COMPLETION	1

#define MAX_BLOCK 1024*512

enum {
	/* CMD Registers */

	KVSSD_STATUS_REG	=0x00,
	KVSSD_CMD_REG		=0x04,
	KVSSD_KEY_REG		=0x08,
	KVSSD_VALUE_REG		=0x0C,
};


struct goldfish_kvssd_state {
	struct goldfish_device dev;
	int kvssd_fd;
	int kvssd_meta;
	uint32_t status; //Ready: 0, Busy: 1
	uint32_t cmd;	//Read: 0, Write: 1
	uint32_t key[4];			//current		
	uint32_t value_pos;
	uint32_t key_pos;
	uint32_t pbn;
	uint32_t wait;
	uint32_t kvssd_value[1024];		//current
	
	uint32_t kvssd_block[MAX_BLOCK];	//meta
	uint32_t kvssd_key[MAX_BLOCK];	//meta
	uint32_t kvssd_keypos[MAX_BLOCK];	//mtea
};

#define KVSSD_STATE_SAVE_VERSION	3
#define QFIELD_STRUCT	struct goldfish_kvssd_state

QFIELD_BEGIN(goldfish_kvssd_fields)
	QFIELD_INT32(status),
	QFIELD_INT32(cmd),
	QFIELD_INT32(value_pos),
	QFIELD_INT32(key_pos),
	QFIELD_INT32(pbn),
	QFIELD_INT32(wait),
QFIELD_END

static void goldfish_kvssd_save(QEMUFile* f, void* opaque)
{
	struct goldfish_kvssd_state* s = opaque;
	/* TODO */
	qemu_put_buffer(f, (uint8_t*)s->kvssd_value, 1024 * 4);
	qemu_put_buffer(f, (uint8_t*)s->key, 4*4);
	qemu_put_buffer(f, (uint8_t*)s->kvssd_block, MAX_BLOCK * 4);
	qemu_put_buffer(f, (uint8_t*)s->kvssd_key, MAX_BLOCK*4);
	qemu_put_buffer(f, (uint8_t*)s->kvssd_keypos, MAX_BLOCK*4);
	qemu_put_struct(f, goldfish_kvssd_fields, s);
}

static int goldfish_kvssd_load(QEMUFile* f, void* opaque, int version_id)
{
	struct goldfish_kvssd_state* s = opaque;
	if ( version_id != KVSSD_STATE_SAVE_VERSION )
		return -1;
	/* TODO */
	qemu_get_buffer(f, (uint8_t*)s->kvssd_value, 1024 * 4);
	qemu_get_buffer(f, (uint8_t*)s->key, 4*4);
	qemu_get_buffer(f, (uint8_t*)s->kvssd_block, MAX_BLOCK * 4);
	qemu_get_buffer(f, (uint8_t*)s->kvssd_key, MAX_BLOCK*4);
	qemu_get_buffer(f, (uint8_t*)s->kvssd_keypos, MAX_BLOCK*4);
	qemu_get_struct(f, goldfish_kvssd_fields, s);
	return 0;
}

/*static off_t do_lseek(int fd, off_t offset, int whence) {
	off_t ret;

	do {
		ret = lseek(fd, offset, whence);
	} while (ret == -1 && errno == EINTR);

	return ret;
}

static int do_write(int fd, const void *buf, size_t size) {
	int ret;
	do {
		ret = write(fd, buf, size);
	} while (ret < 0 && errno == EINTR);

	return ret;
}*/

static void goldfish_kvssd_meta_write(struct goldfish_kvssd_state *s) {
	pwrite(s->kvssd_meta, s->kvssd_block, sizeof(s->kvssd_block), 0);
	pwrite(s->kvssd_meta, s->kvssd_key, sizeof(s->kvssd_key), sizeof(s->kvssd_block));
	pwrite(s->kvssd_meta, s->kvssd_keypos, sizeof(s->kvssd_keypos), sizeof(s->kvssd_block)+sizeof(s->kvssd_key));
	fsync(s->kvssd_meta);
	return;
}

static void goldfish_kvssd_meta_read(struct goldfish_kvssd_state *s) {
	pread(s->kvssd_meta, s->kvssd_block, sizeof(s->kvssd_block), 0);
	pread(s->kvssd_meta, s->kvssd_key, sizeof(s->kvssd_key), sizeof(s->kvssd_block));
	pread(s->kvssd_meta, s->kvssd_keypos, sizeof(s->kvssd_keypos), sizeof(s->kvssd_block)+sizeof(s->kvssd_key));
	return;
}

static uint32_t goldfish_kvssd_read(void* opaque, hwaddr offset, uint32_t value)
{
	struct goldfish_kvssd_state* s = (struct goldfish_kvssd_state*)opaque;
	uint32_t temp;

	if ( offset < 0 ) {
		cpu_abort(cpu_single_env, "kvssd_dev_read: Bad offset %" HWADDR_PRIx "\n", offset);
		return 0;
	}

	switch (offset) {
		case KVSSD_STATUS_REG:
			return s->status;
		case KVSSD_KEY_REG:
			temp = 1;
			int i=0;
			for(i=0; i<4; i++) temp += s->key[i];
			goldfish_kvssd_meta_read(s);
			i = 0;
			while(i<MAX_BLOCK){
				if(s->kvssd_keypos[i] == temp){
					return 1;
				}
				i++;
			}
			return 0;
		case KVSSD_VALUE_REG:
			temp = s->value_pos;
			s->value_pos = (s->value_pos+1)%1024;
			return s->kvssd_value[temp];
	};

	return 0;
}

#define PAGE_SHIFT 12

static int goldfish_kvssd_data_read(struct goldfish_kvssd_state *s) {
	pread(s->kvssd_fd, s->kvssd_value, sizeof(s->kvssd_value), s->pbn << PAGE_SHIFT);

	return 1;
}

static int goldfish_kvssd_data_write(struct goldfish_kvssd_state *s) {
	pwrite(s->kvssd_fd, s->kvssd_value, sizeof(s->kvssd_value), s->pbn << PAGE_SHIFT);
	fsync(s->kvssd_fd);
	
	return 0;
}




static void goldfish_kvssd_write(void* opaque, hwaddr offset, uint32_t value)
{
	struct goldfish_kvssd_state* s = (struct goldfish_kvssd_state*)opaque;
	int status;

	if ( offset < 0 ) {
		cpu_abort(cpu_single_env, "kvssd_dev_read: Bad offset %" HWADDR_PRIx "\n", offset);
		return;
	}
	
	uint32_t i=0;
	uint32_t j=0;
	uint32_t temp = 0;

	switch (offset) {
		case KVSSD_CMD_REG:
			s->status = KVSSD_BUSY;
			s->cmd = value;
			switch(s->cmd) {
				case CMD_GET:
					goldfish_kvssd_meta_read(s);
					temp = 1;
					for(i=0; i<4; i++) temp += s->key[i];
					i = 0;
					while(i< MAX_BLOCK){
						if(s->kvssd_keypos[i] == temp) break;
						i++;
					}
					if(i==MAX_BLOCK){
						s->pbn = 0;
						status = goldfish_kvssd_data_read(s);
						break;
					}
					else{
						s->pbn = s->kvssd_key[i];;
						status = goldfish_kvssd_data_read(s);
					}
					break;
				case CMD_PUT:
					goldfish_kvssd_meta_read(s);
					temp = 1;
					for(i=0; i<4; i++) temp += s->key[i];
					i = 0;
					j = 0;
					int check = 0;
					while(i< MAX_BLOCK){
						j = i;
						if(s->kvssd_keypos[i] == temp){
							check = 1;
							s->kvssd_block[s->kvssd_key[i]] = 2;
							while(s->kvssd_block[j]) j++;
							s->kvssd_block[j] = 1;
							s->kvssd_key[i] = j;
							break;
						}
						i++;
					}
					if(check == 1){
						goldfish_kvssd_meta_write(s);
						s->pbn = j;
						status = goldfish_kvssd_data_write(s);	
					}
					else{
						i = 0;
						j = 0;
						while(s->kvssd_keypos[i] && i<MAX_BLOCK) i++;
						while(j<MAX_BLOCK-4){
							if(s->kvssd_block[j] == 0){
								s->kvssd_block[j] = 1;
								s->kvssd_key[i] = j;
								s->kvssd_keypos[i] = temp;
								goldfish_kvssd_meta_write(s);
								s->pbn = j;
								status = goldfish_kvssd_data_write(s);					
								break;
							}
							j++;
						}
						if(j==MAX_BLOCK-4){
							i = 0;
							while(i<MAX_BLOCK){
								if(s->kvssd_block[s->key[i]] == 2){
									s->kvssd_block[s->key[i]] = 0;
									s->kvssd_key[i] = 0;
									s->kvssd_keypos[i] = 0;
								}
								i++;
							}
							i = 0;
							j = 0;
							while(s->kvssd_keypos[i] && i<MAX_BLOCK) i++;
							while(s->kvssd_block[j]) j++;
							if(j==MAX_BLOCK){
								cpu_abort(cpu_single_env, "kvssd_block: exceed block size and all block is valid %d\n", j);
							}
							s->kvssd_block[j] = 1;
							s->kvssd_key[i] = j;
							s->kvssd_keypos[i] = temp;
							goldfish_kvssd_meta_write(s);
							s->pbn = j;
							status = goldfish_kvssd_data_write(s);
						}
					}

					break;
				case CMD_ERASE:
					goldfish_kvssd_meta_read(s);
					temp = 1;
					i=0;
					for(i=0; i<4; i++) temp += s->key[i];
					i = 0;
					while(i<MAX_BLOCK){
						if(s->kvssd_keypos[i] == temp) break;
						i++;
					}
					s->kvssd_block[s->kvssd_key[i]] = 2;
					s->kvssd_keypos[i] = 0;
					goldfish_kvssd_meta_write(s);
					status = 0;
								
				

					break;
				case CMD_EXIST:
					goldfish_kvssd_meta_read(s);
					temp = 1;
					i =0;
					for(i=0; i<4; i++) temp += s->key[i];
					i = 0;
					while(i< MAX_BLOCK){
						if(s->kvssd_keypos[i] == temp) break;
						i++;
					}
					if(i==MAX_BLOCK) s->pbn = 0;
					else s->pbn = s->kvssd_key[i];
					status = 1;
				
					break;
				default:
					cpu_abort(cpu_single_env, "kvssd_cmd: unsupported command %d\n", s->cmd);
					return;
			}
			if ( status == 0 ) {
				s->status = KVSSD_READY;
				goldfish_device_set_irq(&s->dev, 0, 1);
			} 
			else if ( status == 1 ) {
				s->status = KVSSD_WAIT;
				goldfish_device_set_irq(&s->dev, 0, 1);
			}			
			break;
		case KVSSD_KEY_REG:
			s->key[s->key_pos] = value;
			s->key_pos = (s->key_pos+1) % 4;
			break;
		case KVSSD_VALUE_REG:
			s->kvssd_value[s->value_pos] = value;
			s->value_pos = (s->value_pos+1) % 1024;
			break;
		case KVSSD_STATUS_REG:
			if(s->key[s->key_pos]==value){
				s->wait = s->wait +1; 
				s->key_pos = (s->key_pos+1) %4;
			} 
			if(s->wait==4){
				s->wait = 0;
				s->status = KVSSD_READY;
			}
			break;
			
	};
}

static CPUReadMemoryFunc *goldfish_kvssd_readfn[] = {
	goldfish_kvssd_read,
	goldfish_kvssd_read,
	goldfish_kvssd_read
};

static CPUWriteMemoryFunc *goldfish_kvssd_writefn[] = {
	goldfish_kvssd_write,
	goldfish_kvssd_write,
	goldfish_kvssd_write
};

void goldfish_kvssd_init(void)
{
	struct goldfish_kvssd_state *s;

	s = (struct goldfish_kvssd_state *)g_malloc0(sizeof(*s));
	s->dev.name = "goldfish_kvssd";
	s->dev.base = 0;
	s->dev.size = 0x1000;
	s->dev.irq_count = 1;
	s->dev.irq = 15;
	s->kvssd_fd = open("/media/seungmin/Windows/emu-2.2-release/external/qemu/kvssd.data", O_RDWR | O_CREAT, 0777);
	s->kvssd_meta = open("/media/seungmin/Windows/emu-2.2-release/external/qemu/kvssd.meta", O_RDWR | O_CREAT, 0777);

	goldfish_device_add(&s->dev, goldfish_kvssd_readfn, goldfish_kvssd_writefn, s);


	register_savevm(NULL, 
			"goldfish_kvssd",
			0,
			KVSSD_STATE_SAVE_VERSION,
			goldfish_kvssd_save,
			goldfish_kvssd_load,
			s);
}

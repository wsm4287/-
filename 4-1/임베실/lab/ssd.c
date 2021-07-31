#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>

#define CMD_PUT			3
#define CMD_GET			4
#define CMD_ERASE		5
#define CMD_EXIST		6

struct ioctl_env {
	uint32_t key[4];
	uint32_t value[1024];
};

int main(int argc, char *argv[])
{
	int fd;
	int ret;
	struct ioctl_env env;
	
	fd = open("/dev/kvssd", O_RDWR | O_NDELAY);
	int i;

	for(i=0; i<3096; i=i+3){
		env.key[0] = i;
		env.key[1] = 0;
		env.key[2] = 0;
		env.key[3] = 0;

		for(int j=0; j<1024; j++) env.value[j] = i+j;
		ioctl(fd, CMD_PUT, &env);
	}
	
	for(int j=0; j<1024; j++) env.value[j]=0;

	for(i=0; i<3096; i=i+3){
		env.key[0] = i;
		env.key[1] = 0;
		env.key[2] = 0;
		env.key[3] = 0;

		ioctl(fd, CMD_GET, &env);
		printf("%d ", env.value[0]);
	}	
	printf("\n");	
	
	for(i=1; i<3096; i=i+3){
		env.key[0] = i;
		env.key[1] = 0;
		env.key[2] = 0;
		env.key[3] = 0;

		for(int j=0; j<1024; j++) env.value[j] = i+j;
		ioctl(fd, CMD_PUT, &env);
	}

	for(int j=0; j<1024; j++) env.value[j]=0;

	for(i=0; i<3096; i=i+3){
		env.key[0] = i;
		env.key[1] = 0;
		env.key[2] = 0;
		env.key[3] = 0;

		ioctl(fd, CMD_GET, &env);
		printf("%d ", env.value[0]);
	}	
	printf("\n");	

	for(i=0; i<3096; i=i+3){
		env.key[0] = i;
		env.key[1] = 0;
		env.key[2] = 0;
		env.key[3] = 0;

		ioctl(fd, CMD_EXIST, &env);
	}

	for(i=0; i<3096; i=i+3){
		env.key[0] = i;
		env.key[1] = 0;
		env.key[2] = 0;
		env.key[3] = 0;

		ioctl(fd, CMD_ERASE, &env);
	}

	for(i=0; i<3096; i=i+3){
		env.key[0] = i;
		env.key[1] = 0;
		env.key[2] = 0;
		env.key[3] = 0;

		for(int j=0; j<1024; j++) env.value[j] = i+j;
		ioctl(fd, CMD_PUT, &env);
	}
	
	for(i=0; i<3096; i=i+3){
		env.key[0] = i;
		env.key[1] = 0;
		env.key[2] = 0;
		env.key[3] = 0;

		ioctl(fd, CMD_GET, &env);
		printf("%d ", env.value[0]);
	}	
	printf("\n");	
	
	
	for(i=2; i<3096; i=i+3){
		env.key[0] = i;
		env.key[1] = 0;
		env.key[2] = 0;
		env.key[3] = 0;

		for(int j=0; j<1024; j++) env.value[j] = i+j;
		ioctl(fd, CMD_PUT, &env);
	}	
	


	for(i=1; i<3096; i=i+3){
		env.key[0] = i;
		env.key[1] = 0;
		env.key[2] = 0;
		env.key[3] = 0;

		for(int j=0; j<1024; j++) env.value[j] = i+j;
		ioctl(fd, CMD_PUT, &env);
	}


	for(i=0; i<3096; i++){
		env.key[0] = i;
		env.key[1] = 0;
		env.key[2] = 0;
		env.key[3] = 0;

		ioctl(fd, CMD_GET, &env);
		printf("%d ", env.value[0]);
	}	
	printf("\n");	
	
	return 0;
}	

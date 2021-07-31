#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>

#define	LED_ADDR 0xff012000
#define LED_SIZE 4096

#define LED0 0x000
#define LED1 0x004
#define LED2 0x008
#define LED3 0x00C
#define LED4 0x010
#define LED5 0x014
#define LED6 0x018

#define COL0	0x0
#define COL1	0x1 
#define COL2	0x2     
#define COL3	0x3 
#define COL4	0x4 
#define COL5	0x5 	
#define COL6	0x6 	

#define CMD1 0x04
#define CMD2 0x05
#define CMD3 0x06

unsigned char color[] = {COL0, COL1, COL2, COL3, COL4, COL5, COL6};

int main(int argc, char *argv[])
{
	int i, fd;
	unsigned *led_base_addr;
	unsigned *led0, *led1, *led2, *led3, *led4, *led5, *led6;

	fd = open("/dev/led", O_RDWR);

	/* 
	  Access device by ioctl
	  ex. ioctl(fd, cmd_num, parameter)
	*/
	if(argc==2){
		char x[100];
		while(argv[1][i+1]){
			x[i] = argv[1][i+4];
			i++;
		}
		x[i]='\0';
		if(x[1]=='N'){
			printf("%s\n",x);
			if(x[3]=='A'){
				for(int i=0; i<=6; i++) printf("%d ",i);
				printf("\n");
			}
			else{
				char y[2];
		        	y[0] = x[6];
				y[1] = '\0';
				char z[2]; 
				z[0] = x[8];
				z[1] = '\0';
				int yy = atoi(y);
				int zz = atoi(z);
				for(int i=yy; i<=zz; i++)
					printf("%d ", i);
				printf("\n");
			}
		}
		else if(x[1]=='F'){
			printf("%s\n",x);
			if(x[4]=='A'){
				for(int i=0; i<=6; i++) printf("%d ", i);
				printf("\n");
			}
			else{
				char y[2];
		        	y[0] = x[7];
				y[1] = '\0';
				char z[2]; 
				z[0] = x[9];
				z[1] = '\0';
				int yy = atoi(y);
				int zz = atoi(z);
				for(int i=yy; i<=zz; i++)
					printf("%d ",i);
				printf("\n");
			}
		
		}

	}

	//ioctl(fd, CMD3, 1);

	close(fd);
	return 0;
}	

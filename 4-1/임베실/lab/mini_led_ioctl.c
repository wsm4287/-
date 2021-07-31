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
#define CMD4 0x07
#define CMD5 0x08
#define CMD6 0x09
#define CMD7 0x0A



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
		int i=0;
		char x[30];
		while(argv[1][i+4]){
			x[i] = argv[1][i+4];
			i++;
		}
		x[i]='\0';
		if(x[1]=='N'){
			if(x[3]=='A'){
				for(int i=0; i<=6; i++) ioctl(fd, CMD1, i);
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
				for(int i=yy; i<=zz; i++) ioctl(fd, CMD1, i);
			}
		}
		else if(x[1]=='F'){
			if(x[4]=='A'){
				for(int i=0; i<=6; i++) ioctl(fd, CMD2, i);
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
				for(int i=yy; i<=zz; i++) ioctl(fd, CMD2, i);
			}
		
		}
		else if(x[1]=='x'){
			char y[2];
		        y[0] = x[3];
			y[1] = '\0';
			char z[2]; 
			z[0] = x[5];
			z[1] = '\0';
			int yy = atoi(y);
			int zz = atoi(z);

			if(x[11]=='g' && x[13]=='a')
				for(int i=yy; i<=zz; i++) ioctl(fd, CMD2, i);
			
			if(x[11]=='w')
				for(int i=yy; i<=zz; i++) ioctl(fd, CMD1, i);
			
			if(x[11]=='r')
				for(int i=yy; i<=zz; i++) ioctl(fd, CMD3, i);

			if(x[11]=='y')
				for(int i=yy; i<=zz; i++) ioctl(fd, CMD4, i);

			if(x[11]=='g' && x[13]=='e')
				for(int i=yy; i<=zz; i++) ioctl(fd, CMD5, i);

			if(x[11]=='s')
				for(int i=yy; i<=zz; i++) ioctl(fd, CMD6, i);

			if(x[11]=='p')
				for(int i=yy; i<=zz; i++) ioctl(fd, CMD7, i);

	
		}
		else{

			if(x[7]=='g' && x[9]=='a')
				for(int i=0; i<=6; i++) ioctl(fd, CMD2, i);
			
			if(x[7]=='w')
				for(int i=0; i<=6; i++) ioctl(fd, CMD1, i);
			
			if(x[7]=='r')
				for(int i=0; i<=6; i++) ioctl(fd, CMD3, i);

			if(x[7]=='y')
				for(int i=0; i<=6; i++) ioctl(fd, CMD4, i);

			if(x[7]=='g' && x[9]=='e')
				for(int i=0; i<=6; i++) ioctl(fd, CMD5, i);

			if(x[7]=='s')
				for(int i=0; i<=6; i++) ioctl(fd, CMD6, i);

			if(x[7]=='p')
				for(int i=0; i<=6; i++) ioctl(fd, CMD7, i);


		}

	}

	//ioctl(fd, CMD3, 1);

	close(fd);
	return 0;
}	

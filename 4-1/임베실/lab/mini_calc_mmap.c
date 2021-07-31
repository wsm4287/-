#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>

#define	SEGMENT_ADDR 0xff011000
#define SEGMENT_SIZE 4096

#define SEGMENT0 0x000
#define SEGMENT1 0x004
#define SEGMENT2 0x008
#define SEGMENT3 0x00C
#define SEGMENT4 0x010
#define SEGMENT5 0x014
#define SEGMENT6 0x018

#define NUM1	0x24   
#define NUM2	0x5d 
#define NUM3	0x6d     
#define NUM4	0x2e 
#define NUM5	0x6b 
#define NUM6	0x7a 	
#define NUM7	0x27 	
#define NUM8	0x7f	
#define NUM9	0x6f	 
#define NUM0	0x77


unsigned char number[] = {NUM0, NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9};

int main(int argc, char *argv[])
{
	int i, fd;
	unsigned *seg_base_addr;
	unsigned *seg0, *seg1, *seg2, *seg3, *seg4, *seg5, *seg6;

	fd = open("/dev/segment", O_RDWR);
	seg_base_addr = (unsigned *)mmap(NULL, SEGMENT_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, SEGMENT_ADDR);

	seg0 = (unsigned *)(seg_base_addr + 0);
	seg1 = (unsigned *)(seg_base_addr + 1);
	seg2 = (unsigned *)(seg_base_addr + 2);
	seg3 = (unsigned *)(seg_base_addr + 3);
	seg4 = (unsigned *)(seg_base_addr + 4);
	seg5 = (unsigned *)(seg_base_addr + 5);
	seg6 = (unsigned *)(seg_base_addr + 6);

	/* This program turn on all segments (0)*/

	if(argc==2){
		int x = atoi(argv[1]);
		if(x>9999999) x = 9999999;
		if(x<0) x = 0;
		int k=0;
		while(x){
			*(unsigned *)(seg_base_addr + 6 - k) = number[x%10];
			x = x/10;
			k++;
		}
		while(k<7){
			*(unsigned *)(seg_base_addr + 6 - k) = number[0];
			k++;
		}

	}
	else if(argc==4){
		int x = atoi(argv[1]);
		int y = atoi(argv[3]);
		
		if(argv[2][0]=='+')
		       x = x+y;	
		else if(argv[2][0] == '-')
			x = x-y;
		else if(argv[2][0] == 'x')
			x = x*y;
		else x = x/y;

		if(x>9999999) x = 9999999;
		if(x<0) x = 0;

		int k=0;
		while(x){
			*(unsigned *)(seg_base_addr + 6 - k) = number[x%10];
			x = x/10;
			k++;
		}
		while(k<7){
			*(unsigned *)(seg_base_addr + 6 - k) = number[0];
			k++;
		}

	}
	else if(argc==3){
		char aa[8];
		for(int i=0; i<7; i++){
			if(*(unsigned *)(seg_base_addr + i ) == number[0]) aa[i]='0';
			if(*(unsigned *)(seg_base_addr + i ) == number[1]) aa[i]='1';
			if(*(unsigned *)(seg_base_addr + i ) == number[2]) aa[i]='2';
			if(*(unsigned *)(seg_base_addr + i ) == number[3]) aa[i]='3';
			if(*(unsigned *)(seg_base_addr + i ) == number[4]) aa[i]='4';
			if(*(unsigned *)(seg_base_addr + i ) == number[5]) aa[i]='5';
			if(*(unsigned *)(seg_base_addr + i ) == number[6]) aa[i]='6';
			if(*(unsigned *)(seg_base_addr + i ) == number[7]) aa[i]='7';
			if(*(unsigned *)(seg_base_addr + i ) == number[8]) aa[i]='8';
			if(*(unsigned *)(seg_base_addr + i ) == number[9]) aa[i]='9';
		}
		aa[7]='\0';
		int x = atoi(aa);
		int y = atoi(argv[2]);
		
		if(argv[1][0]=='+')
		       x = x+y;	
		else if(argv[1][0] == '-')
			x = x-y;
		else if(argv[1][0] == 'x')
			x = x*y;
		else x = x/y;

		if(x>9999999) x = 9999999;
		if(x<0) x = 0;

		int k=0;
		while(x){
			*(unsigned *)(seg_base_addr + 6 - k) = number[x%10];
			x = x/10;
			k++;
		}
		while(k<7){
			*(unsigned *)(seg_base_addr + 6 - k) = number[0];
			k++;
		}

	}

/*	*seg0 = number[0];
	*seg1 = number[1];
	*seg2 = number[2];
	*seg3 = number[3];
	*seg4 = number[4];
	*seg5 = number[5];
	*seg6 = number[6];
*/
	munmap(seg_base_addr, 4096);
	close(fd);
	return 0;
}	

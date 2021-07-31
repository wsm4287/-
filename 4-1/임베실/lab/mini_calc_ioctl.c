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

#define SEGMENT_3	0x20

#define CMD1 0x04
#define CMD2 0x05
#define CMD3 0x06

unsigned char number[] = {NUM0, NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9};

int main(int argc, char *argv[])
{
	int i, fd;
	unsigned *seg_base_addr;
	unsigned *seg0, *seg1, *seg2, *seg3, *seg4, *seg5, *seg6;

	fd = open("/dev/segment", O_RDWR);

	/* 
	  Access device by ioctl
	  ex. ioctl(fd, cmd_num, parameter)
	*/

	ioctl(fd, CMD3, 3);

	close(fd);
	return 0;
}	

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(int argc, char *argv[])
{
	int fd;
	int ret;
	char *buf = (char *)malloc(sizeof(char) * 4096);
	char *buf2 = (char *)malloc(sizeof(char) * 4096);
	int i;

	fd = open("/dev/iodev", O_RDWR | O_NDELAY);

	/* 
	  Access device by read and write
	*/
	lseek(fd, 0, SEEK_SET);

	ret = read(fd, buf, 4096);
	printf("READ TEST : %s\n", buf);

	if(argc==2){
		strcpy(buf2, argv[1]);
	}

	i = 0;
	while(buf2[i]){
		buf[i]=buf2[i];
		i++;
	}
	buf[i]='\0';


	ret = write(fd, buf, 4096);

	printf("ret: %d\n", ret);

	close(fd);
	return 0;
}	

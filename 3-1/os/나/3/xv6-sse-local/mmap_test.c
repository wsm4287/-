#include "types.h"
#include "user.h"
#include "param.h"
#include "fcntl.h"

int main(int argc, char** argv) {
	

	printf(1, "mmap test \n");
	int i;
	int size = 4096;
	int fd = open("README", O_RDWR);
	char* text = mmap(fd, 2048,   size, MAP_PROT_READ|MAP_PROT_WRITE);			      //File example
	char* text2 = mmap(-1, 0,  size, MAP_PROT_READ|MAP_PROT_WRITE|MAP_POPULATE);  //ANONYMOUS example

	for (i = 0; i < size; i++) 
		printf(1, "%c", text[i]);
	printf(1,"\n============file mmap end==========\n\n\n\n");

	text2[0] = 's';
	text2[4095] = 'Y';

	for (i = 0; i < size; i++) 
		printf(1, "%c", text2[i]);
	printf(1,"\n============anonymous mmap end==========\n");

	munmap(text, size);
	munmap(text2, size);
	exit();
}

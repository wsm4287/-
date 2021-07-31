#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

const static unsigned char aes_key[] = {0x00,0x01,0x24,0x53,0x50,0xb5,0xeb,0x0a,0x15,0x48,0xfc,0x6d,0x27,0xd3,0xb4,0xd1};
//const static unsigned char aes_key[] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF};

void print_data(const char *title, const void* data, int len);

int main(){


	//unsigned char aes_input[]="CBMsz223gfHe6AH6I + IIEjpXxjFlupBrGYZ8CDYYr9WJj4j0cMuL8uAA / Yxr9pNK";

	unsigned char aes_input[]="Q0JNc3oyMjNnZkhlNkFINkkgKyBJSUVqcFh4akZsdXBCckdZWjhDRFlZcjlXSmo0ajBjTXVMOHVBQSAvIFl4cjlwTks=";
	//unsigned char aes_input[]="SKKU is the top university in the world";

//	unsigned char aes_input[]={0x0,0x1,0x2,0x3,0x4,0x5};
	
	unsigned char iv[AES_BLOCK_SIZE];
	memset(iv, 0x00, AES_BLOCK_SIZE);

	unsigned char enc_out[sizeof(aes_input) + AES_BLOCK_SIZE];
	unsigned char dec_out[sizeof(aes_input)];
	memset(enc_out, 0, sizeof(enc_out));
	memset(dec_out, 0, sizeof(dec_out));

	AES_KEY enc_key, dec_key;
	AES_set_encrypt_key(aes_key, sizeof(aes_key)*8, &enc_key);
	AES_cbc_encrypt(aes_input, enc_out, sizeof(aes_input), &enc_key, iv, AES_ENCRYPT);

	memset(iv, 0x00, AES_BLOCK_SIZE);
	AES_set_decrypt_key(aes_key, sizeof(aes_key)*8, &dec_key);
	AES_cbc_encrypt(enc_out, dec_out, sizeof(aes_input), &dec_key, iv, AES_DECRYPT);

	print_data("\n original ", aes_input, sizeof(aes_input));
	print_data("\n Encrypted ", enc_out, sizeof(enc_out));
	print_data("\n Decrypted ", dec_out, sizeof(dec_out));

	return 0;
}

void print_data(const char *title, const void* data, int len)
{
	printf("%s : ", title);
	const unsigned char *p = (const unsigned char*)data;
	int i=0;

	for(; i<len; i++) printf("%02X ", *p++);

	printf("\n");
}

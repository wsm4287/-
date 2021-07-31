#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/des.h>
#include <openssl/rand.h>
#include <openssl/aes.h> 

 
int main(void)
{
    unsigned char in[256], out[8][64], back[256];
 
    //DES_cblock key = {0x00, 0x00, 0x99, 0x65, 0x6c, 0x16, 0xf8, 0xe8};
    DES_cblock key;

    unsigned char pass[16] = "000099656c16f8e8";

    unsigned char ch2[3];
    int num1;
    for(int k=0; k<8; k++){
	ch2[0] = pass[k*2+0];
	ch2[1] = pass[k*2+1];
	ch2[2] ='\0';
	num1 = strtol(ch2, NULL, 16);
	key[k] = num1;
    }
    

    DES_key_schedule keysched;
 
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    memset(back, 0, sizeof(back));
    
    for(int i=0; i<8; i++) printf("[%02x] ", key[i]);
    printf("\n"); 

    DES_set_key(&key, &keysched);

    unsigned char origin[64] = "U0tLVSBpcyB0aGUgdG9wIHVuaXZlcnNpdHkgaW4gdGhlIHdvcmxk";
 

    for(int i=0; i<8; i++){
	
	for(int j=0; j<8; j++){
		if(!origin[i*8+j]) in[j]=0;
		in[j] = origin[i*8+j];
		
	}	
	printf("%s ", in);
	    
	DES_ecb_encrypt((DES_cblock*)in,(DES_cblock*)out[i], &keysched, DES_ENCRYPT);
 
  	int k=0;
	while (out[i][k]){
		printf("%02x ", out[i][k++]);
    		back[i*8+k] = out[i][k];
	}
	printf("\n");
    }

    unsigned char iv[AES_BLOCK_SIZE];
    memset(iv, 0x00, AES_BLOCK_SIZE);

    unsigned char enc_out[sizeof(back) + AES_BLOCK_SIZE];
    memset(enc_out, 0, sizeof(enc_out));


    const static unsigned char aes_key[] = {0x00,0x01,0x24,0x53,0x50,0xb5,0xeb,0x0a,0x15,0x48,0xfc,0x6d,0x27,0xd3,0xb4,0xd1};

    AES_KEY enc_key;

    AES_set_encrypt_key(aes_key, sizeof(aes_key)*8, &enc_key);
    AES_cbc_encrypt(back, enc_out, sizeof(back), &enc_key, iv, AES_ENCRYPT);

    printf("\n");
    printf("%s\n", enc_out);
    for(int i=0; i<sizeof(enc_out); i++){
	printf("%02x ", enc_out[i]);
    }



    
    return(0);
}

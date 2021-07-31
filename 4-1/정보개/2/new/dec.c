#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>



static int DecodeMimeBase64[256] = {
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* 00-0F */
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* 10-1F */
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,62,-1,-1,-1,63,  /* 20-2F */
    52,53,54,55,56,57,58,59,60,61,-1,-1,-1,-1,-1,-1,  /* 30-3F */
    -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,  /* 40-4F */
    15,16,17,18,19,20,21,22,23,24,25,-1,-1,-1,-1,-1,  /* 50-5F */
    -1,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,  /* 60-6F */
    41,42,43,44,45,46,47,48,49,50,51,-1,-1,-1,-1,-1,  /* 70-7F */
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* 80-8F */
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* 90-9F */
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* A0-AF */
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* B0-BF */
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* C0-CF */
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* D0-DF */
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* E0-EF */
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1   /* F0-FF */
    };
int base64_decode(char *text, unsigned char *dst, int numBytes )
{
  const char* cp;
  int space_idx = 0, phase;
  int d, prev_d = 0;
  unsigned char c;
    space_idx = 0;
    phase = 0;
    for ( cp = text; *cp != '\0'; ++cp ) {
        d = DecodeMimeBase64[(int) *cp];
        if ( d != -1 ) {
            switch ( phase ) {
                case 0:
                    ++phase;
                    break;
                case 1:
                    c = ( ( prev_d << 2 ) | ( ( d & 0x30 ) >> 4 ) );
                    if ( space_idx < numBytes )
                        dst[space_idx++] = c;
                    ++phase;
                    break;
                case 2:
                    c = ( ( ( prev_d & 0xf ) << 4 ) | ( ( d & 0x3c ) >> 2 ) );
                    if ( space_idx < numBytes )
                        dst[space_idx++] = c;
                    ++phase;
                    break;
                case 3:
                    c = ( ( ( prev_d & 0x03 ) << 6 ) | d );
                    if ( space_idx < numBytes )
                        dst[space_idx++] = c;
                    phase = 0;
                    break;
            }
            prev_d = d;
        }
    }
    return space_idx;
}



const static unsigned char aes_key[] = {0x00,0x01,0x24,0x53,0x50,0xb5,0xeb,0x0a,0x15,0x48,0xfc,0x6d,0x27,0xd3,0xb4,0xd1};

void print_data(const char *title, const void* data, int len);

int main(){

	unsigned char input[]="CBMsz223gfHe6AH6I+IIEjpXxjFlupBrGYZ8CDYYr9WJj4j0cMuL8uAA/Yxr9pNK";

	/*int i=0;
	while(input[i++]);
	for(; i<64; i++) input[i]= ' ';
*/
	unsigned char aes_input[64];
	memset(aes_input, 0, 64);

	base64_decode(input,aes_input,sizeof(input));

	int k=0;
	
	unsigned char iv[AES_BLOCK_SIZE];
	memset(iv, 0x00, AES_BLOCK_SIZE);

	unsigned char dec_out[sizeof(aes_input)];
	memset(dec_out, 0, sizeof(dec_out));

	AES_KEY dec_key;

	memset(iv, 0x00, AES_BLOCK_SIZE);
	AES_set_decrypt_key(aes_key, sizeof(aes_key)*8, &dec_key);
	AES_cbc_encrypt(aes_input, dec_out, sizeof(aes_input), &dec_key, iv, AES_DECRYPT);

	memset(iv, 0x00, AES_BLOCK_SIZE);
	AES_KEY enc_key;

	
	print_data("\n original ", aes_input, sizeof(aes_input));
	printf("\n%s", aes_input);
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

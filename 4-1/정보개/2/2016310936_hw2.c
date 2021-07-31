#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/des.h>
#include <openssl/aes.h>

char *plain;			//plaintext
char *cipher;		//ciphertext
char **pass;		//MD5 value
char **key;		//MD5 key


int base64[64] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','I', 'J', 'K', 'L', 'M', 'N', 'O', 'P','Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X','Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f','g', 'h', 'i', 'j', 'k', 'l', 'm', 'n','o', 'p', 'q', 'r', 's', 't', 'u', 'v','w', 'x', 'y', 'z', '0', '1', '2', '3','4', '5', '6', '7', '8', '9', '+', '/'};

void base64_encode(unsigned char *plain, unsigned char *encode, int plain_size){

	int i=0;
	int j=0;
	
	while(i < plain_size-2){								// 3개의 plain -> 4개의 encode
		encode[j++] = base64[plain[i] >> 2];
		encode[j++] = base64[((plain[i] << 4) & 0x30) | (plain[i+1] >> 4)];
		encode[j++] = base64[((plain[i+1] << 2) & 0x3c) | (plain[i+2] >> 6)];
		encode[j++] = base64[(plain[i+2] & 0x3f)];
		i+=3;
	}
	
	if(i == plain_size-2){											// 2개의 plain + padding -> 4개의 encode
		encode[j++] = base64[plain[i] >> 2];
		encode[j++] = base64[((plain[i] << 4) & 0x30) | (plain[i+1] >> 4)];
		encode[j++] = base64[((plain[i+1] << 2) & 0x3c)];
		encode[j++] = '='; 
	
	}
	
	else{																			// 1개의 plain + padding -> 4개의 encode
		encode[j++] = base64[plain[i] >> 2];
		encode[j++] = base64[((plain[i] << 4) & 0x30)];
		encode[j++] = '=';
		encode[j++] = '=';
	}

}


int main(){
	unsigned char ch;
	FILE *fpIn, *fpOut;
	FILE *fpPs;

	fpPs = fopen("passwords.txt", "r");
	fpIn = fopen("PlaintextCiphertext.txt", "r");
	fpOut = fopen("keys.txt", "wb");
	
	plain = (char*)malloc(sizeof(char)*64);	//plaintext의 64byte만 저장
	cipher = (char*)malloc(sizeof(char)*512);	//ciphertext의 512byte만 저장
	pass = (char**)malloc(sizeof(char*)*184389);	//passwords.txt에 총 184389개수의 value
	key = (char**)malloc(sizeof(char*)*184389);	//passwords.txt에 총 184389개수의 key
	int i = 0;
	
	for(i=0; i<184389; i++){				//value와 key 하나하나에 32byte크기 할당
		pass[i] = (char*)malloc(sizeof(char)*32);
		key[i] = (char*)malloc(sizeof(char)*32);
	}
	
	for(i=0; fscanf(fpIn, "%c", &ch) != EOF && i<64; ++i){  //plaintext의 64byte -> plain에 저장
		if(ch == '\n') break;
		plain[i]=ch;
	}
	if(i<64) plain[i]='\0';
	if(i==64){			//plaintext의 크기가 64byte보다 크면 ciphertext가 올 때까지 넘김
		for(i=0; fscanf(fpIn, "%c", &ch) != EOF; ++i){
			if(ch == '\n') break;
		}
	}

	
	int cnt = 0;
	for(i=0; fscanf(fpIn, "%c", &ch) != EOF && i<512; ++i){  //ciphertext의 512byte -> cipher에 저장
		cipher[cnt]=ch;
		cnt++;
	}
	cipher[cnt]='\0';
	fclose(fpIn);

	
	int j=0;
	for(i=0; i<184389; i++){		//passwords.txt의 value와 key를 각각 pass와 key에 저장
		int cnt = 0;
		for(; fscanf(fpPs, "%c", &ch) != EOF; ++j){
			if(ch == ' ') break;
			pass[i][cnt++] = ch;
		}
		cnt = 0;
		for(; fscanf(fpPs, "%c", &ch) != EOF; ++j){
			if(ch == '\n') break;
			key[i][cnt++] = ch;
		}

	}
	fclose(fpPs);
	
	unsigned char des_in[8][8];		//des_ebc 암호화의 input 생성 64byte를 8 * 8byte로 쪼갬
	
	for(int i=0; i<8; i++) memset(des_in[i],0,8);

	
	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
			if(plain[i*8+j]) des_in[i][j] = plain[i*8+j];
			else des_in[i][j]=0;
		}
	}
	
	

	for(int i=0; i<184389; i++){		//밖의 for문은 aes_cbc 암호화 반복문
		unsigned char aes_key[16];
		char ch3[3];
		int num2;
		for(int k=0; k<16; k++){		//aes 암호화의 key값 저장 -> aes_key 
				ch3[0] = pass[i][k*2+0];
				ch3[1] = pass[i][k*2+1];
				ch3[2] = '\0';
				num2 = strtol(ch3, NULL, 16);
				aes_key[k] = num2;
		}
			
		for(int j=0; j<184389; j++){	//안의 for문은 des_ebc 암호화 반복문
			char ch2[3];
			int num1;
			DES_cblock key1;
			for(int k=0; k<8; k++){	//des 암호화의 key값 저장 -> key1
				ch2[0] = pass[j][k*2+0];
				ch2[1] = pass[j][k*2+1];
				ch2[2] = '\0';
				num1 = strtol(ch2, NULL, 16);
				key1[k] = num1;
			}
			
			unsigned char des_out[8][8];	//des 암호화 output 생성
			for(int i=0; i<8; i++) memset(des_out[i],0,8);
			
			DES_key_schedule keysched;

			DES_set_key(&key1, &keysched);
			for(int k=0; k<8; k++) {	//des 암호화과정 8byte나눈 것을 8번 반복 des_in -> des_out
				DES_ecb_encrypt((DES_cblock*)des_in[k],(DES_cblock*)des_out[k], &keysched, DES_ENCRYPT);
			}

			unsigned char aes_input[64];	//aes 암호화 input 생성
			memset(aes_input,0,64);
			for(int k=0; k<8; k++){
				for(int l=0; l<8; l++){	//des의 output을 aes input으로 옮김
					aes_input[k*8+l] = des_out[k][l];

				}
			}


			unsigned char iv[AES_BLOCK_SIZE];	//initalization vector 생성 NULL으로 사용
			memset(iv, 0x00, AES_BLOCK_SIZE);
			
			unsigned char enc_out[sizeof(aes_input)];	//aes 암호화 output 생성
			memset(enc_out, 0, sizeof(enc_out));
			AES_KEY key2;
			AES_set_encrypt_key(aes_key, sizeof(aes_key)*8, &key2); // aes_key -> key2로 변환

			// aes_cbc 암호화 aes_input -> enc_out
			AES_cbc_encrypt(aes_input, enc_out, sizeof(aes_input), &key2, iv, AES_ENCRYPT);
			int k=0;
			
			int encode_size = 4 * ((sizeof(enc_out)+ 2) / 3);	//base64 변환 공간 할당
			
			unsigned char base_out[encode_size];
			
			base64_encode(enc_out, base_out, sizeof(enc_out));	//base64 변환 enc_out -> base_out
			
			k = 0;
			int diff=40;			//암호화 후 비교크기를 최대 40으로 설정
			
			while(base_out[k++]);		
			if(diff > k) diff = k;	//만약 base_out이나 cipher 중에 size가 40보다 작은 것이 있으면 변경
			k = 0;
			
			while(cipher[k++]);
			if(diff > k) diff = k;
			k = 0;
			
			while(base_out[k] && base_out[k] == cipher[k]){  //diff길이만큼 base_out과 cipher를 비교
				if(k > diff){		//만약 diff까지 왔으면 암호화가 제대로 이루어짐 -> key값 찾음
					char x[40];
					int l=0;
					while(key[j][l]){		//x에 key1, key2 차례로 옮긴 후 fpOut에 출력
						x[l] = key[j][l];
						l++;
					}
					x[l]='\0';
					fwrite(x,l, 1, fpOut);
					ch = '\n';
					fwrite(&ch, sizeof(ch), 1, fpOut);
					l=0;
					while(key[i][l]){
						x[l] = key[i][l];
						l++;
					}
					x[l]='\0';
					fwrite(x,l, 1, fpOut);	
					fclose(fpOut);
					
					for(int l=0; l<184389; l++){	// malloc으로 할당해준 공간 free
						free(pass[l]);
						free(key[l]);
					}
					free(pass);
					free(key);
					free(plain);
					free(cipher);

					return 0;		// 빠른 실행 종료를 위해 바로 return
				}
			k++;
			}
		}

	}
	


	fclose(fpOut);			//만약 key를 찾지 못했어도 할당한 공간 free 후 종료
	for(i=0; i<184389; i++){
		free(pass[i]);
		free(key[i]);
	}
	free(pass);
	free(key);
	free(plain);
	free(cipher);

	return 0;
}

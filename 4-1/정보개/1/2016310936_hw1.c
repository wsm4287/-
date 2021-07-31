#include <stdio.h>

char origin[5005]; // input file original
char temp[5005];
int alp[26]; // alphabet 사용 횟수
float al[26]; // alphabet 빈도수
int text1;		// input text 크기
int text2;

float pp[10]; // 혹시 빈도수가 0.065 정도로 안나왔을 때 대비하여

unsigned char key[10];

int find_length(){
	for(int i=1; i<=10; i++){
		int cnt = 1; // 읽는 글 위치를 넘겨줌
		int sum = 0; // alphabet 총 횟수
		
		while(cnt < text2){           // 각 alphabet 횟수를 세고 총 alphabet 수도 샌다.
			if('a' <= origin[cnt] && origin[cnt] <= 'z'){
				alp[origin[cnt]-97]++;
				sum++;
			}
			if('A' <= origin[cnt] && origin[cnt] <= 'Z'){
				alp[origin[cnt]-65]++;
				sum++;
			}
			cnt = cnt + i; // length 단위
		}

		float s = 0;
		for(int j=0; j<26; j++){      // alphabet의 빈도수를 체크
			al[j] = (float) alp[j] / (float) sum;
			al[j] = al[j] * al[j];
			s = s + al[j];
			al[j]=0;
			alp[j]=0;
		}
		
		if(sum > 300 && s < 0.07 && s > 0.06) return i;  //빈도수 합이 0.065에 가까우면 length이므로 return
		sum = 0;

		pp[i-1] = s;
	}

	float y = 0.038;
	int ans;
	for(int i=0; i<10; i++){
		if(pp[i] > y){
			y = pp[i];
			ans = i+1;
		}
	}
	return ans;   //만약 빈도수가 0.065에 가까운 경우가 없으면 가장 큰 경우를 length로 판단
}

int find_value(int length, int position){            // key 개수를 알았다면, 위치마다의 value값 찾기
	float val[256]={0,};                    // 0x00 ~ 0xff 변환 후 빈도수 저장
	float e[256]={0,};                      // 0x00 ~ 0xff 변환 후 e 사용 횟수 저장

	for(int i=0; i<256; i++){
		int cnt = position;
		int sum = 0;
		int ccnt = 0;
	
		while(cnt < text2){              // 0x00 ~ 0xff 중 for문을 반복하며 변환 값을 temp에 저장
			temp[ccnt] = origin[cnt] ^ i;
			ccnt++;
			cnt = cnt + length;
		}
		temp[ccnt]='\0';

		for(int j=0; j<ccnt; j++){               // 변환 후 alphabet 횟수 저장
			if('a' <= temp[j] && temp[j] <= 'z'){
				alp[temp[j]-97]++;
				sum++;
			}
		}
		float s = 0;
		e[i] = (float) alp[4] / (float) sum;       // (e 사용 횟수)/(alphabet 총 횟수) 저장
		if(e[i] > 0.5) e[i]=0;                    // 빈도수가 지나칠 정도로 많으면 잘못된 것으로 판단하여 0으로 저장
		for(int j=0; j<26; j++){      
			al[j] = (float) alp[j] / (float) sum;
			al[j] = al[j] * al[j];
			s = s + al[j];
			al[j]=0;
			alp[j]=0;
		}
		sum = 0;
		val[i] = s;                         // 변환 후 빈도수 저장
		if(val[i] > 0.09) e[i]=0;           // 빈도수가 과도할 정도로 높으면 잘못된 것으로 판단

		cnt = 0;
		while(cnt < ccnt){        // 변환 전으로 다시 변환
			temp[cnt] ^= i;
			cnt++;
		}
	}
	int ans=0;
	float max=0.05;
	for(int i=0; i<256; i++){ // 변환 된 후 중 'e'의 사용 횟수가 가장 높은 값 중 빈도수가 적지 않은 값을 value로 판단
		
		if(e[i] > max && val[i] < 0.08){
			if(val[i] < 0.05) continue;
			max = e[i];
			ans = i;
		}
	}
	return ans;
}

void find_key(int k){
	for(int i=0; i<k; i++){       
		key[i] = find_value(k,i);
	}
}



int main(){
	unsigned char ch;
	FILE *fpIn, *fpOut;

	fpIn = fopen("hw1_input.txt", "r");
	fpOut = fopen("hw1_output.txt", "wb");
	int i=0;
	for(i=0; fscanf(fpIn, "%c", &ch) != EOF; ++i){
		origin[i]=ch;
	}
	text1 = i;
	origin[i]= '\0';
	text2 = i;
	fclose(fpIn);
	
	int key_length = find_length();

	find_key(key_length);

	char value[5];

	for(i=0; i< key_length; i++){                //output 파일 첫 줄에 value값 출력
		sprintf(value, "0x%02x", key[i]);
		value[4]=' ';
		fwrite(&value,sizeof(value), 1, fpOut);
	}
	ch = '\n';
	fwrite(&ch, sizeof(ch), 1, fpOut);

	for(i=0; i<text1; i++){           // output 파일 두번 째 줄부터 변환된 값 출력
		ch = key[i % key_length] ^ origin[i];
		fwrite(&ch, sizeof(ch), 1, fpOut);
	}
	fclose(fpOut);

	return 0;
}

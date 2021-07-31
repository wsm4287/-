#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define CNT 6
#define MAX_NUM 45
#define MAX_TRY 10000

#define SWAP(x,y) {int temp=x; x=y; y=temp;}

void make_randoms(int *base, int n);
void sort(int *base, int n);
void print_generate_num(int *base, int *scores);
void print_recommend_num(int *base, int *scores);

void check_answer(int *scores){
	int i, j, max;

	for(i=0;i<CNT;i++){
		max=0;
		for(j=0;j<MAX_NUM;j++){
			if(scores[max]<scores[j]){
				max=j;
			}
		}
		printf("숫자 %d: %d번 발생\n",max+1,scores[max]);
		scores[max]=0;
	}
}


void main(){
	int i;
	int base[CNT]={0};//로또 번호 저장 변수
	int scores[MAX_NUM]={0};//특정값에 대한 발생 빈도 저장 변수
	int check[MAX_NUM]={0};

	srand((unsigned int)time(0));//프로그램 동작할때마다 다르게 랜덤 발생
	print_generate_num(base,scores);//로또 번호 출력 및 발생 빈도 측정
	for(i=0;i<MAX_NUM;i++){
		check[i]=scores[i];
	}
	print_recommend_num(base,scores);//발생 번호 중 추천 번호 출력
	check_answer(check);

}

// 번호를 랜덤하게 생성하는 함수 (중복 숫자 체크 포함)
// 번호 n개를 한번에 생성
// Hint: "rand()%45" 사용
void make_randoms(int *base, int n){
    int i;
    int j;
    int a[n];
    for(i=0; i<n; i++){
        a[i] =1+rand()%45;
        for(j=0; j<i; j++){
            if(a[i] == a[j]){
                while(a[i] == a[j])                       /*번호를 받을때 이전번호들중 같은게 있으면 계속 새로받게 하였습니다.*/
                     a[i] = 1+rand()%45;
            }
        }
    }

    for(i=0; i<n; i++){
        base[i] =a[i];
    }


}

// n개의 수를 정렬하는 함수 (오름차순)
void sort(int *base, int n){
    int i,j;
    int k;
    for(i=0; i<n; i++){
        for(j=0; j<n-i-1; j++){
            if(base[j] > base[j+1]){
                k = base[j];
                base[j] = base[j+1];
                base[j+1] = k;
            }
        }
    }

}

// 로또 번호 발생 후 출력 및 발생 빈도 측정 함수
// Hint: 함수내에서 make_randoms 함수 사용
void print_generate_num(int *base, int *scores){
    int i;
    int j;
    for(i=0; i<10000; i++){
        printf("%dth try ", i+1);
        make_randoms(base, 6);
        sort(base,6);
        for(j=0; j<6; j++){
            printf("%d ",base[j]);
            scores[base[j]]++;
        }
        printf("\n");
    }

}

// 발생 빈도가 가장 많은 번호 6개를 추천해주는 함수
// 단, 발생 빈도가 같은 경우 낮은 크기의 번호를 추천
// Hint: check_answer 함수 참고
void print_recommend_num(int *base, int *scores){
    int i,j;
    int max;
    int x[45];
    for(i=0; i<45; i++)
        x[i] = scores[i];
    printf("추천 번호 ");
    for(i=0;i<6;i++){
		max=0;
		for(j=0;j<45;j++){
			if(x[max]<x[j]){
				max=j;
			}
		}
		printf("%d ",max+1);
		x[max]=0;
	}
	printf("\n");


}

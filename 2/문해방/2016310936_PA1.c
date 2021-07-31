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
		printf("���� %d: %d�� �߻�\n",max+1,scores[max]);
		scores[max]=0;
	}
}


void main(){
	int i;
	int base[CNT]={0};//�ζ� ��ȣ ���� ����
	int scores[MAX_NUM]={0};//Ư������ ���� �߻� �� ���� ����
	int check[MAX_NUM]={0};

	srand((unsigned int)time(0));//���α׷� �����Ҷ����� �ٸ��� ���� �߻�
	print_generate_num(base,scores);//�ζ� ��ȣ ��� �� �߻� �� ����
	for(i=0;i<MAX_NUM;i++){
		check[i]=scores[i];
	}
	print_recommend_num(base,scores);//�߻� ��ȣ �� ��õ ��ȣ ���
	check_answer(check);

}

// ��ȣ�� �����ϰ� �����ϴ� �Լ� (�ߺ� ���� üũ ����)
// ��ȣ n���� �ѹ��� ����
// Hint: "rand()%45" ���
void make_randoms(int *base, int n){
    int i;
    int j;
    int a[n];
    for(i=0; i<n; i++){
        a[i] =1+rand()%45;
        for(j=0; j<i; j++){
            if(a[i] == a[j]){
                while(a[i] == a[j])                       /*��ȣ�� ������ ������ȣ���� ������ ������ ��� ���ιް� �Ͽ����ϴ�.*/
                     a[i] = 1+rand()%45;
            }
        }
    }

    for(i=0; i<n; i++){
        base[i] =a[i];
    }


}

// n���� ���� �����ϴ� �Լ� (��������)
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

// �ζ� ��ȣ �߻� �� ��� �� �߻� �� ���� �Լ�
// Hint: �Լ������� make_randoms �Լ� ���
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

// �߻� �󵵰� ���� ���� ��ȣ 6���� ��õ���ִ� �Լ�
// ��, �߻� �󵵰� ���� ��� ���� ũ���� ��ȣ�� ��õ
// Hint: check_answer �Լ� ����
void print_recommend_num(int *base, int *scores){
    int i,j;
    int max;
    int x[45];
    for(i=0; i<45; i++)
        x[i] = scores[i];
    printf("��õ ��ȣ ");
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

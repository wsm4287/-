#include <stdio.h>

int a[3] = { 2, 5, 7 };   //구슬
int b[3];          // 구슬을 담을 상자
int N = 3;      // 구슬 3개

void print(){
	for(int i=0; i<N; i++) printf("%d ", b[i]);
	printf("\n");

}


void DFS(int n)    //n는 구슬(a배열의 index)
{
	if(n == N){
		print();
		return;
	}
	b[n] = a[n];
	DFS(n+1);
	b[n] = 0;
	DFS(n+1);

     //1] 리턴조건 : N번째이면 인쇄후 리턴
     //2] 현재구슬을 고르기(b배열에 담기)
     //3] 현재 구슬을 고르지 않기(b배열에 담지 않기)
}

int main(void)
{
     DFS(0);   //a[0]번 구슬부터 조합
}

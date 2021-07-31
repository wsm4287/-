#include <stdio.h>

int N, M;
int a[10];
int check[10];

void print() {
	for (int i = 1; i <= N; i++) printf("%d ", a[i]);
	printf("\n");
}

void DFS1(int n) {
	if (n > N) {
		print();
		return;
	}
	for (int i = 1; i <= 6; i++) {
		a[n] = i;
		DFS1(n + 1);
	}


}

void DFS2(int n, int start) {
	if(n > N){
		print();
		return;
	}
	for(int i=start; i<=6; i++){
		a[n] = i;
		DFS2(n+1,i);
	}
}

void DFS3(int n) {
	if(n > N){
		print();
		return;
	}
	for(int i=1; i<=6; i++){
		if(check[i] == 1) continue;
		check[i] = 1;
		a[n] = i;
		DFS3(n+1);
		check[i] = 0;
	}

}

void DFS4(int n, int start){
	if(n > N){
		print();
		return;
	}
	for(int i=start; i<=6; i++){
		a[n] = i;
		DFS4(n+1, i+1);
	}
	
}

int main() {

	scanf("%d %d", &N, &M);
	if (M == 1) DFS1(1);
	else if(M == 2) DFS2(1,1);
	else if(M == 3) DFS3(1);
	else DFS4(1,1);
	return 0;
}

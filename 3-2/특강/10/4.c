#include <stdio.h>

int a[6][3];
int result[6][3];
int check;
int x1[] = {0,0,0,0,0,1,1,1,1,2,2,2,3,3,4};
int x2[] = {1,2,3,4,5,2,3,4,5,3,4,5,4,5,5};

int minus(int x1, int x2){
	if(x1 >= x2) return x1- x2;
	else x2 - x1;
}

void dfs(int n){
	if(n >= 15){
 		for(int i=0; i<6; i++){
			for(int j=0; j<3; j++){
				if(a[i][j] != result[i][j]) return;
			}
		}
	check = 1;
	return;
	}
	int y1 = x1[n];
	int y2 = x2[n];

	for(int i=0; i<3; i++){
		result[y1][i]++;
		result[y2][2-i]++;
		dfs(n+1);
		result[y1][i]--;
		result[y2][2-i]--;		

	}	

}	



int main(){

	for(int i=0; i<4; i++){
		for(int j=0; j<6; j++) scanf("%d %d %d", &a[j][0], &a[j][1], &a[j][2]);
		check = 0;
		dfs(0);
		if(check == 1) printf("1 ");
		else printf("0 ");
	}

	return 0;
}

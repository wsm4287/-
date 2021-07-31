#include <iostream>


using namespace std;

int N,M,D;
int map[20][20];
int ans;
int temp[20][20];

int dis(int x1, int x2, int y1, int y2){
	int x,y;
	if(x1>x2) x = x1-x2;
	else x = x2-x1;
	if(y1>y2) y = y1-y2;
	else y = y2-y1;
	return x+y;
}

int attack(int x1, int x2, int x3){
	int check[20][20]={0,};
	int a[3]={x1,x2,x3};
	int sh[3][3]={{D,99,99},{D,99,99},{D,99,99}};
	for(int k=0; k<3; k++){
		for(int i=N-1; i>=0; i--){
			for(int j=0; j<M; j++){
				if(temp[i][j]){
					if(dis(a[k],j,N,i)<=D){
						if(sh[k][0] > dis(a[k],j,N,i)){
							sh[k][0] = dis(a[k],j,N,i);
							sh[k][1] = i;
							sh[k][2] = j;
						}
						else if(sh[k][0] == dis(a[k],j,N,i) && j < sh[k][2]){
							sh[k][1] = i;
							sh[k][2] = j;
						}
						
					}
				}
			}
		}
		
		if(sh[k][1] < N && sh[k][2] < M) check[sh[k][1]][sh[k][2]] = 1;
	}
	int t=0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(check[i][j]){
				t++;
				temp[i][j] = 0;
			}
		}
	}
	return t;

}

void move(){
	for(int i=N-1; i>=0; i--){
		for(int j=0; j<M; j++) temp[i][j] = temp[i-1][j];
	}
	for(int j=0; j<M; j++) temp[0][j] = 0;
}


void find(int x1, int x2, int x3){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++) temp[i][j]= map[i][j];
	}

	int sum=0;
	for(int i=0; i<N; i++){
		sum += attack(x1,x2,x3);
		move();
	}
	if(sum > ans) ans = sum;
}


int main(){
	cin >> N >> M >> D;

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++) cin >> map[i][j];
	}
	for(int i=0; i<M; i++){
		for(int j=i+1; j<M; j++){
			for(int k=j+1; k<M; k++){
				find(i,j,k);
			}
		}
	}
	cout << ans;
}

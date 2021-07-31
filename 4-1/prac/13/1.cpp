#include <iostream>

using namespace std;

int T, K;
int ans;
int a[4][8];
int ro[2][20];
int check[4];

void rotate(int x, int d){
	if(check[x]) return;
	if(check[0]+check[1]+check[2]+check[3]==4) return;
	int check1 = 0;
	int check2 = 0;
	if(x < 3){
		if(a[x][2] != a[x+1][6])
			check1 = 1;
	}
	if(x > 0){
		if(a[x][6] != a[x-1][2]) check2 = 1;
	}
	//cout << x << " : " << check1 << " " << check2 << endl;
	
	check[x] = 1;
	if(d == 1){
		int temp = a[x][7];
		for(int i=7; i>0; i--){
			a[x][i] = a[x][i-1];
		}
		a[x][0] = temp;
		if(check1) rotate(x+1,-1);
		if(check2) rotate(x-1,-1);
	}
  
	else{
		int temp = a[x][0];
		for(int i=0; i<7; i++){
				a[x][i] = a[x][i+1];				
		}
		a[x][7] = temp;
		if(check1) rotate(x+1,1);
		if(check2) rotate(x-1,1);
		}

  check[x] = 0;

}


void find(int k){
	while(k<K){
		rotate(ro[0][k]-1, ro[1][k]);
	/*	for(int i=0; i<4; i++){
			for(int j=0; j<8; j++) cout << a[i][j] << " ";
			cout << endl;
		}
		cout << endl << endl;*/
		k++;
	}
}

int main(){
	cin >> T;
	for(int t=1; t<=T; t++){
		cin >> K;
		for(int i=0; i<4; i++){
			for(int j=0; j<8; j++){
				cin >> a[i][j];
			}
		}
		for(int i=0; i<K; i++) cin >> ro[0][i] >> ro[1][i];

		find(0);
		if(a[0][0]) ans++;
		if(a[1][0]) ans = ans+2;
		if(a[2][0]) ans = ans+4;
		if(a[3][0]) ans = ans+8;
		cout << "#" << t << " " << ans << endl;
		ans = 0;
	}
	return 0;
}

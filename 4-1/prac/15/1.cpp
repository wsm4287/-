#include <iostream>

using namespace std;

int T, N, O, M, W;

int a[10];
int b[5];
int ans = 999999;


void find(int k, int x, int o,int y, int check){
	if(k > M) return;
	if(x > W) return;
	if(x < 0) return;
	if(y > 999) return;
	if(k > ans) return;
	if(x == W){
		if(k!=0){
			if(ans > k) ans = k;
			return;
		}
	}
	if(check==0){
		int xx = x*10;
		for(int i=0; i<N; i++)
			find(k+1,xx+a[i],0,0,0);
	}
	if(x && o){
		if(y){
			int yy = y * 10;
			for(int i=0; i<N; i++){
				find(k+1,x,o,yy+a[i],1);
			}
			if(o==1) find(k,x+y,0,0,1);
			if(o==2) find(k,x-y,0,0,1);
			if(o==3){
				cout << k << " " << x << " " << y << endl;
				find(k,x*y,0,0,1);
			}
			if(o==4) find(k,x/y,0,0,1);
		}
		else{
			for(int i=0; i<N; i++){
				if(a[i]==0) continue;
				find(k+1,x,o,a[i],1);
			}
		}
	}
	else if(x && !o){
		for(int i=0; i<5; i++){
			if(b[i]) find(k+1,x,i,0,1);
		}
	}

}

int main(){
	cin >> T;
	for(int t=1; t<=T; t++){
		cin >> N >> O >> M;
		for(int i=0; i<N; i++)
			cin >> a[i];
		int x;
		for(int i=0; i<O; i++){
			cin >> x;
			b[x] = 1;
		}
		cin >> W;

		find(0,0,0,0,0);
		if(ans == 999999) ans = -1;
		cout << "#" << t << " " << ans << endl;
		ans = 999999;
		for(int i=0; i<5; i++) b[i]=0;
	}
	return 0;
}

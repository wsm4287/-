#include <iostream>
#include <queue>

using namespace std;

int N;
int a[20];
char o[10];
int ans=-999999999;
int s;

int cal(int x, int y, char z){
	if(z=='+') return x + y;
	else if(z=='-') return x - y;
	else if(z=='*') return x*y;
}

void find(int k, int x){
	if(k>=N/2){
		if(x > ans) ans = x;
		return;
	}
	find(k+1,cal(x,a[k+1],o[k]));

	if(k+1<N/2){
		int r = cal(a[k+1],a[k+2],o[k+1]);
		r = cal(x,r,o[k]);
		find(k+2,r);
	}

}

int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		if(i%2==0) cin >> a[i/2];
		else cin >> o[i/2];
	}
	find(0,a[0]);
	cout << ans;
	return 0;
}

#include <iostream>

using namespace std;

int n;
int ans;

int t[15];
int p[15];

void find(int k, int sum){
	if(k>=n){
		if(sum > ans){
			ans = sum;
		}
		return;
	}
	if(k+t[k]<=n) find(k+t[k], sum+p[k]);
	find(k+1, sum);
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> t[i] >> p[i];

	find(0,0);
	cout << ans;
	return 0;
}

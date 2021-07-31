#include <iostream>

using namespace std;

int N;

int ans=0;

void find(int x){
	int a = x;
	while(a){
		if(a % 10 == 9){
			ans = 1;
			return;
		}
		a = a /10;
	}
	
}

int main(){
	cin >> N;
	for(int i=1; i<=N; i++){
		int x;
		cin >> x;
		find(x);
		if(ans == 1) cout << "#" << i << " Yes" << endl;
		else cout << "#" << i << " No" << endl;
		ans = 0;
	}

	return 0;
}

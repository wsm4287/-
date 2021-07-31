#include <iostream>
#include <queue>

using namespace std;

int T,N;
int ans;

priority_queue<int> x;

void find(){
	int a = 0;
	while(!x.empty()){
		if(a == x.top()){
			ans--;
			a = -5;
		}
		else {
			ans++;
			a = x.top();
		}
		x.pop();
	}
}

int main(){
	cin >> T;
	for(int t=1; t<=T; t++){
		cin >> N;
		int a;
		for(int i=0; i<N; i++){
			cin >> a;
			x.push(a);
		}
		find();
		cout << "#" << t << " " << ans << endl;
		ans = 0;
	}
	return 0;
}

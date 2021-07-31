#include <iostream>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

int T,N,k;
string z;

int ans;


void change(string answer,int a){
	for(int i=0; i<a; i++){
		if(answer[i] >= 48 && answer[i] <= 57) ans += (answer[i]-48)*pow(16,a-1-i);
		else ans += (answer[i]-55)*pow(16,a-i-1);
	}
}

string rotate(string x, int N){
	char y = x[N-1];
	for(int i=N-1; i>0; i--)
		x[i] = x[i-1];
	x[0] = y;
	return x;
}

void find(string x, int N, int k){
	priority_queue<string> aa;
	int a = N/4;
	for(int i=0; i<a; i++){
		int t=0;
		for(t=0; t<N; t=t+a){
			aa.push(x.substr(t, a));
		}
		x = rotate(x,N);
	}

	string same;
	for(int i=0; i<k-1; i++){
		if(same != aa.top()){
			same = aa.top();
			aa.pop();
			}
		else{
			aa.pop();
			i--;
		}
	}
	change(aa.top(),a);

}

int main(){
	cin >> T;
	int i=0;
	for(i=0; i<T; i++){
		cin >> N >> k;
		cin >> z;
		find(z,N,k);
		cout << ans << endl;
		ans = 0;
	}

	return 0;
}

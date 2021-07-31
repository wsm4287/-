#include <iostream>

using namespace std;

int T, N;

//int a=99999999;
//int b=0;
int ans;

int main(){
	cin >> T;
	for(int t=1; t<=T; t++){
		cin >> N;
		int x, y;
		for(int i=0; i<N; i++){
			cin >> x >> y;
			ans = ans + y - x + 1;
			//if(a > x) a = x;
			//if(y > b) b = y;
		}
//		ans = b-a+1;
		cout << "#" << t << " " << ans << endl;
		ans = 0;
//		a = 99999999;
//		b = 0;
	}

	return 0;
}

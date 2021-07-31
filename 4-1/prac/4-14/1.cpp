#include <iostream>
#include <vector>

using namespace std;

int N;
int ans=-99999999;

vector <int> a;
vector <char> b;

void find(int x, int k){
	if(k >= N/2){
		if(x > ans) ans = x;
		return;
	}

	if(b[k] == '+'){
		find(x+a[k+1], k+1);
		if(k<N/2-1){
			if(b[k+1] == '+'){
				find(x+a[k+1]+a[k+2], k+2);
			}
			else if(b[k+1] == '*'){
				find(x+(a[k+1]*a[k+2]), k+2);
			}
			else{
				find(x+a[k+1]-a[k+2], k+2);
			}
		}
	}
	else if(b[k] == '*'){
		find(x * a[k+1], k+1);
		if(k<N/2-1){
			if(b[k+1] == '+'){
				find(x*(a[k+1]+a[k+2]), k+2);
			}
			else if(b[k+1] == '*'){
				find(x*(a[k+1]*a[k+2]), k+2);
			}
			else{
				find(x*(a[k+1]-a[k+2]), k+2);
			}
	
		}
	}	
	else{
		find(x - a[k+1], k+1);
		if(k<N/2-1){
			if(b[k+1] == '+'){
				find(x-(a[k+1]+a[k+2]), k+2);
			}
			else if(b[k+1] == '*'){
				find(x-(a[k+1]*a[k+2]), k+2);
			}
			else{
				find(x-(a[k+1]-a[k+2]), k+2);
			}
	
		}
	
	}

}

int main(){
	cin >> N;
	char x;
	char num[2];
	num[1] ='\0';
	for(int i=0; i<N; i++){
		cin >> x;
		if(i%2==0){
			num[0] = x;
			a.push_back(atoi(num));
		}
		else
			b.push_back(x);
	}
	find(a[0],0);
	cout << ans << endl;
	return 0;
}


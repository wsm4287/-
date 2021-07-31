#include <iostream>

using namespace std;

int n;
int b,c;
int a[1000000];
long long ans[1000000];

void find(int k){
	if(a[k] < b){
		ans[k] = 1;
		return;
	}
	int x = a[k] - b;
	if(x % c == 0) ans[k] = 1+x/c;
	else ans[k] = 2+x/c;
}


int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	cin >> b >> c;
	
	for(int i=0; i<n; i++) find(i);
	
	long long x = 0;
	for(int i=0; i<n; i++) x+=ans[i];

	cout << x;
	return 0;
}

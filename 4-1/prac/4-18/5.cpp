#include <iostream>
#include <vector>

using namespace std;

int n;

int a[11];
int check[11];

int ans1 = -1000000000;
int ans2 = 1000000000;

int op(int s, int a, int o){
	if(o==0) return s+a;
	if(o==1) return s-a;
	if(o==2) return s*a;
	if(o==3){
		if(s < 0){
			int t = 0 - s;
			t = t / a;
			return 0-t;
		}
		return s/a;
	}

}

int oper(vector<int> v, vector<int> c){
	int s = v[0];
	for(int i=0; i<n-1; i++){
		s = op(s,v[i+1],c[i]);
	}
	return s;
}

void find(int k, int o[4], vector<int> v, vector<int> c){
	if(k==2*n-1){
		int s = 0;
		s = oper(v,c);
		if(s > ans1){
			ans1 = s;
		}
		if(s < ans2){
			ans2 = s;
		}
		return;
	}
	if(k%2==0){
		v.push_back(a[k/2]);
		find(k+1,o,v,c);
	}
	else{
		for(int i=0; i<4; i++){
			if(o[i] == 0) continue;
			o[i]--;
			c.push_back(i);
			find(k+1,o,v,c);
			c.pop_back();
			o[i]++;
		}
	}

}

int main(){
	cin >> n;
	int o[4];
	for(int i=0; i<n; i++) cin >> a[i];
	cin >> o[0] >> o[1] >> o[2] >> o[3];

	vector<int> v;
	vector<int> c;
	find(0,o,v,c);

	cout << ans1 << endl << ans2;

}

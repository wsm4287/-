#include <iostream>
#include <vector>

using namespace std;

vector <char> v[4];

int n;

vector <pair<int, int>> m;

void	left(int k){
	int temp = v[k][0];
	for(int i=0; i<7; i++){
		v[k][i] = v[k][i+1];
	}
	v[k][7] = temp;
}

void	right(int k){
	int temp = v[k][7];
	for(int i=7; i>0; i--){
		v[k][i] = v[k][i-1];
	}
	v[k][0] = temp;
}

void start(int k){
	if(n == k) return;

	int x = m[k].first;
	int y = m[k].second;

	int check[4] = {0,};
	check[x] = y;

	if(x==0){
		if(v[0][2] != v[1][6]){
			check[1] = 0-y;
			if(v[1][2] != v[2][6]){
				check[2] = y;
				if(v[2][2] != v[3][6]) check[3] = 0-y;
			}
		}
	}

	else if(x==1){
		if(v[0][2] != v[1][6]){
			check[0] = 0-y;
		}
		if(v[1][2] != v[2][6]){
			check[2] = 0-y;
			if(v[2][2] != v[3][6]) check[3] = y;
		}
	}

	else if(x==2){
		if(v[1][2] != v[2][6]){
			check[1] = 0-y;
			if(v[0][2] != v[1][6]) check[0] = y;
		}
		if(v[2][2] != v[3][6]){
			check[3] = 0-y;
		}
	}

	else{
		if(v[2][2] != v[3][6]){
			check[2] = 0-y;
			if(v[1][2] != v[2][6]){
				check[1] = y;
				if(v[0][2] != v[1][6]) check[0] = 0-y;
			}
		}
	}


	for(int i=0; i<4; i++){
		if(check[i] == 1) right(i);
		else if(check[i] == -1) left(i);
	}



	start(k+1);
}


int main(){
	char a;
	for(int i=0; i<4; i++){
		for(int j=0; j<8; j++){
			cin >> a;
			v[i].push_back(a);
		}
	}
	cin >> n;
	int x, y;
	for(int i=0; i<n; i++){
		cin >> x >> y;
		m.push_back({x-1,y});
	}
	
	start(0);


	int ans=0;
	
	if(v[0][0] == '1') ans+= 1;
	if(v[1][0] == '1') ans+= 2;
	if(v[2][0] == '1') ans+= 4;
	if(v[3][0] == '1') ans+= 8;

	cout << ans;

	return 0;
}


#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int N;

int map[22][22];
int s = 2;
int count;
int ans;

int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};

int x,y;

int select(){
	
	
	
	
	int d = abs(mx-x)+abs(my-y);
	cout << endl;
	cout <<y << " " << x << " " << my << " " << mx<< " " << d << endl;
	if(s == m) count++;
	if(count == s){
		count = 0;
		s++;
	}
	y = my;
	x = mx;
	return d;
}

void find(int k){
	int c = 0;
	for(int i=0; i<fish.size(); i++){
		if(s > fish[i].first){
			c = 1;
			break;
		}
	}
	if(c==0){
		ans = k;
		return;
	}
	
	find(k+select());
}


int main(){
	cin >> N;
	int a;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> a;
			if(a==9){
				y = i;
				x = j;
			}
			else if(a==0) continue;
			else{
				fish.push_back({a,{i,j}});
				map[i][j] = a;
			}
		}
	}
	find(0);
	
	cout << ans;
}

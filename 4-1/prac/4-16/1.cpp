#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int people[11];
int map[11][11];
int ans=9999;
int visit[11];


void find(vector<int> a, vector<int> b, int k){
	if(k==N){
		if(a.empty() || b.empty()) return;
	
		for(int i=0; i<N; i++) visit[i] = 1;
		for(int i=0; i<a.size(); i++) visit[a[i]] = 0;

		queue<int> q;
		q.push(a[0]);
		visit[a[0]] = 1;
		while(!q.empty()){
			int s = q.front();
			q.pop();
			for(int i=0; i<N; i++){
				if(map[s][i] && visit[i] == 0){
					visit[i] = 1;
					q.push(i);
				}
			}
		}
		int c = 0;
		for(int i=0; i<N; i++){
			if(visit[i] == 0){
				c = 1;
				break;
			}
		}
		if(c) return;

		for(int i=0; i<N; i++) visit[i] = 1;
		for(int i=0; i<b.size(); i++) visit[b[i]] = 0;

		q.push(b[0]);
		visit[b[0]] = 1;
		while(!q.empty()){
			int s = q.front();
			q.pop();
			for(int i=0; i<N; i++){
				if(map[s][i] && visit[i] == 0){
					visit[i] = 1;
					q.push(i);
				}
			}
		}
		for(int i=0; i<N; i++){
			if(visit[i] == 0){
				c = 1;
				break;
			}
		}
		if(c) return;

		int dif;
		int suma = 0;
		int sumb = 0;
		for(int i=0; i<a.size(); i++){
			suma += people[a[i]];
		}
		for(int i=0; i<b.size(); i++){
			sumb += people[b[i]];
		}
		if(suma > sumb) dif = suma-sumb;
		else dif = sumb-suma;
		if(ans > dif) ans = dif;
	}

	else{
		a.push_back(k);
		find(a,b,k+1);
		a.pop_back();
		b.push_back(k);
		find(a,b,k+1);
		b.pop_back();
	}
}


int main(){
	cin >> N;
	for(int i=0; i<N; i++) cin >> people[i];
	int n;
	for(int i=0; i<N; i++){
		cin >> n;
		int x;
		for(int j=0; j<n; j++){
			cin >> x;
			map[i][x-1] = 1;
		}
	}
	vector<int> a;
	vector<int> b;
	find(a,b,0);
	if(ans == 9999) ans = -1;
	cout << ans;
}

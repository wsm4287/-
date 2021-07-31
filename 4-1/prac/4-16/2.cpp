#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,M;
vector<pair<int,int>> city[6];
int visit[10][10];

int check[6];
int link[6][6];

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

int map[10][10];

int cnt = 0;

int ans = 999999;

int chk(){
	for(int i=0; i<cnt; i++) check[i] = 0;

	queue<int> qq;
	qq.push(0);
	check[0]=1;
	while(!qq.empty()){
		int s = qq.front();
		qq.pop();
		for(int i=0; i<cnt; i++){
			if(link[s][i] && !check[i]){
				check[i]=1;
				qq.push(i);
			}
		}
	}
	for(int i=0; i<cnt; i++){
		if(check[i]==0) return 0;
	}
	return 1;
}

void scan(){
	queue<pair<int,int>> q;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j] && !visit[i][j]){
				visit[i][j] = 1;
				q.push({i,j});
				city[cnt].push_back({i,j});
				while(!q.empty()){
					int y1 = q.front().first;
					int x1 = q.front().second;
					q.pop();
					for(int k=0; k<4; k++){
						int ny = y1 + dy[k];
						int nx = x1 + dx[k];
						if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
						if(map[ny][nx] && !visit[ny][nx]){
							visit[ny][nx] = 1;
							q.push({ny,nx});
							city[cnt].push_back({ny,nx});
						}
					}
					
				}
				cnt++;
			}
		}
	}
}

int possible(int a, int b){

	int min[city[a].size()][2];
	for(int i=0; i<city[a].size(); i++){
		min[i][0] = 99;
		min[i][1] = 99;
		min[i][2] = 99;
	}


	for(int i=0; i<city[a].size(); i++){
		for(int j=0; j<city[b].size(); j++){
			if(city[a][i].first == city[b][j].first){
				int dif = 0;
				int u = 0;
				if(city[a][i].second > city[b][j].second){
					for(int k=city[b][j].second+1; k<city[a][i].second; k++) if(map[city[a][i].first][k] == 1) u = 1;
					if(u) continue;
					dif = city[a][i].second - city[b][j].second;
				}
				else{
					for(int k=city[a][i].second+1; k<city[b][j].second; k++) if(map[city[a][i].first][k] == 1) u = 1;
					if(u) continue;
					dif = city[b][j].second - city[a][i].second;
				}
				dif -=1;
				if(dif == 1) continue;
				if(min[i][0] > dif){
					min[i][0] = dif;
					min[i][1] = city[a][i].first;
					min[i][2] = city[a][i].second;
				}
				min[i+1][0] = 99;
			}
			if(city[a][i].second == city[b][j].second){

				int dif = 0;
				int u = 0;
				if(city[a][i].first > city[b][j].first){
					for(int k=city[b][j].first+1; k<city[a][i].first; k++) if(map[k][city[a][i].second] == 1) u = 1;
					if(u) continue;
					dif = city[a][i].first - city[b][j].first;
				}
				else{
					for(int k=city[a][i].first+1; k<city[b][j].first; k++) if(map[k][city[a][i].second] == 1) u = 1;
					if(u) continue;
					dif = city[b][j].first - city[a][i].first;
				}
				dif -=1;
				if(dif == 1) continue;
				if(min[i][0] > dif){
					min[i][0] = dif;
					min[i][1] = city[a][i].first;
					min[i][2] = city[a][i].second;
				}
				min[i+1][0] = 99;

			}

		}
	}
	
	int mm = 99;
	int x1, y1;
	/*for(int i=0; i<city[a].size(); i++){
		cout << min[i][0] << endl;
	}*/
	
	for(int i=0; i<city[a].size(); i++){
		if(min[i][0] == 99) continue;
		if(min[i][0] == 1) continue;
		if(mm > min[i][0] && (y1 != min[i][1] || x1 != min[i][2])){
			mm = min[i][0];
			y1 = min[i][1];
			x1 = min[i][2];
		}
	}
	if(mm == 99) return 0;
	else return mm;

}

void find(int l, int k){


	/*for(int i=0; i<cnt; i++){
		for(int j=i+1; j<cnt; j++){
			cout << i << " " << j << endl << possible(i,j) << endl;
		}
		cout << endl;
	}*/
		if(l > ans) return;
	
	if(k==cnt){
		if(chk()==0) return;
		/*cout << endl << l << endl;
		for(int i=0; i<cnt; i++){
			for(int j=0; j<cnt; j++) cout << link[i][j] << " ";
			cout << endl;
		}*/
		if(ans > l) ans = l;
		return;
	}

	for(int i=k+1; i<cnt; i++){
		if(link[k][i]) continue;
		int t = possible(k,i);
		if(t==0) continue;
		link[k][i] = 1;
		link[i][k] = 1;
		find(l+t, k);
		find(l+t,k+1);
		link[k][i] = 0;
		link[i][k] = 0;
	}
	find(l,k+1);

	
}


int main(){
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> map[i][j];
		}
	}
	scan();
	for(int i=0; i<6; i++) sort(city[i].begin(), city[i].end());

	/*for(int i=0; i<cnt; i++){
		for(int j=0; j<city[i].size(); j++) cout << city[i][j].first << " " << city[i][j].second << endl;
		cout << endl;
	}*/

	//cout << cnt << endl;
	find(0,0);
	

	if(ans==999999) ans = -1;
	cout << ans;
	return 0;
}

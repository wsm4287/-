#include <iostream>
#include <queue>

using namespace std;

int n,l;
int ans;

int map[110][110];

void down(int k){
	queue <pair<int,int>> line;
	line.push({map[0][k],1});
	for(int i=1; i<n; i++){
		if(map[i][k] == line.front().first){
			line.front().second++;
		}
		else if(map[i][k] - line.front().first == 1){
			if(line.front().second<l) return;
			line.pop();
			line.push({map[i][k],1});
		}
		else if(line.front().first - map[i][k] == 1){
			int c = 0;
			int x = map[i][k];
			while(map[i][k] == x && c<l){
				i++;
				c++;
			}
			if(c<l) return;
			i--;
			line.pop();
			line.push({map[i][k],0});
		}
		else return;
	}
		ans++;
}

void right(int k){
	queue <pair<int,int>> line;
	line.push({map[k][0],1});
	for(int i=1; i<n; i++){
		if(map[k][i] == line.front().first){
			line.front().second++;
		}
		else if(map[k][i] - line.front().first == 1){
			if(line.front().second<l) return;
			line.pop();
			line.push({map[k][i],1});
		}
		else if(line.front().first - map[k][i] == 1){
			int c = 0;
			int x = map[k][i];
			while(map[k][i] == x && c<l){
				i++;
				c++;
			}
			if(c<l) return;
			i--;
			line.pop();
			line.push({map[k][i],0});
		}
		else return;
	}
		ans++;
}


int main(){
	cin >> n >> l;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) cin >> map[i][j];
	}

	for(int i=0; i<n; i++){
		down(i);
		right(i);
	}
	cout << ans;
}

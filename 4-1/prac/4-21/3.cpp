#include <iostream>
#include <vector>

using namespace std;

int n,m;
int map[9][9];
int ans = 999999;
vector <pair<int,pair<int,int>>> v;

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

void copy(int a[9][9], int b[9][9]){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) a[i][j] = b[i][j];
	}
}

void find(int k, int temp[9][9]){
	if(k == v.size()){
		/*cout << endl;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++) cout << temp[i][j] << " ";
			cout << endl;*/
		

		int sum=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(temp[i][j] == 0) sum++;
			}
		}
		if(ans > sum) ans = sum;
		return;
	}

	int y = v[k].second.first;
	int x = v[k].second.second;
	int c = v[k].first;

	int cop[9][9];
	copy(cop,temp);


	if(c==1){
		for(int i=0; i<4; i++){
			int nx = x;
			int ny = y;
			while(1){
				temp[ny][nx] = 1;
				ny = ny + dy[i];
				nx = nx + dx[i];
				if(ny <0 || nx <0 || ny > n-1 || nx > m-1) break;
				if(temp[ny][nx] == 6) break;
			}
			find(k+1,temp);
			copy(temp,cop);
		}
	}

	else if(c==2){
		for(int i=0; i<4; i++){
			int nx = x;
			int ny = y;
			int d = i;
			while(1){
				temp[ny][nx] = 1;
				ny = ny + dy[d];
				nx = nx + dx[d];
				if(ny <0 || nx <0 || ny > n-1 || nx > m-1) break;
				if(temp[ny][nx] == 6) break;
			}
			nx = x;
			ny = y;
			d = (i+2)%4;
			while(1){
				temp[ny][nx] = 1;
				ny = ny + dy[d];
				nx = nx + dx[d];
				if(ny <0 || nx <0 || ny > n-1 || nx > m-1) break;
				if(temp[ny][nx] == 6) break;
			}
			find(k+1,temp);
			copy(temp,cop);
		}
	}

	else if(c==3){
		for(int i=0; i<4; i++){
			int nx = x;
			int ny = y;
			int d = i;
			while(1){
				temp[ny][nx] = 1;
				ny = ny + dy[d];
				nx = nx + dx[d];
				if(ny <0 || nx <0 || ny > n-1 || nx > m-1) break;
				if(temp[ny][nx] == 6) break;
			}
			nx = x;
			ny = y;
			d = (i+1)%4;
			while(1){
				temp[ny][nx] = 1;
				ny = ny + dy[d];
				nx = nx + dx[d];
				if(ny <0 || nx <0 || ny > n-1 || nx > m-1) break;
				if(temp[ny][nx] == 6) break;
			}
			find(k+1,temp);
			copy(temp,cop);
		}
	}

	else if(c==4){
		for(int i=0; i<4; i++){
			int nx = x;
			int ny = y;
			int d = i;
			while(1){
				temp[ny][nx] = 1;
				ny = ny + dy[d];
				nx = nx + dx[d];
				if(ny <0 || nx <0 || ny > n-1 || nx > m-1) break;
				if(temp[ny][nx] == 6) break;
			}
			nx = x;
			ny = y;
			d = (i+1)%4;
			while(1){
				temp[ny][nx] = 1;
				ny = ny + dy[d];
				nx = nx + dx[d];
				if(ny <0 || nx <0 || ny > n-1 || nx > m-1) break;
				if(temp[ny][nx] == 6) break;
			}
			nx = x;
			ny = y;
			d = (d+1)%4;
			while(1){
				temp[ny][nx] = 1;
				ny = ny + dy[d];
				nx = nx + dx[d];
				if(ny <0 || nx <0 || ny > n-1 || nx > m-1) break;
				if(temp[ny][nx] == 6) break;
			}
			find(k+1,temp);
			copy(temp,cop);
		}
	}

	else if(c == 5){
		for(int i=0; i<4; i++){
			int nx = x;
			int ny = y;
			while(1){
				temp[ny][nx] = 1;
				ny = ny + dy[i];
				nx = nx + dx[i];
				if(ny <0 || nx <0 || ny > n-1 || nx > m-1) break;
				if(temp[ny][nx] == 6) break;
			}
		}
		find(k+1,temp);
		copy(temp,cop);
	}

}

int main(){
	cin >> n >> m;
	int x;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> x;
			if(x >=1 && x <= 5) v.push_back({x,{i,j}});
			else map[i][j] = x;
		}
	}


	find(0, map);

	cout << ans;
}

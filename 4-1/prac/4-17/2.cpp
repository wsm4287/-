#include <iostream>
#include <queue>

using namespace std;

int n;
int map[20][20];
int ans;

void left(int temp[20][20]){
	for(int i=0; i<n; i++){
		queue<int> q;
		for(int j=0; j<n; j++){
			if(temp[i][j] == 0) continue;
			q.push(temp[i][j]);
			temp[i][j] = 0;
		}
		int cnt = 0;
		while(!q.empty()){
			int s = q.front();
			q.pop();
			if(temp[i][cnt] == 0){
				temp[i][cnt] = s;
			}
			else if(temp[i][cnt] == s){
				temp[i][cnt] = s*2;
				cnt++;
			}
			else{
				cnt++;
				temp[i][cnt] = s;
			}
		}
	}
}

void right(int temp[20][20]){
	for(int i=0; i<n; i++){
		queue<int> q;
		for(int j=n-1; j>=0; j--){
			if(temp[i][j] == 0) continue;
			q.push(temp[i][j]);
			temp[i][j] = 0;
		}
		int cnt = n-1;
		while(!q.empty()){
			int s = q.front();
			q.pop();
			if(temp[i][cnt] == 0){
				temp[i][cnt] = s;
			}
			else if(temp[i][cnt] == s){
				temp[i][cnt] = s*2;
				cnt--;
			}
			else{
				cnt--;
				temp[i][cnt] = s;
			}
		}
	}
}

void up(int temp[20][20]){
	for(int i=0; i<n; i++){
		queue<int> q;
		for(int j=0; j<n; j++){
			if(temp[j][i] == 0) continue;
			q.push(temp[j][i]);
			temp[j][i] = 0;
		}
		int cnt = 0;
		while(!q.empty()){
			int s = q.front();
			q.pop();
			if(temp[cnt][i] == 0){
				temp[cnt][i] = s;
			}
			else if(temp[cnt][i] == s){
				temp[cnt][i] = s*2;
				cnt++;
			}
			else{
				cnt++;
				temp[cnt][i] = s;
			}
		}
	}
}

void down(int temp[20][20]){
	for(int i=0; i<n; i++){
		queue<int> q;
		for(int j=n-1; j>=0; j--){
			if(temp[j][i] == 0) continue;
			q.push(temp[j][i]);
			temp[j][i] = 0;
		}
		int cnt = n-1;
		while(!q.empty()){
			int s = q.front();
			q.pop();
			if(temp[cnt][i] == 0){
				temp[cnt][i] = s;
			}
			else if(temp[cnt][i] == s){
				temp[cnt][i] = s*2;
				cnt--;
			}
			else{
				cnt--;
				temp[cnt][i] = s;
			}
		}
	}
}

void find(int temp[20][20], int k){

	
	if(k>=5){
		int mx = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(temp[i][j] > mx) mx = temp[i][j];
			}
		}
		if(mx >ans) ans = mx;
		return;
	}

	int copy[20][20];

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) copy[i][j] = temp[i][j];
	
	}
	
	left(temp);
	find(temp, k+1);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) temp[i][j] = copy[i][j];
	}

	right(temp);
	find(temp, k+1);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) temp[i][j] = copy[i][j];
	}

	up(temp);
	find(temp, k+1);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) temp[i][j] = copy[i][j];
	}

	down(temp);	
	find(temp, k+1);
	
}

int main(){
	cin >> n;
	int temp[20][20];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> map[i][j];
			temp[i][j] = map[i][j];
		}
	}
	find(temp, 0);
	

	cout << ans;

	return 0;
}

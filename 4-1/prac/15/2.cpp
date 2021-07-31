#include <iostream>
#include <queue>

using namespace std;

int N;

int map[20][20];
int max1;
int check;

void up(){
	for(int j=0; j<N; j++){
		queue<int> s;
		for(int i=0; i<N; i++){
			if(map[i][j]==0) continue;
			s.push(map[i][j]);
			map[i][j]=0;
		}
		int cnt=0;
		while(!s.empty()){
			int ss = s.front();
			s.pop();
			if(map[cnt][j]==0){
				map[cnt][j] = ss;
			}
			else if(map[cnt][j]==ss){
				map[cnt][j] = 2*ss;
				cnt++;
			}
			else{
				cnt++;
				map[cnt][j] = ss;
			}
		}
	}
}

void down(){
	for(int j=0; j<N; j++){
		queue<int> s;
		for(int i=N-1; i>=0; i--){
			if(map[i][j]==0) continue;
			s.push(map[i][j]);
			map[i][j]=0;
		}
		int cnt=N-1;
		while(!s.empty()){
			int ss = s.front();
			s.pop();
			if(map[cnt][j]==0){
				map[cnt][j] = ss;
			}
			else if(map[cnt][j]==ss){
				map[cnt][j] = 2*ss;
				cnt--;
			}
			else{
				cnt--;
				map[cnt][j] = ss;
			}
		}
	}
}

void right(){
	for(int i=0; i<N; i++){
		queue<int> s;
		for(int j=N-1; j>=0; j--){
			if(map[i][j]==0) continue;
			s.push(map[i][j]);
			map[i][j]=0;
		}
		int cnt=N-1;
		while(!s.empty()){
			int ss = s.front();
			s.pop();
			if(map[i][cnt]==0){
				map[i][cnt] = ss;
			}
			else if(map[i][cnt]==ss){
				map[i][cnt] = 2*ss;
				cnt--;
			}
			else{
				cnt--;
				map[i][cnt] = ss;
			}
		}
	}
}

void left(){
	for(int i=0; i<N; i++){
		queue<int> s;
		for(int j=0; j<N; j++){
			if(map[i][j]==0) continue;
			s.push(map[i][j]);
			map[i][j]=0;
		}
		int cnt=0;
		while(!s.empty()){
			int ss = s.front();
			s.pop();
			if(map[i][cnt]==0){
				map[i][cnt] = ss;
			}
			else if(map[i][cnt]==ss){
				map[i][cnt] = 2*ss;
				cnt++;
			}
			else{
				cnt++;
				map[i][cnt] = ss;
			}
		}
	}
}

void find(int k){
	if(k==5){
		int x=0;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(map[i][j] > x) x = map[i][j];
			}
		}
		if(x > max1) max1 = x;
		return;
	}

	int temp[20][20];

	for(int i=0; i<N; i++){	
		for(int j=0; j<N; j++){
			temp[i][j] = map[i][j];
		}
	}


	up();

	find(k+1);
	for(int i=0; i<N; i++){	
		for(int j=0; j<N; j++){
			map[i][j] = temp[i][j];
		}
	}



	right();

	find(k+1);
	for(int i=0; i<N; i++){	
		for(int j=0; j<N; j++){
			map[i][j] = temp[i][j];
		}
	}



	down();

	find(k+1);
	for(int i=0; i<N; i++){	
		for(int j=0; j<N; j++){
			map[i][j] = temp[i][j];
		}
	}	


	left();

	find(k+1);
	for(int i=0; i<N; i++){	
		for(int j=0; j<N; j++){
			map[i][j] = temp[i][j];
		}
	}
}

int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> map[i][j];
		}
	}
	find(0);
	cout << max1;
	return 0;
}

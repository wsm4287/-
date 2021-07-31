#include <iostream>
#include <queue>

using namespace std;

int n, l;
int map[100][100];
int ans;

void findx(int k){
	//cout <<"x " << k << endl;
	
	queue<pair<int,pair<int,int>>> q;
	q.push({0,{map[k][0],1}});
	for(int i=1; i<n; i++){
		//cout << q.front().first << " " << q.front().second.first << " " << q.front().second.second << " " << endl;
		if(map[k][i] == q.front().second.first){
			q.push({q.front().first,{map[k][i], q.front().second.second+1}});
			q.pop();
		}
		else{
			int dif = q.front().second.first - map[k][i];
				//cout << dif << " " << q.front().second.second << endl;
			if(dif != -1 && dif != 1) return;
			if(q.front().first == 0){
				//cout << dif << " " << q.front().second.second << endl;
				if(dif == -1 && q.front().second.second < l) return;
				q.push({dif, {map[i][k], 1}});
				q.pop();
			}
			else{
				if(q.front().first != dif){
					if(dif == -1 && q.front().second.second < 2 * l) return;
					q.push({dif,{map[i][k], 1}});
					q.pop();
				}
				else{
					if(q.front().second.second < l) return;
					q.push({dif,{map[i][k],1}});
					q.pop();
				}
				
			}
		}

	}
	if(q.front().second.second >= l) ans++;


}

void findy(int k){
	//cout << "y " << k << endl;
	queue<pair<int,pair<int,int>>> q;
	q.push({0,{map[0][k],1}});
	for(int i=1; i<n; i++){
		//cout << q.front().first << " " << q.front().second.first << " " << q.front().second.second << endl;
		if(map[i][k] == q.front().second.first){
			q.push({q.front().first, {map[i][k], q.front().second.second+1}});
			q.pop();
		}
		else{
			int dif = q.front().second.first - map[i][k];
			if(dif != -1 && dif != 1) return;
			if(q.front().first == 0){
				if(dif == -1 && q.front().second.second < l) return;
				q.push({dif, {map[i][k], 1}});
				q.pop();
			}
			else{
				if(q.front().first != dif){
					if(dif == -1 && q.front().second.second < 2 * l) return;
					q.push({dif,{map[i][k], 1}});
					q.pop();
				}
				else{
					if(q.front().second.second < l) return;
					q.push({dif,{map[i][k],1}});
					q.pop();
				}
				
			}
		}
	}
	if(q.front().second.second >= l) ans++;

}

int main(){
	cin >> n >> l;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) cin >> map[i][j];
	}

	for(int i=0; i<n; i++){
		//cout << endl;
		findx(i);
		//cout << endl;
		findy(i);
		//cout << endl;
		}


	cout << ans;

}

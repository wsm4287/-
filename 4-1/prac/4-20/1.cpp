#include <iostream>
#include <vector>

using namespace std;

int n;

int s[21][21];
int ans = 9999999;
int visit[21];

void find(int k, int p){
	if(k==n/2){
		int sum0 = 0;
		int sum1 = 0;

		vector<int> start;
		vector<int> link;

		for(int i=0; i<n; i++){
			if(visit[i] == 0){
				start.push_back(i);
			}
			else
				link.push_back(i);
		}
		for(int i=0; i<start.size()-1; i++){
			for(int j=i+1; j<start.size(); j++){
				sum0 += s[link[i]][link[j]] + s[link[j]][link[i]];
				sum1 += s[start[i]][start[j]] + s[start[j]][start[i]];
			}
		}
		int dif;
		if(sum0 > sum1) dif = sum0-sum1;
		else dif = sum1 - sum0;
		if(ans > dif) ans = dif;
		return;
	}

	for(int i=p+1; i<n; i++){
		if(visit[i]) continue;
		visit[i] = 1;
		find(k+1,i);
		visit[i] = 0;
	}
	

}


int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) cin >> s[i][j];
	}

	find(0,-1);

	cout << ans;

	return 0;
}

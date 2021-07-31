#include <iostream>
#include <vector>

using namespace std;

int T, N, M, K;

struct an{
	int x,y,s,d,t;
};

int ans;
vector<int> map[100][100];

int dx[]={0,0,0,-1,1};
int dy[]={0,-1,1,0,0};

int main(){
	cin >>T;
	for(int t=1; t<=T; t++){
		cin >> N >>M >> K;
		vector<an> aa(K);
		for(int i=0; i<K; i++){
			cin >> aa[i].y >> aa[i].x >> aa[i].s >> aa[i].d;
			map[aa[i].y][aa[i].x].push_back(i);
		}
		int k = 0;
	
		while(k<M){
			for(int i=0; i<K; i++){
				if(aa[i].s==0) continue;
				map[aa[i].y][aa[i].x].clear();
			}
			for(int i=0; i<K; i++){
				if(aa[i].s==0)continue;
				aa[i].x += dx[aa[i].d];
				aa[i].y += dy[aa[i].d];
				map[aa[i].y][aa[i].x].push_back(i);
			}
			for(int i=0; i<K; i++){
				if(aa[i].s==0) continue;
				if(aa[i].y ==0 || aa[i].x ==0 || aa[i].y ==N-1 || aa[i].x ==N-1){
					aa[i].s=aa[i].s/2;
					if(aa[i].d==1) aa[i].d=2;
					else if(aa[i].d==2) aa[i].d=1;
					else if(aa[i].d==3) aa[i].d=4;
					else if(aa[i].d==4) aa[i].d=3;
				}
				else if(map[aa[i].y][aa[i].x].size()>1){
					int x = aa[i].x;
					int y = aa[i].y;
					int max_s = 0;
					int max_d = 0;
					int max_cnt = 0;
					int sum = 0;
					for(int j=0; j< map[y][x].size(); j++){
						sum += aa[map[y][x][j]].s;
						if(aa[map[y][x][j]].s > max_s){
							max_s = aa[map[aa[i].y][aa[i].x][j]].s; 
							max_d = aa[map[aa[i].y][aa[i].x][j]].d; 
							max_cnt = map[aa[i].y][aa[i].x][j]; 
						}
						aa[map[aa[i].y][aa[i].x][j]].s = 0;
					}
					aa[max_cnt].s = sum;
					aa[max_cnt].d = max_d;
				}
			}
			k++;
		}
	
		for(int i=0; i<K; i++) ans += aa[i].s;
		
		cout << "#" << t << " " << ans << endl;
		ans = 0;
		aa.clear();
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				map[i][j].clear();
			}
		}
	}

	return 0;
}

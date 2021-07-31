#include <iostream>
#include <vector>

using namespace std;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};

int T, N;

int map[4001][4001];

struct atom{
	int x;
	int y;
	int d;
	int e;
};

vector<atom> a;

int ans;
int cnt;

void find(){
	while(cnt>0){
		for(int i=0; i<N; i++){
			if(a[i].e == 0) continue;
			map[a[i].y][a[i].x] = 0;
			int nx = a[i].x + dx[a[i].d];
			int ny = a[i].y + dy[a[i].d];
			if(nx <0 || ny <0 || nx >4000 || ny >4000){
				a[i].e = 0;
				cnt--;
				continue;
			}
			a[i].x = nx;
			a[i].y = ny;
			map[a[i].y][a[i].x] = i;
		}
		for(int i=0; i<N; i++){
			if(a[i].e == 0) continue;
			if(map[a[i].y][a[i].x] != i){
				cout << a[i].x << " " << a[i].y << " " << a[i].e << endl;
				ans += a[i].e;
				a[i].e = 0;
				map[a[i].y][a[i].x] = 0;
				cnt--;
			}

		}

	}


}

int main(){
	cin >> T;
	for(int i=1; i<=T; i++){
		cin >> N;
		cnt = N;
		atom aa;
		for(int j=0; j<N; j++){
			cin >> aa.x >> aa.y >> aa.d >> aa.e;
			aa.x = 2000 + 2*aa.x;
			aa.y = 2000 + 2*aa.y;
			a.push_back(aa);
		}
		find();
		cout << "#" << i << " " << ans << endl;
		ans = 0;
		a.clear();
	}
	return 0;


}

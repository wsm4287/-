#include <iostream>
using namespace std;

struct BC{
	int x, y;
	int C;
	int P;
};

BC bc[8];

int map[11][11];
int a[110];
int b[110];

int ax = 1;
int ay = 1;
int bx = 10;
int by = 10;

int dx[] = {0, 0, 1, 0, -1};
int dy[] = {0, -1, 0, 1, 0};

int T, M, A;
int ans;

int dis(int x1, int x2, int y1, int y2){
	int x=0;
	if(x1 >= x2) x= x1 - x2;
	else x = x2 - x1;

	int y=0;
	if(y1 >= y2) y = y1 - y2;
	else y = y2 - y1;
	return x+y;
}

void set(int key, int x, int y, int C){
	for(int i=1; i<=10; i++){
		for(int j=1; j<=10; j++){
			if(dis(x,j,y,i)<=C){
				if(map[i][j] == 0) map[i][j] = key;
				else map[i][j] = 10*map[i][j]+key;
			}
		}
	}


}

int check(int *x1, int *x2, int p1, int p2){
	int max = 0;
	for(int i=0; i<p1; i++){
		int k = bc[x1[i]-1].P;
		for(int j=0; j<p2; j++){
			if(x1[i] != x2[j]){
				k += bc[x2[j]-1].P;
				if(k > max) max = k;
				k -= bc[x2[j]-1].P;
			}
		}
	}
	return max;
}

void find(){
	int k=0;
	while(k<=M){
		if(map[ay][ax] > 0 && map[ay][ax] < 10){
			if(map[ay][ax] == map[by][bx]){
				ans+= bc[map[ay][ax]-1].P;
			}
			else if(map[by][bx] > 0 && map[by][bx] < 10){
					ans += bc[map[by][bx]-1].P;
					ans += bc[map[ay][ax]-1].P;
			}
			else if(map[by][bx] > 10){
				int xx[8] = {0,};
				int pp = map[by][bx];
				int cnt=0;
				while(pp){
					xx[cnt++] = pp % 10;
					pp = pp /10;
				}
				int max = 0;
				for(int i=0; i< cnt; i++){
					if(bc[xx[i]-1].P > max){ 
						if(xx[i] != map[ay][ax])
							max = bc[xx[i]-1].P;
					}
				}
				ans += max;
				ans += bc[map[ay][ax]-1].P;
			}
			else
				ans +=bc[map[ay][ax]-1].P;	
		}

		else if(map[ay][ax] >10){
			if(map[by][bx] >0 && map[by][bx] < 10){
				ans += bc[map[by][bx]-1].P;
				int xx[8] = {0,};
				int pp = map[ay][ax];
				int cnt=0;
				while(pp){
					xx[cnt++] = pp % 10;
					pp = pp /10;
				}
				int max = 0;
				for(int i=0; i< cnt; i++){
					if(bc[xx[i]-1].P > max && xx[i] != map[by][bx]) max = bc[xx[i]-1].P;
				}
				ans += max;
			}
			else if(map[by][bx] == map[ay][ax]){
				int xx[8] = {0,};
				int pp = map[by][bx];
				int cnt=0;
				while(pp){
					xx[cnt++] = pp % 10;
					pp = pp /10;
				}
				int max1 = 0;
				int max2 = 0;
				for(int i=0; i< cnt; i++){
					if(bc[xx[i]-1].P > max1){
						max2 = max1;
						max1 = bc[xx[i]-1].P;
					}
				}
				ans += max1;
				ans += max2;
			}
			else if(map[by][bx] != 0){
				int xx1[8] = {0,};
				int xx2[8] = {0,};
				int pp1 = map[ay][ax];
				int pp2 = map[by][bx];
				int cnt1=0;
				int cnt2=0;
				while(pp1){
					xx1[cnt1++] = pp1 % 10;
					pp1 = pp1 /10;
				}
				while(pp2){
					xx2[cnt2++] = pp2 % 10;
					pp2 = pp2 / 10;
				}
				ans += check(xx1, xx2, cnt1, cnt2);
			}
			else{
				int xx[8] = {0,};
				int pp = map[ay][ax];
				int cnt=0;
				while(pp){
					xx[cnt++] = pp % 10;
					pp = pp /10;
				}
				int max = 0;
				for(int i=0; i< cnt; i++){
					if(bc[xx[i]-1].P > max && xx[i] != map[by][bx]) max = bc[xx[i]-1].P;
				}
				ans += max;	
			}
		}


		else{
			if(map[by][bx] >0 && map[by][bx] < 10){
				ans += bc[map[by][bx]-1].P;
			}
			else if(map[by][bx] > 10){
				int xx[8] = {0,};
				int pp = map[by][bx];
				int cnt=0;
				while(pp){
					xx[cnt++] = pp % 10;
					pp = pp /10;
				}
				int max = 0;
				for(int i=0; i< cnt; i++){
					if(bc[xx[i]-1].P > max) max = bc[xx[i]-1].P;
				}
				ans += max;
			}
		}
		cout << ax << " " << ay << " " << map[ay][ax] << endl;
		cout << bx << " " << by << " " << map[by][bx] << endl;
		cout << ans << endl;
		cout << endl;
		ax = ax + dx[a[k]];
		ay = ay + dy[a[k]];
		bx = bx + dx[b[k]];
		by = by + dy[b[k]];
		k++;
	}
}


int main(){
	cin >> T;
	for(int i=1; i<=T; i++){
		cin >> M >> A;
		for(int j=0; j<M; j++){
			cin >> a[j];
		}
		for(int j=0; j<M; j++){
			cin >> b[j];
		}
		for(int j=0; j<A; j++){
			cin >> bc[j].x >> bc[j].y >> bc[j].C >> bc[j].P;
			set(j+1, bc[j].x, bc[j].y, bc[j].C);
		}

		find();
		cout << "#" << i << " " << ans << endl;
		ans = 0;
		for(int j=0; j<12; j++){
			for(int k=0; k<12; k++){
				map[j][k] = 0;
			}
		}
		ax = ay = 1;
		bx = by = 10;
	}

	return 0;
}

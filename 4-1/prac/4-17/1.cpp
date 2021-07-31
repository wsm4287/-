#include <iostream>

using namespace std;

int n,m;
char map[10][10];
int O[2];
int ans = 99;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

void find(int k, int by, int bx, int ry, int rx, int d){
	if(k>10) return;
	if(by == O[0] && bx == O[1]) return;
	if(ry == O[0] && rx == O[1]){
		//cout << k << " " << by << " " << bx << " " << ry << " " << rx << " " << d <<endl;
		if(ans > k) ans = k;
		return;
	}

	for(int i=0; i<4; i++){
		if(d == 0 && i == 1) continue;
		if(d == 1 && i == 0) continue;
		if(d == 2 && i == 3) continue;
		if(d == 3 && i == 2) continue;

		int bny = by;
		int bnx = bx;
		int rny = ry;
		int rnx = rx;

		if(bny == rny && (i==0 || i ==1)){

			if(i==1){

				if(bnx > rnx){
					while(map[bny+dy[i]][bnx+dx[i]] == '.'){
						bny = bny+dy[i];
						bnx = bnx+dx[i];
					}
					if(map[bny+dy[i]][bnx+dx[i]] == 'O'){
						bny = bny+dy[i];
						bnx = bnx+dx[i];
					}
					while(map[rny+dy[i]][rnx+dx[i]] == '.' && rnx+dx[i] != bnx){
						rny = rny+dy[i];
						rnx = rnx+dx[i];
					}
					if(map[rny+dy[i]][rnx+dx[i]] == 'O'){
						rny = rny+dy[i];
						rnx = rnx+dx[i];
					}
				}
				else{
					while(map[rny+dy[i]][rnx+dx[i]] == '.'){
						rny = rny+dy[i];
						rnx = rnx+dx[i];
					}
					if(map[rny+dy[i]][rnx+dx[i]] == 'O'){
						rny = rny+dy[i];
						rnx = rnx+dx[i];
					}
					while(map[bny+dy[i]][bnx+dx[i]] == '.' && bnx+dx[i] != rnx){
						bny = bny+dy[i];
						bnx = bnx+dx[i];
					}
					if(map[bny+dy[i]][bnx+dx[i]] == 'O'){
						bny = bny+dy[i];
						bnx = bnx+dx[i];
					}
				}

			}
			else{
				if(bnx < rnx){
					while(map[bny+dy[i]][bnx+dx[i]] == '.'){
						bny = bny+dy[i];
						bnx = bnx+dx[i];
					}
					if(map[bny+dy[i]][bnx+dx[i]] == 'O'){
						bny = bny+dy[i];
						bnx = bnx+dx[i];
					}
					while(map[rny+dy[i]][rnx+dx[i]] == '.' && rnx+dx[i] != bnx){
						rny = rny+dy[i];
						rnx = rnx+dx[i];
					}
					if(map[rny+dy[i]][rnx+dx[i]] == 'O'){
						rny = rny+dy[i];
						rnx = rnx+dx[i];
					}
				}
				else{
					while(map[rny+dy[i]][rnx+dx[i]] == '.'){
						rny = rny+dy[i];
						rnx = rnx+dx[i];
					}
					if(map[rny+dy[i]][rnx+dx[i]] == 'O'){
						rny = rny+dy[i];
						rnx = rnx+dx[i];
					}
					while(map[bny+dy[i]][bnx+dx[i]] == '.' && bnx+dx[i] != rnx){
						bny = bny+dy[i];
						bnx = bnx+dx[i];
					}
					if(map[bny+dy[i]][bnx+dx[i]] == 'O'){
						bny = bny+dy[i];
						bnx = bnx+dx[i];
					}
				}
			}

		}

		else if(bnx == rnx && (i==2 || i==3)){
			
			if(i==3){

				if(bny > rny){
					while(map[bny+dy[i]][bnx+dx[i]] == '.'){
						bny = bny+dy[i];
						bnx = bnx+dx[i];
					}
					if(map[bny+dy[i]][bnx+dx[i]] == 'O'){
						bny = bny+dy[i];
						bnx = bnx+dx[i];
					}
					while(map[rny+dy[i]][rnx+dx[i]] == '.' && rny+dy[i] != bny){
						rny = rny+dy[i];
						rnx = rnx+dx[i];
					}
					if(map[rny+dy[i]][rnx+dx[i]] == 'O'){
						rny = rny+dy[i];
						rnx = rnx+dx[i];
					}
				}
				else{
					while(map[rny+dy[i]][rnx+dx[i]] == '.'){
						rny = rny+dy[i];
						rnx = rnx+dx[i];
					}
					if(map[rny+dy[i]][rnx+dx[i]] == 'O'){
						rny = rny+dy[i];
						rnx = rnx+dx[i];
					}
					while(map[bny+dy[i]][bnx+dx[i]] == '.' && bny+dy[i] != rny){
						bny = bny+dy[i];
						bnx = bnx+dx[i];
					}
					if(map[bny+dy[i]][bnx+dx[i]] == 'O'){
						bny = bny+dy[i];
						bnx = bnx+dx[i];
					}
				}

			}
			else{
				if(bny < rny){
					while(map[bny+dy[i]][bnx+dx[i]] == '.'){
						bny = bny+dy[i];
						bnx = bnx+dx[i];
					}
					if(map[bny+dy[i]][bnx+dx[i]] == 'O'){
						bny = bny+dy[i];
						bnx = bnx+dx[i];
					}
					while(map[rny+dy[i]][rnx+dx[i]] == '.' && rny+dy[i] != bny){
						rny = rny+dy[i];
						rnx = rnx+dx[i];
					}
					if(map[rny+dy[i]][rnx+dx[i]] == 'O'){
						rny = rny+dy[i];
						rnx = rnx+dx[i];
					}
				}
				else{
					while(map[rny+dy[i]][rnx+dx[i]] == '.'){
						rny = rny+dy[i];
						rnx = rnx+dx[i];
					}
					if(map[rny+dy[i]][rnx+dx[i]] == 'O'){
						rny = rny+dy[i];
						rnx = rnx+dx[i];
					}
					while(map[bny+dy[i]][bnx+dx[i]] == '.' && bny+dy[i] != rny){
						bny = bny+dy[i];
						bnx = bnx+dx[i];
					}
					if(map[bny+dy[i]][bnx+dx[i]] == 'O'){
						bny = bny+dy[i];
						bnx = bnx+dx[i];
					}
				}
			}



		}
		else{
			while(map[bny+dy[i]][bnx+dx[i]] == '.'){
				bny = bny+dy[i];
				bnx = bnx+dx[i];
			}
			if(map[bny+dy[i]][bnx+dx[i]] == 'O'){
				bny = bny+dy[i];
				bnx = bnx+dx[i];
			}
			while(map[rny+dy[i]][rnx+dx[i]] == '.'){
				rny = rny+dy[i];
				rnx = rnx+dx[i];
			}
			if(map[rny+dy[i]][rnx+dx[i]] == 'O'){
				rny = rny+dy[i];
				rnx = rnx+dx[i];
			}

		}

		find(k+1, bny, bnx, rny, rnx, i);
	}


}


int main(){
	cin >> n >> m;
	int B[2];
	int R[2];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> map[i][j];
			if(map[i][j] == 'B'){
				B[0] = i;
				B[1] = j;
				map[i][j] = '.';
			}
			if(map[i][j] == 'R'){
				R[0] = i;
				R[1] = j;
				map[i][j] = '.';
			}
			if(map[i][j] == 'O'){
				O[0] = i;
				O[1] = j;
			}
		}
	}

	find(0, B[0], B[1], R[0], R[1] , -1);

	if(ans == 99) ans = -1;
	cout << ans;
	return 0;
}

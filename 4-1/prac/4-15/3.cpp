#include <iostream>
#include <vector>

using namespace std;
int n;
int player[50][9];
int ans;
int wait[4];
int check[9];

vector<int> bat;

void move(int x){
	if(x==1){
		wait[3] = wait[2];
		wait[2] = wait[1];
		wait[1] = wait[0];
		wait[0] = 1;
	}
	else if(x==2){
		wait[3] = wait[1]+wait[2];
		wait[2] = wait[0];
		wait[1] = 1;
		wait[0] = 0;
	}
	else if(x==3){
		wait[3] = wait[0]+wait[1]+wait[2];
		wait[2] = 1;
		wait[1] = wait[0] = 0;
	}
	else if(x==4){
		wait[3] = wait[0]+wait[1]+wait[2]+1;
		wait[2] = wait[1] = wait[0] = 0;
	}

}

void find(int r, int sum, int k){

	if(k>=n){
		if(sum > ans) ans = sum;
		return;
	}

	int out=0;
	for(int j=0; j<4; j++) wait[j] = 0;

	while(out<3){
		if(r>8) r = 0;
		if(player[k][bat[r]]==0){
			out++;
		}
		else{
			//cout << k << " " << r << " " << bat[r] << " " << out << " " << sum << endl;
			move(player[k][bat[r]]);
			if(wait[3]){
				sum += wait[3];
				wait[3] = 0;
			}
		}
		r++;
	}

	find(r,sum,k+1);

}

void back(int k){
	if(k==9){
		if(bat[3] == 0) find(0,0,0);
		return;
	}
	for(int i=0; i<9; i++){
		//cout << i << " " << check[i] << endl;
		if(check[i]) continue;
		bat.push_back(i);
		check[i] = 1;
		back(k+1);
		check[i] = 0;
		bat.pop_back();
	}

}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<9; j++) cin >> player[i][j];
	}
	back(0);
	cout << ans;
	return 0;
}

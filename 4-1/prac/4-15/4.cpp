#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int A[55][55];
int rotate[6][3];

vector<int> order;

int ans=9999;
int check[6];

void move(int temp[55][55], int y1, int x1, int y2, int x2, int k){
	for(int t=0; t<k; t++){
		int s=temp[y1+t][x1+t];
		for(int i=y1+t; i<y2-t; i++){
			temp[i][x1+t] = temp[i+1][x1+t];
		}
		for(int i=x1+t; i<x2-t; i++){
			temp[y2-t][i] = temp[y2-t][i+1];
		}
		for(int i=y2-t; i>y1+t; i--){
			temp[i][x2-t] = temp[i-1][x2-t];
		}
		for(int i=x2-t; i>x1+t+1; i--){
			temp[y1+t][i] = temp[y1+t][i-1];
		}
		temp[y1+t][x1+t+1]=s;

	}

}

void find(){
	int temp[55][55];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			temp[i][j] = A[i][j];
		}
	}
	for(int i=0; i<k; i++){
		int y1 = rotate[order[i]][0] - rotate[order[i]][2]-1;
		int x1 = rotate[order[i]][1] - rotate[order[i]][2]-1;
		int y2 = rotate[order[i]][0] + rotate[order[i]][2]-1;
		int x2 = rotate[order[i]][1] + rotate[order[i]][2]-1;
		move(temp,y1,x1,y2,x2, rotate[order[i]][2]);
	}
		/*cout << endl;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++) cout << temp[i][j] << " ";
			cout << endl;
		}
		cout << endl;
*/

	
	int sum=0;
	int mini=9999;
	for(int i=0; i<n; i++){
		sum = 0;
		for(int j=0; j<m; j++) sum += temp[i][j];
		if(mini > sum) mini = sum;
	}

	
	if(ans > mini) ans = mini;
}

void play(int t){
	if(k==t){
		find();
		return;
	}

	for(int i=0; i<k; i++){
		if(check[i]) continue;
		order.push_back(i);
		check[i] = 1;
		play(t+1);
		check[i] = 0;
		order.pop_back();
	}

}



int main(){
	cin >> n >> m >> k;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> A[i][j];
		}
	}
	for(int i=0; i<k; i++){
		cin >> rotate[i][0] >> rotate[i][1] >> rotate[i][2];
	}
	play(0);
	cout << ans;

	return 0;
}

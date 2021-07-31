#include <iostream>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

int n, l, r;

int a[55][55];	


int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int visit[55][55];


void line(int idy, int idx) {
	vector<pair<int, int>> v;
	queue<pair<int, int>> q;
	v.push_back({ idy,idx });
	q.push({ idy,idx });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		//cout << y << " " << x << endl;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (visit[ny][nx]) continue;
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			int t = abs(a[ny][nx] - a[y][x]);
			if (t >= l && t <= r) {
				visit[ny][nx] = 1;
				v.push_back({ ny,nx });
				q.push({ ny,nx });
			}
		}
	}
	int sum = 0;
	for (int k = 0; k < v.size(); k++) {
		sum += a[v[k].first][v[k].second];
	}
	sum = sum / v.size();
	for (int k = 0; k < v.size(); k++) {
		a[v[k].first][v[k].second] = sum;
	}

}

int need() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			int t = abs(a[i][j] - a[i + 1][j]);
			if (t >= l && t <= r) return 1; 
			t = abs(a[i][j] - a[i][j + 1]);
			if (t >= l && t <= r) return 1;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		int t = abs(a[n-1][i] - a[n-1][i+1]);
		if (t >= l && t <= r) return 1;
	}
	for (int i = 0; i < n - 1; i++) {
		int t = abs(a[i][n-1] - a[i][n-1]);
		if (t >= l && t <= r) return 1;
	}
	return 0;
}


int main() {

	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> a[i][j];
	}

	int k = 0;

	while (k < 2000) {

		if (need() == 0) break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j]) continue;
				visit[i][j] = 1;
				line(i, j);
			}
		}


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visit[i][j] = 0;
			}
		}

		k++;

	}


	cout << k;
	return 0;
}
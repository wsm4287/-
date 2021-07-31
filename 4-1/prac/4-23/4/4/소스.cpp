#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, K;
int a[11][11];
vector <int> tree[11][11];
int ans;
int map[11][11];

int dx[] = { -1,0,1,-1,1,-1,0,1 };
int dy[] = { -1, -1,-1,0,0,1,1,1 };

void run(int k) {

	if (k == K) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans += tree[i][j].size();
			}
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tree[i][j].size() == 0) continue;
			sort(tree[i][j].begin(), tree[i][j].end());
			vector <int> temp;
			int d = 0;
			for (int k = 0; k < tree[i][j].size(); k++) {
				int age = tree[i][j][k];
				if (map[i][j] >= age) {
					map[i][j] = map[i][j] - age;
					temp.push_back(age+1);
				}
				else {
					d += age / 2;
				}
			}
			tree[i][j].clear();
			for (int k = 0; k < temp.size(); k++) tree[i][j].push_back(temp[k]);
			map[i][j] += d;
		}

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tree[i][j].size() == 0) continue;
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (tree[i][j][k] % 5) continue;
				if (tree[i][j][k]) {
					for (int q = 0; q < 8; q++) {
						int ny = i + dy[q];
						int nx = j + dx[q];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						tree[ny][nx].push_back(1);
					}
				}

			}
		}

	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] += a[i][j];
		}
	}
	run(k + 1);
}

int main() {
	cin >> n >> m >> K;
	int q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			map[i][j] = 5;
		}
	}
	int x, y, z;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		tree[x - 1][y - 1].push_back(z);
	}
	run(0);
	cout << ans;
	return 0;
}

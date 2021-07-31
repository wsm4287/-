#include <iostream>
#include <vector>

using namespace std;

int n, m;
int map[55][55];
int ans = 99999999;

vector <pair<int, int>> ch;
vector <pair<int, int>> h;

int dis(int x1, int x2, int y1, int y2) {
	int x, y;
	if (x1 > x2) x = x1 - x2;
	else x = x2 - x1;
	if (y1 > y2) y = y1 - y2;
	else y = y2 - y1;
	return x + y;
}


int move(int y, int x) {
	int d = 99;
	for (int i = 0; i < n; i++) {
		if (d == 1) break;
		for (int j = 0; j < n; j++) {
			if (d == 1) break;
			if (map[i][j] == 2) {
				if (d > dis(x, j, y, i)) d = dis(x, j, y, i);
			}
		}
	}
	return d;
}

int cal() {
	int sum = 0;
	for (int i = 0; i < h.size(); i++) {
		sum += move(h[i].first, h[i].second);
	}
	return sum;

}

void find(int k , int idx) {
	if (k == m) {
		int x = cal();
		if (ans > x) ans = x;
		return;
	}

	for (int i = idx; i < ch.size(); i++) {
		map[ch[i].first][ch[i].second] = 2;
		find(k + 1, i+1);
		map[ch[i].first][ch[i].second] = 0;
	}



}

int main() {
	cin >> n >> m;
	int a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;
			if (a == 1) h.push_back({ i,j });
			if (a == 2) ch.push_back({ i,j });
		}
	}
	find(0,0);
	cout << ans;
	return 0;
}
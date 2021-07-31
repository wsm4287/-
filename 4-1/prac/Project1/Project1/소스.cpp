#include <iostream>

using namespace std;

int n, m, d;
int map[20][20];
int temp[20][20];
int ans;

int dis(int x1, int x2, int y1, int y2) {
	int x, y;
	if (x1 > x2) x = x1 - x2;
	else x = x2 - x1;
	if (y1 > y2) y = y1 - y2;
	else y = y2 - y1;
	return x + y;
}

void find(int x1, int x2, int x3) {
	int sum = 0;
	int ypos = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << temp[i][j] << ' ';
		}
		cout << endl;
	}

	while (ypos < n-1) {
		int min1[3] = { 99, 99,99 };
		int min2[3] = { 99, 99,99 };
		int min3[3] = { 99, 99,99 };
		for (int i = ypos+1; i < ypos+1+d; i++) {
			for (int j = 0; j < m; j++) {
				if (temp[i][j]) {
					if (dis(x1, j, ypos, i) <= d) {
						if (dis(x1, j, ypos, i) < min1[0]) {
							min1[0] = dis(x1, j, ypos, i);
							min1[1] = j;
							min1[2] = i;
						}
						else if ((dis(x1, j, ypos, i) == min1[0]) && (j < min1[1])) {
							min1[1] = j;
							min1[2] = i;
						}
					}
					if (dis(x2, j, ypos, i) <= d) {
						if (dis(x2, j, ypos, i) < min2[0]) {
							min2[0] = dis(x2, j, ypos, i);
							min2[1] = j;
							min2[2] = i;
						}
						else if ((dis(x2, j, ypos, i) == min2[0]) && (j < min2[1])) {
							min2[1] = j;
							min2[2] = i;
						}
					}
					if (dis(x3, j, ypos, i) <= d) {
						if (dis(x3, j, ypos, i) <min3[0]) {
							min3[0] = dis(x3, j, ypos, i);
							min3[1] = j;
							min3[2] = i;
						}
						else if ((dis(x3, j, ypos, i) == min3[0])&& (j < min3[1])) {
							min3[1] = j;
							min3[2] = i;
						}
					}

				}
			}
		}



		if (min1[0] != 99) {
			if (temp[min1[2]][min1[1]]) {
				temp[min1[2]][min1[1]] = 0;
				sum++;
			}
		}
		if (min2[0] != 99) {
			if (temp[min2[2]][min2[1]]) {
				temp[min2[2]][min2[1]] = 0;
				sum++;
			}
		}
		if (min3[0] != 99) {
			if (temp[min3[2]][min3[1]]) {
				temp[min3[2]][min3[1]] = 0;
				sum++;
			}
		}

		cout << endl;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << temp[i][j] << ' ';
			}
			cout << endl;
		}
		ypos++;

	}

	if (sum > ans) ans = sum;
	
}

int main() {
	cin >> n >> m >> d;
	for (int i = n-1; i >=0; i--) {
		for (int j = 0; j < m; j++) cin >> map[i][j];
	}

	for (int i = 0; i < m; i++) {
		for (int j = i+1; j < m; j++) {
			for (int k = j + 1; k < m; k++)
				find(i, j, k);
		}
	}
	cout << ans;
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int t, n;

int map[6][3][3];

vector <pair<char, char>> r;

void find(int k) {
	if (k == n) {
		return;
	}
	if (r[k].first == 'L') {
		if (r[k].second == '+') {
			int temp[3];
			for (int i = 0; i < 3; i++) {
				temp[i] = map[0][i][0];
			}
			for (int i = 0; i < 3; i++) {
				map[0][i][0] = map[3][i][0];
			}
			for (int i = 0; i < 3; i++) {
				map[3][i][0] = map[1][i][0];
			}
			for (int i = 0; i < 3; i++) {
				map[1][i][0] = map[2][i][0];
			}
			for (int i = 0; i < 3; i++) {
				map[2][i][0] = temp[i];
			}
			int z = map[4][0][0];
			map[4][0][0] = map[4][2][0];
			map[4][2][0] = map[4][2][2];
			map[4][2][2] = map[4][0][2];
			map[4][0][2] = z;
			z = map[4][0][1];
			map[4][0][1] = map[4][1][0];
			map[4][1][0] = map[4][2][1];
			map[4][2][1] = map[4][1][2];
			map[4][1][2] = z;
		}
		else {
			int temp[3];
			for (int i = 0; i < 3; i++) {
				temp[i] = map[0][i][0];
			}
			for (int i = 0; i < 3; i++) {
				map[0][i][0] = map[2][i][0];
			}
			for (int i = 0; i < 3; i++) {
				map[2][i][0] = map[1][i][0];
			}
			for (int i = 0; i < 3; i++) {
				map[1][i][0] = map[3][i][0];
			}
			for (int i = 0; i < 3; i++) {
				map[3][i][0] = temp[i];
			}
			int z = map[4][0][0];
			map[4][0][0] = map[4][0][2];
			map[4][0][2] = map[4][2][2];
			map[4][2][2] = map[4][2][0];
			map[4][2][0] = z;
			z = map[4][0][1];
			map[4][0][1] = map[4][1][2];
			map[4][1][2] = map[4][2][1];
			map[4][2][1] = map[4][1][0];
			map[4][1][0] = z;
		}
	}
	if (r[k].first == 'R') {
		if (r[k].second == '+') {
			int temp[3];
			for (int i = 0; i < 3; i++) {
				temp[i] = map[0][i][2];
			}
			for (int i = 0; i < 3; i++) {
				map[0][i][2] = map[2][i][2];
			}
			for (int i = 0; i < 3; i++) {
				map[2][i][2] = map[1][i][2];
			}
			for (int i = 0; i < 3; i++) {
				map[1][i][2] = map[3][i][2];
			}
			for (int i = 0; i < 3; i++) {
				map[3][i][2] = temp[i];
			}
			int z = map[5][0][0];
			map[5][0][0] = map[5][2][0];
			map[5][2][0] = map[5][2][2];
			map[5][2][2] = map[5][0][2];
			map[5][0][2] = z;
			z = map[5][0][1];
			map[5][0][1] = map[5][1][0];
			map[5][1][0] = map[5][2][1];
			map[5][2][1] = map[5][1][2];
			map[5][1][2] = z;
		}
		else {
			int temp[3];
			for (int i = 0; i < 3; i++) {
				temp[i] = map[0][i][2];
			}
			for (int i = 0; i < 3; i++) {
				map[0][i][2] = map[3][i][2];
			}
			for (int i = 0; i < 3; i++) {
				map[3][i][2] = map[1][i][2];
			}
			for (int i = 0; i < 3; i++) {
				map[1][i][2] = map[2][i][2];
			}
			for (int i = 0; i < 3; i++) {
				map[2][i][2] = temp[i];
			}
			int z = map[5][0][0];
			map[5][0][0] = map[5][0][2];
			map[5][0][2] = map[5][2][2];
			map[5][2][2] = map[5][2][0];
			map[5][2][0] = z;
			z = map[5][0][1];
			map[5][0][1] = map[5][1][2];
			map[5][1][2] = map[5][2][1];
			map[5][2][1] = map[5][1][0];
			map[5][1][0] = z;
		}
	}
	if (r[k].first == 'U') {
		if (r[k].second == '+') {
			int temp[3];
			for (int i = 0; i < 3; i++) {
				temp[i] = map[2][0][i];
			}
			for (int i = 0; i < 3; i++) {
				map[2][0][i] = map[5][2-i][0];
			}
			for (int i = 0; i < 3; i++) {
				map[5][2-i][0] = map[3][2][2-i];
			}
			for (int i = 0; i < 3; i++) {
				map[3][2][2-i] = map[4][i][2];
			}
			for (int i = 0; i < 3; i++) {
				map[4][i][2] = temp[i];
			}
			int z = map[0][0][0];
			map[0][0][0] = map[0][2][0];
			map[0][2][0] = map[0][2][2];
			map[0][2][2] = map[0][0][2];
			map[0][0][2] = z;
			z = map[0][0][1];
			map[0][0][1] = map[0][1][0];
			map[0][1][0] = map[0][2][1];
			map[0][2][1] = map[0][1][2];
			map[0][1][2] = z;
		}
		else {
			int temp[3];
			for (int i = 0; i < 3; i++) {
				temp[i] = map[2][0][i];
			}
			for (int i = 0; i < 3; i++) {
				map[2][0][i] = map[4][i][2];
			}
			for (int i = 0; i < 3; i++) {
				map[4][i][2] = map[3][2][2-i];
			}
			for (int i = 0; i < 3; i++) {
				map[3][2][2-i] = map[5][2-i][0];
			}
			for (int i = 0; i < 3; i++) {
				map[5][2-i][0] = temp[i];
			}
			int z = map[0][0][0];
			map[0][0][0] = map[0][0][2];
			map[0][0][2] = map[0][2][2];
			map[0][2][2] = map[0][2][0];
			map[0][2][0] = z;
			z = map[0][0][1];
			map[0][0][1] = map[0][1][2];
			map[0][1][2] = map[0][2][1];
			map[0][2][1] = map[0][1][0];
			map[0][1][0] = z;
		}
	}
	if (r[k].first == 'D') {
		if (r[k].second == '+') {
			int temp[3];
			for (int i = 0; i < 3; i++) {
				temp[i] = map[2][2][i];
			}
			for (int i = 0; i < 3; i++) {
				map[2][2][i] = map[4][i][0];
			}
			for (int i = 0; i < 3; i++) {
				map[4][i][0] = map[3][0][2-i];
			}
			for (int i = 0; i < 3; i++) {
				map[3][0][2-i] = map[5][2-i][2];
			}
			for (int i = 0; i < 3; i++) {
				map[5][2-i][2] = temp[i];
			}
			int z = map[1][0][0];
			map[1][0][0] = map[1][2][0];
			map[1][2][0] = map[1][2][2];
			map[1][2][2] = map[1][0][2];
			map[1][0][2] = z;
			z = map[1][0][1];
			map[1][0][1] = map[1][1][0];
			map[1][1][0] = map[1][2][1];
			map[1][2][1] = map[1][1][2];
			map[1][1][2] = z;
		}
		else {
			int temp[3];
			for (int i = 0; i < 3; i++) {
				temp[i] = map[2][2][i];
			}
			for (int i = 0; i < 3; i++) {
				map[2][2][i] = map[5][2-i][2];
			}
			for (int i = 0; i < 3; i++) {
				map[5][2-i][2] = map[3][0][2-i];
			}
			for (int i = 0; i < 3; i++) {
				map[3][0][2-i] = map[4][i][0];
			}
			for (int i = 0; i < 3; i++) {
				map[4][i][0] = temp[i];
			}
			int z = map[1][0][0];
			map[1][0][0] = map[1][0][2];
			map[1][0][2] = map[1][2][2];
			map[1][2][2] = map[1][2][0];
			map[1][2][0] = z;
			z = map[1][0][1];
			map[1][0][1] = map[1][1][2];
			map[1][1][2] = map[1][2][1];
			map[1][2][1] = map[1][1][0];
			map[1][1][0] = z;
		}
	}
	
	if (r[k].first == 'F') {
		if (r[k].second == '+') {
			int temp[3];
			for (int i = 0; i < 3; i++) {
				temp[i] = map[0][2][i];
			}
			for (int i = 0; i < 3; i++) {
				map[0][2][i] = map[4][2][i];
			}
			for (int i = 0; i < 3; i++) {
				map[4][2][i] = map[1][0][2-i];
			}
			for (int i = 0; i < 3; i++) {
				map[1][0][2-i] = map[5][2][i];
			}
			for (int i = 0; i < 3; i++) {
				map[5][2][i] = temp[i];
			}
			int z = map[2][0][0];
			map[2][0][0] = map[2][2][0];
			map[2][2][0] = map[2][2][2];
			map[2][2][2] = map[2][0][2];
			map[2][0][2] = z;
			z = map[2][0][1];
			map[2][0][1] = map[2][1][0];
			map[2][1][0] = map[2][2][1];
			map[2][2][1] = map[2][1][2];
			map[2][1][2] = z;

		}
		else {
			int temp[3];
			for (int i = 0; i < 3; i++) {
				temp[i] = map[0][2][i];
			}
			for (int i = 0; i < 3; i++) {
				map[0][2][i] = map[5][2][i];
			}
			for (int i = 0; i < 3; i++) {
				map[5][2][i] = map[1][0][2-i];
			}
			for (int i = 0; i < 3; i++) {
				map[1][0][2-i] = map[4][2][i];
			}
			for (int i = 0; i < 3; i++) {
				map[4][2][i] = temp[i];
			}
			int z = map[2][0][0];
			map[2][0][0] = map[2][0][2];
			map[2][0][2] = map[2][2][2];
			map[2][2][2] = map[2][2][0];
			map[2][2][0] = z;
			z = map[2][0][1];
			map[2][0][1] = map[2][1][2];
			map[2][1][2] = map[2][2][1];
			map[2][2][1] = map[2][1][0];
			map[2][1][0] = z;
		}
	}
	if (r[k].first == 'B') {
		if (r[k].second == '+') {
			int temp[3];
			for (int i = 0; i < 3; i++) {
				temp[i] = map[0][0][i];
			}
			for (int i = 0; i < 3; i++) {
				map[0][0][i] = map[5][0][i];
			}
			for (int i = 0; i < 3; i++) {
				map[5][0][i] = map[1][2][2-i];
			}
			for (int i = 0; i < 3; i++) {
				map[1][2][2-i] = map[4][0][i];
			}
			for (int i = 0; i < 3; i++) {
				map[4][0][i] = temp[i];
			}
			int z = map[3][0][0];
			map[3][0][0] = map[3][2][0];
			map[3][2][0] = map[3][2][2];
			map[3][2][2] = map[3][0][2];
			map[3][0][2] = z;
			z = map[3][0][1];
			map[3][0][1] = map[3][1][0];
			map[3][1][0] = map[3][2][1];
			map[3][2][1] = map[3][1][2];
			map[3][1][2] = z;

		}
		else {
			int temp[3];
			for (int i = 0; i < 3; i++) {
				temp[i] = map[0][0][i];
			}
			for (int i = 0; i < 3; i++) {
				map[0][0][i] = map[4][0][i];
			}
			for (int i = 0; i < 3; i++) {
				map[4][0][i] = map[1][2][2-i];
			}
			for (int i = 0; i < 3; i++) {
				map[1][2][2-i] = map[5][0][i];
			}
			for (int i = 0; i < 3; i++) {
				map[5][0][i] = temp[i];
			}
			int z = map[3][0][0];
			map[3][0][0] = map[3][0][2];
			map[3][0][2] = map[3][2][2];
			map[3][2][2] = map[3][2][0];
			map[3][2][0] = z;
			z = map[3][0][1];
			map[3][0][1] = map[3][1][2];
			map[3][1][2] = map[3][2][1];
			map[3][2][1] = map[3][1][0];
			map[3][1][0] = z;
		}
	}


	find(k + 1);
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {

		for (int l = 0; l < 6; l++) {
			for (int q = 0; q < 3; q++) {
				for (int p = 0; p < 3; p++) map[l][q][p] = l+1; //0 -> w 1-> y 2 -> r 3->o  4->g  5->b
			}
		}

		cin >> n;
		char a, b;
		for (int j = 0; j < n; j++) {
			cin >> a >> b;
			r.push_back({ a, b });
		}
		find(0);
		for (int q = 0; q < 3; q++) {
			for (int p = 0; p < 3; p++) {
				int x = map[0][q][p];
				if (x == 1) cout << 'w';
				if (x == 2) cout << 'y';
				if (x == 3) cout << 'r';
				if (x == 4) cout << 'o';
				if (x == 5) cout << 'g';
				if (x == 6) cout << 'b';
			}
			cout << endl;
		}
		r.clear();
	}

	return 0;
}

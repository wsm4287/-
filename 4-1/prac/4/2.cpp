#include <stdio.h>
#include <algorithm>
using namespace std;
 
struct Worm {
    int x, y, data;
    Worm() { x = 0, y = 0, data = 0; }
    Worm(int x,int y,int d):x(x),y(y), data(d) {}
};
 
int t, n, res;
int map[100][100];
Worm worm[10];
int wormIdx;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
 
//0상, 1하, 2좌, 3우
int run(int x, int y, int dir) {
    int cnt = 0;
    int sx = x;
    int sy = y;
    int ax = x + dx[dir];
    int ay = y + dy[dir];
    int d = dir;
 
    while (true) {
        //printf("(%d, %d) %d\n", ax, ay, d);
        //벽에 부딪힌 경우
        if (ax < 0 || ay < 0 || ax >= n || ay >= n) {
            int odir;
            if (d == 0) odir = 1;
            else if (d == 1) odir = 0;
            else if (d == 2) odir = 3;
            else odir = 2;
 
            ax = ax + dx[odir];
            ay = ay + dy[odir];
            d = odir;
            cnt++;
            continue;
        }
 
        //종료
        if (map[ax][ay] == -1 || (ax == sx && ay == sy)) {
            return cnt;
        }
 
        //빈칸인 경우
        if (map[ax][ay] == 0) {
            ax = ax + dx[d];
            ay = ay + dy[d];
        }
 
        //블록인 경우
        else if (1 <= map[ax][ay] && map[ax][ay] <= 5) {
            int odir;
            if (map[ax][ay] == 1) {
                if (d == 0) odir = 1;
                else if (d == 1) odir = 3;
                else if (d == 2) odir = 0;
                else odir = 2;
            }
            else if (map[ax][ay] == 2) {
                if (d == 0) odir = 3;
                else if (d == 1) odir = 0;
                else if (d == 2) odir = 1;
                else odir = 2;
            }
            else if (map[ax][ay] == 3) {
                if (d == 0) odir = 2;
                else if (d == 1) odir = 0;
                else if (d == 2) odir = 3;
                else odir = 1;
            }
            else if (map[ax][ay] == 4) {
                if (d == 0) odir = 1;
                else if (d == 1) odir = 2;
                else if (d == 2) odir = 3;
                else odir = 0;
            }
            else {
                if (d == 0) odir = 1;
                else if (d == 1) odir = 0;
                else if (d == 2) odir = 3;
                else odir = 2;
            }
 
            ax = ax + dx[odir];
            ay = ay + dy[odir];
            d = odir;
            cnt++;
        }
        //웜홀인 경우
        else if (6 <= map[ax][ay] && map[ax][ay] <= 10) {
            for (int i = 0; i < wormIdx; i++) {
                if (map[ax][ay] == worm[i].data) {
                    if (worm[i].x != ax || worm[i].y != ay) {
                        ax = worm[i].x + dx[d];
                        ay = worm[i].y + dy[d];
                        break;
                    }
                }
            }
        }
    }
}
 
int main() {
    scanf("%d", &t);
 
    for (int tc = 1; tc <= t; tc++) {
        scanf("%d", &n);
 
        wormIdx = 0;
        res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &map[i][j]);
                if (6 <= map[i][j] && map[i][j] <= 10) {
                    Worm w(i, j, map[i][j]);
                    worm[wormIdx++] = w;
                }
            }
        }
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        //printf("(%d, %d) 에서 %d 방향\n", i, j, k);
                        res = max(run(i, j, k), res);
                    }
                }
            }
        }
 
        printf("#%d %d\n", tc, res);
    }
}
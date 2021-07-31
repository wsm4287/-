#include <stdio.h>

int a[30][30];
int N;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int cnt;
int b[900];
int ans;

void FF(int y, int x) {
    a[y][x] = 0;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx <0 || ny <0 || nx > N - 1 || ny > N - 1) continue;
        if (a[ny][nx] == 1) FF(ny, nx);
    }
}
int main(void) {
    int i, j;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (a[i][j] == 1) {
                cnt = 0;
                FF(i, j);
                b[ans++] = cnt;
            }

        }

    }

    printf("%d\n", ans);

    for (i = 0; i < ans - 1; i++) {
        for (j = i + 1; j < ans; j++) {
            if (b[i] > b[j]) {
                int temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    for (i = 0; i < ans; i++) printf("%d\n", b[i]);
    return 0;
}
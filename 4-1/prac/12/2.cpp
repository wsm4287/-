//점심 식사시간
//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N;
int board[10][10] = { 0, };
vector<pair<int, int>> people;
vector<pair<int, int>> stair;
int s[10];
int ans;
int siz;
int calc() {
    int t = 0;
    int chk = 0;
    int d[10];
    queue<int> c[2];

    for (int i = 0; i < people.size(); i++) {
        d[i] = abs(people[i].first - stair[s[i]].first) + abs(people[i].second - stair[s[i]].second);
    }

    while (true) {
        if (t >= ans) return t;

        if (chk == siz) return t;

        for (int i = 0; i < 2; i++) {//계단에 들어간 인원
		cout << c[i].size() << endl;
            for (int j = 0; j < c[i].size(); j++) {
                int top = c[i].front();
                c[i].pop();
                top--;
                if (top != 0)
                    c[i].push(top);
                else{
                    chk++;
                }
            }
        }

        for (int i = 0; i < people.size(); i++) {//입구에 도착한 인원
            if (t == d[i]) {
                if(c[s[i]].size()<3)//계단 입구 도착시 아무도 없다면
                    c[s[i]].push(board[stair[s[i]].first][stair[s[i]].second]);
                else {
                    c[s[i]].push(board[stair[s[i]].first][stair[s[i]].second] + c[s[i]].front());
                }
            }
        }
        t++;

    }

}

void dfs(int cnt) {

    if (cnt == people.size()) {
        int tmp = calc();
        if (ans > tmp) ans = tmp;
        return;
    }

    s[cnt] = 0; dfs(cnt + 1);
    s[cnt] = 1; dfs(cnt + 1);

}

int main() {//모든 사람들이 계단을 내려가 이동이 완료되는 시간이 최소가 되는 경우
    //freopen("C:\\Users\\Yu\\Desktop\\sample_input.txt", "r", stdin);

    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++) {
        cin >> N;
        people.clear();
        stair.clear();
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) people.push_back({ i,j });
            else if (board[i][j] > 1) stair.push_back({ i,j });
        }
        siz = people.size();
        ans = 2e9;
        dfs(0);
        cout << "#" << test_case << ' ' << ans << '\n';

    }
    return 0;//정상종료
}

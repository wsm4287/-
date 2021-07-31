#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int N, M, ans;
bool check[11];
void dfs(int now, int len, vector<vector<int>> &v)
{
    if (len>ans)
    {
        ans = len;
    }
 
    check[now] = true;
 
    for (int i = 0; i<v[now].size(); i++)
    {
        int next = v[now][i];
        if (!check[next])
        {
            dfs(next, len + 1, v);
        }
    }
    check[now]=false;
}
int main()
{
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        ans = 0;
        cin >> N >> M;
        vector<vector<int>> v(N + 1);
        for (int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
 
        for (int i = 1; i <= N; i++)
        {
            memset(check, false, sizeof(check));
            dfs(i, 1, v);
        }
 
        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}

#include <cstdio>
#include <vector>

using namespace std;
#define MAX 505

int friends[MAX][MAX];
bool friendsList[MAX];
int numberofFriends[MAX];
int x;

void findFriends(int nodeNum,int x)
{
    for (int i = 0; i < numberofFriends[nodeNum]; i++)
    {
        int next = friends[nodeNum][i];
        friendsList[next] = true;
    }
    if(x==1)
	return ;
    else{
	x++;{
        for (int i = 0; i < numberofFriends[nodeNum]; i++)
        {
            int next = friends[nodeNum][i];
            findFriends(next,x);
        }
    }
    }
}

int main()
{
    int N, M;
    scanf("%d %d",&N,&M);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d",&a,&b);

        friends[a][numberofFriends[a]++]=b;
        friends[b][numberofFriends[b]++]=a;
    }

    findFriends(1,0);
    int cnt = 0;
    for (int i = 2; i <= N; i++)
        if (friendsList[i])
            cnt++;
    printf("%d",cnt);
    return 0;
}


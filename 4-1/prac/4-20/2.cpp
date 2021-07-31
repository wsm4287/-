#include <iostream>
#include <algorithm>
#include <vector>
#include <set> 
#include <queue>
#include <cstdlib>
 
using namespace std;

int sc[21][21];
bool check[21];
int n;
int ans=987654321;

void dfs(int pl, int cnt){
    if(cnt==(n/2)){
        vector<int> link,start;
        int sum_l=0,sum_s=0,sum=0;
        for(int i=1;i<=n;i++){
            if(check[i]) start.push_back(i);
            else link.push_back(i); 
        }
        for(int i=0;i<start.size()-1;i++){
            for(int j=i+1;j<start.size();j++){
                sum_l+=sc[link[i]][link[j]]+sc[link[j]][link[i]];
                sum_s+=sc[start[i]][start[j]]+sc[start[j]][start[i]];
            }
        }
        sum=abs(sum_l-sum_s);
        ans=min(sum,ans);
        return;
    }

    for(int i=pl+1;i<n;i++){
        if(check[i]==false){
            check[i]=true;
            dfs(i,cnt+1);
            check[i]=false;
        }
    }

}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>sc[i][j];
        }
    }
    dfs(0,0);
    cout<<ans<<"\n";
}

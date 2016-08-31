#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<stdlib.h>
#include <sstream>
#include<deque> //双端队列
#define mod 1000000007
#define ll long long
#define LL long long
#define inf 10000000000000
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e18
using namespace std;

int col[105];
ll cost[105][105];
ll dp[105][105][105];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        cin>>col[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>cost[i][j];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++)
            for(int a=0;a<=m;a++)
                dp[i][j][a]=INF;   //求min 初始化inf
    if(col[1]==0)
    for(int i=1;i<=m;i++)
        dp[1][1][i]=cost[1][i];//初始化  n=1;
    else dp[1][1][col[1]]=0;
    for(int i=2;i<=n;i++)     //从2 到 n dp
        for(int j=1;j<=k;j++)
        {
            if(col[i]==0)     //未涂色
            {
                for(int a=1;a<=m;a++)
                {
                    dp[i][j][a]=min(dp[i][j][a],dp[i-1][j][a]+cost[i][a]);
                    for(int b=1;b<=m;b++)
                        if(b!=a)
                            dp[i][j][a]=min(dp[i][j][a],dp[i-1][j-1][b]+cost[i][a]);

                }
            }
            else    //已涂色
            {
                int a=col[i];
                    dp[i][j][a]=min(dp[i][j][a],dp[i-1][j][a]);//先算与之前同色
                for(int b=1;b<=m;b++)  //不同色
                    if(b!=a)
                        dp[i][j][a]=min(dp[i][j][a],dp[i-1][j-1][b]);
            }
        }
    ll ans=INF;
    for(int i=1;i<=m;i++)
        ans=min(ans,dp[n][k][i]);
    if(ans>=INF) cout<<-1<<endl;
    else  cout<<ans<<endl;

    return 0;
}

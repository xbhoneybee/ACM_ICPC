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
#include <deque>
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;


int n,m,mp[17][17];
const int fullst=(1<<16)-1;
int dp[fullst][17];//dp[st][j]状态为st，最后一次走的是 j 点的最小值
void init()
{
    //Floyd初始化需要
    for(int i=0;i<17;i++)
        for(int j=0;j<17;j++)
            if(i!=j) mp[i][j]=inf;
    //dp初始化需要
    for(int i=0;i<=(1<<n)-1;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=inf;
    dp[1][1]=0;//设置起点为1

}
void floyd()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            if(mp[i][k]!=inf)
            for(int j=1;j<=n;j++)
            {
                if(mp[i][j]>mp[i][k]+mp[k][j])
                    mp[i][j]=mp[i][k]+mp[k][j];
            }
    return ;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       cin>>n>>m;
       init();
       for(int i=0;i<m;i++)
       {
        int u,v,w;
        cin>>u>>v>>w;
        mp[u][v]=mp[v][u]=min(mp[u][v],w);
       }
       if(n==1)
       {
           cout<<0<<endl;continue;
       }
       floyd();
       for(int st=2;st<=(1<<n)-1;st++)
       {
           for(int i=1;i<n;i++)
           {
               if(st&(1<<i))
               {
                int tmp=st-(1<<i);
                for(int j=1;j<=n;j++)
                    if(mp[j][i+1]!=inf)//防止无用操作，也防止爆int
                    {
                        dp[st][i+1]=min(dp[tmp][j]+mp[j][i+1],dp[st][i+1]);
                    }
               }
           }
       }
       int ans=inf;
       for(int i=1;i<=n;i++)
        ans=min(ans,dp[(1<<n)-1][i]+mp[i][1]);//走完最后一个加上一条边即表示来回
       cout<<ans<<endl;
   }

    return 0;
}

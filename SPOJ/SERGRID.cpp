#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<vector>
#include<map>
#include<sstream>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;
int n,m;
char mp[505][505];
int vis[505][505];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int ans=1e8;
void dfs(int x,int y,int step)
{
    int time=mp[x][y]-'0';
    if(x==n-1&&y==m-1)
        {
            ans=min(ans,step);
            return ;
        }
    if(mp[x][y]=='0')
    {
        return ;
    }
    if(vis[x][y]&&vis[x][y]<=step)
        return ;
    else vis[x][y]=step;
    for(int t=0;t<4;t++)
    {
        int tx=x+dx[t]*time;
        int ty=y+dy[t]*time;
        if(tx<0||tx>=n||ty<0||ty>=m)
        continue;
        dfs(tx,ty,step+1);
    }
}
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%s",mp[i]);
        dfs(0,0,0);
        if(ans==1e8)
            ans=-1;
        cout<<ans<<endl;
        ans=1e8;
        memset(vis,0,sizeof vis);
    }
    return 0;
}

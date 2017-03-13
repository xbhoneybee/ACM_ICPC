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

char mp[810][810];
int ans[810][810];
int vis[810][810];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m;
queue<pair<int,int> >que;
void SBFS()
{
    while(!que.empty())
    {
        pair<int,int> p=que.front();
        que.pop();
        for(int i=0;i<4;i++)
        {
            int tx=p.first+dx[i];
            int ty=p.second+dy[i];
            if(tx<0||tx>=n||ty<0||ty>=m)
                continue;
            if(mp[tx][ty]=='1'&&vis[tx][ty]==0)
            {
                que.push(make_pair(tx,ty));
                ans[tx][ty]=ans[p.first][p.second]+1;
                vis[tx][ty]=1;
            }

        }
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",mp[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(mp[i][j]=='0')
        que.push(make_pair(i,j));
    SBFS();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(j)
            printf(" %d",ans[i][j]);
            else printf("%d",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}

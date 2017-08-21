//#include <bits/stdc++.h>
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
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);

using namespace std;


/**
枚举解法：
考虑1-16 个格子每个格子填0或1,为所有情况，之后按状态翻转判断是否成立即可。
下面是DFS代码 考虑每个格子翻转不超过1次，因此考虑每个格子翻转或不翻转，寻找解
*/
char mp[50][50];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int ans;
const int mmd=1e9+7;
bool check()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            if(mp[i][j]!=mp[0][0])
                return false;
    }
    return true;
}
void dfs(int cnt,int x,int y)
{
    if(check())
    {
        ans=min(ans,cnt);
        return;
    }
    if(x>=4)
        return ;
    if(y<3)
    dfs(cnt,x,y+1);
    else
    dfs(cnt,x+1,0);

    mp[x][y]=mp[x][y]=='b'?'w':'b';
    for(int t=0;t<4;t++)
    {
        int tx=x+dx[t];
        int ty=y+dy[t];
        if(tx<0||ty<0||tx>=4||ty>=4)
            continue;
        mp[tx][ty]=mp[tx][ty]=='b'?'w':'b';
    }
    if(y<3)
    dfs(cnt+1,x,y+1);
    else
    dfs(cnt+1,x+1,0);

    mp[x][y]=mp[x][y]=='b'?'w':'b';

    for(int t=0;t<4;t++)
    {
        int tx=x+dx[t];
        int ty=y+dy[t];
        if(tx<0||ty<0||tx>=4||ty>=4)
            continue;
        mp[tx][ty]=mp[tx][ty]=='b'?'w':'b';
    }
}
int main()
{
    {
        for(int i=0;i<4;i++)
            scanf("%s",mp[i]);
        ans=mmd;
        dfs(0,0,0);
        if(ans==mmd)
            printf("Impossible\n");
        else printf("%d\n",ans);
    }
    return 0;
}

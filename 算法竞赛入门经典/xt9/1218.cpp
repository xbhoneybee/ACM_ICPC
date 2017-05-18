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
#define lowbit(x) x&-x

using namespace std;


vector<int>son[10004];
int n;
int d[10004][3];
void init()
{
    memset(d,0,sizeof d);
    for(int i=0;i<=n;i++)
        son[i].clear();
}
void dp(int rt,int fa)
{
    d[rt][0]=1;
    d[rt][1]=0;
    d[rt][2]=n;
    for(int i=0;i<son[rt].size();i++)
    {
        if(son[rt][i]!=fa)
        {
        dp(son[rt][i],rt);
        d[rt][0]+=min(d[son[rt][i]][0],d[son[rt][i]][1]);
        d[rt][1]+=d[son[rt][i]][2];
        }
    }
    for(int i=0;i<son[rt].size();i++)
        if(son[rt][i]!=fa)
        d[rt][2]=min(d[rt][2],d[rt][1]-d[son[rt][i]][2]+d[son[rt][i]][0]);
}
int main()
{
    bool isfirst=true;
    while(scanf("%d",&n)&&n!=-1)
    {
        init();
        for(int i=1;i<n;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            son[a].push_back(b);
            son[b].push_back(a);
        }
        dp(1,0);
        int ans=min(d[1][0],d[1][2]);
        printf("%d\n",ans);
        if(isfirst)
        {
        int tmp;
        scanf("%d",&tmp);
        if(tmp==-1)
            break;
        }
    }
    return 0;
}

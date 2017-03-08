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

int ans,n,m;
int sumans[1005];
int mon[1005];
int summon[1024];
int pre[1024];
int findfater(int x)
{
    int r=x;
    while(pre[r]!=r)
        r=pre[r];
    int i=x,j;
    while(i!=r)//路径压缩（注意路径压缩后的并查集树深度不是1！！！）
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
void join(int x,int y)
{
    int fx=findfater(x),fy=findfater(y);
    if(fx==fy) return;
    pre[fy]=fx;
}
void initial()
{
    for(int i=1;i<=n;i++)
        pre[i]=i;
}
int cmp(int a,int b)
{
    return summon[a]<summon[b];
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int it=1;it<=t;it++)
    {
        scanf("%d %d",&n,&m);
        initial();
        for(int i=1;i<=n;i++)
            scanf("%d",&mon[i]);
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            join(u,v);
        }
        for(int i=1;i<=n;i++)
        {
            if(pre[i]==i)
                {
                    sumans[ans++]=i;
                    summon[i]+=mon[i];
                }
            else {
                int faa=findfater(i);
                summon[faa]+=mon[i];
            }
        }
        printf("Case %d: %d\n",it,ans);
        sort(sumans,sumans+ans,cmp);
        for(int j=0;j<ans-1;j++)
            printf("%d ",summon[sumans[j]]);
        printf("%d\n",summon[sumans[ans-1]]);
        ans=0;
        memset(sumans,0,sizeof sumans);
        memset(summon,0,sizeof summon);
    }
    return 0;
}

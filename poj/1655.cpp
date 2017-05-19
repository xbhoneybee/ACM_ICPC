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

//poj 1655


int t,n;
vector<int>son[20004];
int center[20004];
int d[20004];
int dp(int s,int f)
{
    int big=0;
    d[s]=1;
    for(int i=0;i<son[s].size();i++)
    {
        if(son[s][i]!=f)
        {
            big=max(big,dp(son[s][i],s));
            d[s]+=d[son[s][i]];
        }
    }
    big=max(big,n-d[s]);
    center[s]=big;
    return d[s];
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(d,0,sizeof d);
        memset(center,0,sizeof center);
        for(int i=0;i<=n;i++)
            son[i].clear();
        for(int i=1;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            son[a].push_back(b);
            son[b].push_back(a);
        }
        dp(1,0);
        int ans=n,point;
        for(int i=1;i<=n;i++)
        {
            if(center[i]<ans)
                {
                    ans=center[i];
                    point=i;
                }
        }
        printf("%d %d\n",point,ans);
    }
    return 0;
}

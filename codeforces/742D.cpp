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
#define ll long long
#define LL long long
#define inf 10000000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

int wet[2005],bea[2005];
int pre[1024];
int totw[1005],totb[1005];
vector<int> vec[1001];
int findfater(int x)
{
    int r=x;
    while(pre[r]!=r)
        r=pre[r];
    int i=x,j;
    while(i!=r)//路径压缩
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
void join(int x,int y)
{
    if(x>y) swap(x,y);
    int fx=findfater(x),fy=findfater(y);
    if(fx==fy) return;
    if(fy<fx)
    pre[fy]=fx;
    else pre[fx]=fy;
}
void initial(int n)
{
    for(int i=1;i<=n;i++)
        pre[i]=i;
}
int dp[1005];
int main()
{
    int n,M,W;
    cin>>n>>M>>W;
    initial(1005);
    for(int i=1;i<=n;i++)
        cin>>wet[i];
    for(int i=1;i<=n;i++)
        cin>>bea[i];
    for(int i=0;i<M;i++)
    {
        int x,y;
        cin>>x>>y;
        join(x,y);
    }
    for(int i=1;i<=n;i++)
    {
        int father=findfater(i);
        vec[father].push_back(i);
        totw[father]+=wet[i];
        totb[father]+=bea[i];
    }
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        if(totb[i]!=0&&totb[i]!=bea[i])
        {
            wet[n+cnt]=totw[i];
            bea[n+cnt]=totb[i];
            vec[i].push_back(n+cnt);
            cnt++;
        }
    }
    for(int k=1;k<=n;k++)
    {
        if(vec[k].size()==0)
            continue;
        for(int v=W;v>=0;v--)
            for(int i=0;i<vec[k].size();i++)
            if(v>=wet[vec[k][i]])
            dp[v]=max(dp[v],dp[v-wet[vec[k][i]]]+bea[vec[k][i]]);
    }
    cout<<dp[W]<<endl;
    return 0;
}

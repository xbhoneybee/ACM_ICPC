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
//SG函数与x之前状态有关 状压dp打表
int vis[100];
int SG[16][1<<16];
int mex(int now,int st)
{
    memset(vis,0,sizeof vis);
    for(int i=1;i<=now;i++)//取走i个
    {
        if(st&(1<<i))
            continue;
        vis[SG[now-i][st+(1<<i)]]=1;
    }
    for(int i=0;;i++)
        if(vis[i]==0)
        {
            SG[now][st]=i;
            break;
        }
}
void find_rule()
{
    SG[0][0]=0;
    SG[1][0]=1;
    for(int i=1;i<=15;i++)
        for(int j=(1<<15);j>=0;j--)
    {
        SG[i][j]=mex(i,j);
    }
    for(int i=0;i<=15;i++)
        cout<<i<<" SG "<<SG[i][0]<<endl;
}
int sg[70];
int main()
{
    //find_rule();
    int cnt=0,gap=1;
    for(int i=0;i<70;i++)
    {
        if(cnt<gap)
        {
            sg[i]=gap-1;
            cnt++;
        }else {
             sg[i]=gap++;
             cnt=1;
        }
       // cout<<i<<" sg "<<sg[i]<<endl;
    }
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        ans^=sg[tmp];
    }
    if(ans==0)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

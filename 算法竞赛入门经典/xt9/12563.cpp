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

int n,t;
int a[100];
int dp[180*50+11*60+20];
int main()
{
    iosfalse
    int T,cas=1;
    cin>>T;
    while(T--)
    {
        cin>>n>>t;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+1+n);
        memset(dp,0,sizeof dp);
        long long num_t=0;
        int num_s=0;
        for(int i=1;i<t;i++)//使dp[j]的含义变为必须装满j的容量时，最大数量歌曲
            dp[i]=-1e5;
        for(int i=1;i<=n;i++)
        {
            for(int j=t-1;j>=a[i];j--)
            {
                dp[j]=max(dp[j],dp[j-a[i]]+1);
                num_s=max(num_s,dp[j]);
            }
        }
        for(int j=t-1;j>=0;j--)
        {
           if(dp[j]==num_s)
           {
               num_t=j;
               break;
           }
        }
        num_t+=11*60+18;
        cout<<"Case "<<cas++<<": "<<num_s+1<<" "<<num_t<<endl;
    }
    return 0;
}

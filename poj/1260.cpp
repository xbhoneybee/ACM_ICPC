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


//可选，uva原题
int num[105],pri[105];
int dp[100005];
int ppv[105];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            {
                scanf("%d %d",&num[i],&pri[i]);
                ppv[i]=ppv[i-1]+num[i];
            }
        for(int i=1;i<=100000;i++)
            dp[i]=1e9;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            dp[ppv[i]]=min(dp[ppv[i]],dp[ppv[j]]+(ppv[i]-ppv[j]+10)*pri[i]);
        }
        cout<<dp[ppv[n]]<<endl;
    }
    return 0;
}

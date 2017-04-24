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

int mp[110][110];
int dp[110][110];
int main()
{
    iosfalse
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
            cin>>mp[i][j];
    }
    dp[0][0]=mp[0][0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0)
                dp[i][j]=mp[i][j]+dp[i-1][j];
            else if(j==i)
                dp[i][j]=mp[i][j]+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+mp[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,dp[n-1][i]);
    cout<<ans<<endl;
    return 0;
}

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

int n;
int a[400][400];
int dp[400][400];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
            cin>>a[i][j];
    }
    dp[0][0]=a[0][0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j)
            dp[i][j]=a[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
            else dp[i][j]=a[i][j]+dp[i-1][j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
            ans=max(ans,dp[n-1][i]);
    cout<<ans<<endl;
    return 0;
}

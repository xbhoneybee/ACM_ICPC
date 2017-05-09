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


int a[200];
int dp[110][110];
int main()
{
    iosfalse
    int n;
    cin>>n;//n-1 matrix
    for(int i=1;i<=n;i++)//第i个matrix的行列为a[i],a[i+1]
    {
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            dp[i][j]=1e9;
        }
    for(int len=2;len<=n-1;len++)//length
    {
        for(int i=1;i+len-1<n;i++)//start
        {
            for(int k=i;k<i+len-1;k++)
            {
                dp[i][i+len-1]=min(dp[i][k]+dp[k+1][i+len-1]+a[i]*a[k+1]*a[i+len],dp[i][i+len-1]);
            }
        }
    }
    cout<<dp[1][n-1]<<endl;
    return 0;
}

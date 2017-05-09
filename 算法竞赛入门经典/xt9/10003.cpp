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



//uva 10003
int a[100];
int dp[110][110];
int main()
{
    iosfalse
    int n,l;

    while(cin>>l&&l){
        cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    a[0]=0;
    a[n+1]=l;
    memset(dp,0,sizeof dp);
    for(int i=0;i+2<=n+1;i++)
    {
        for(int j=i+2;j<=n+1;j++)
            dp[i][j]=1e8;
    }
    for(int len=2;len<=n+1;len++)//length
    {
        for(int i=0;i+len<=n+1;i++)//start
        {
            for(int k=i+1;k<i+len;k++)
            {
                dp[i][i+len]=min(dp[i][k]+dp[k][i+len]+a[i+len]-a[i],dp[i][i+len]);
            }
        }
    }
    cout<<"The minimum cutting is "<<dp[0][n+1]<<"."<<endl;
    }
    return 0;
}

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


long long mmd=1e9+7;
long long dp[100005][2];//O->0  L->1
int main()
{
    int n;
    cin>>n;
    dp[0][0]=1;
    dp[0][1]=1;
    dp[1][0]=1;
    dp[1][1]=1;
    for(int i=2;i<=n;i++)
        for(int j=0;j<2;j++)
        {
            if(j==0)
                dp[i][j]=(dp[i-1][j]+dp[i-1][1])%mmd;
            else {
            dp[i][j]=(dp[i-1][j]+dp[i-1][0])%mmd;
            if(i-3>=0)
                dp[i][j]-=dp[i-3][0];
            dp[i][j]=(dp[i][j]+mmd)%mmd;
            }
        }
    long long ans=(dp[n][0]+dp[n][1])%mmd;
    for(int i=1;i<=n;i++)
       {
        long long l,r;
        l=(dp[i-1][0]+dp[i-1][1]);
        r=(dp[n-i][0]+dp[n-i][1]);
        if(i==1) l--;
        if(n-i==0) r--;
        ans=(l*r%mmd+ans)%mmd;
       }
    cout<<ans <<endl;
    return 0;
}

#include <bits/stdc++.h>
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
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

//hdu 1087
long long dp[1005];
int a[1005];
int main()
{
    int n;
    while(cin>>n){
        if(n==0)
        break;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++)
        {
            int k=0;
            for(int j=1;j<i;j++)
            {
                if(a[j]<a[i])
                {
                    if(dp[j]>dp[k])
                        k=j;
                }
            }
            dp[i]=dp[k]+a[i];
        }
        long long ans=dp[1];
        for(int i=2;i<=n;i++)
            ans=max(ans,dp[i]);
        cout<<ans<<endl;
    }
    return 0;
}

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
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x

using namespace std;


//cf ed19 B  dp

int n;
int a[100005];
int dp[100005][2];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dp[0][0]=-1000000001;
    dp[0][1]=-1000000000;
    for(int i=1;i<=n;i++)
    {
        if(a[i]&1)
        {
            dp[i][0]=max(dp[i-1][1]+a[i],max(dp[i-1][0],a[i]));
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]+a[i]);
        }else{
            dp[i][0]=max(dp[i-1][0]+a[i],dp[i-1][0]);
            dp[i][1]=max(max(dp[i-1][1]+a[i],a[i]),dp[i-1][1]);
        }
    }
    cout<<dp[n][0]<<endl;
    return 0;
}

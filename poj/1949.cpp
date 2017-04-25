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

//注意题意k的前驱只能是1~k-1,不用存图
int n;
int dp[10005];
int main()
{
    iosfalse;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int len;
        cin>>len;
        int n_p;
        cin>>n_p;
        if(n_p==0)
            {
                dp[i]=len;
            }
        for(int j=0;j<n_p;j++)
        {
            int prep;
            cin>>prep;
            dp[i]=max(dp[i],dp[prep]+len);
        }
    }
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}

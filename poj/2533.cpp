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

int a[1005];
int dp[1005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<=n;i++)//初始化啊啊啊啊啊
        dp[i]=1;
    for(int i=2;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(a[j]<a[i])
                    dp[i]=max(dp[i],dp[j]+1);
            }
        }
    int ans=1;
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i]);
    printf("%d\n",ans);
    return 0;
}

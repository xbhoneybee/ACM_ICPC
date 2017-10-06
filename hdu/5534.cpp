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

using namespace std;

const int inf=0x3f3fffff;
int f[2100];
int dp[2100];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n-1;i++)
            {
                scanf("%d",&f[i]);
                if(i>1)
                    f[i]-=f[1];
            }
        for(int i=1;i<=n-2;i++)//from 1!
            dp[i]=-inf;
        int V=n-2;
        for(int i=2;i<=n-1;i++){
            for(int j=i-1;j<=V;j++)
            dp[j]=max(dp[j],dp[j-i+1]+f[i]);
        }
        printf("%d\n",dp[n-2]+n*f[1]);
    }
    return 0;
}

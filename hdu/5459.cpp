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


//J

const long long mmd=530600414;
int T,n;
const int maxn=202314;
long long dp[maxn];
long long dL[maxn];
long long dR[maxn];
long long sizes[maxn];
long long lens[maxn];
int main()
{
    dp[1]=0;dp[2]=0;dp[3]=0;dp[4]=0;
    dL[1]=0;dL[2]=0;dL[3]=0;dL[4]=2;
    dR[1]=0;dR[2]=0;dR[3]=2;dR[4]=2;
    sizes[1]=1;sizes[2]=0;sizes[3]=1;sizes[4]=1;
    lens[1]=1;lens[2]=2;lens[3]=3;lens[4]=5;
    for(int i=5;i<=201314;i++)
    {
        dp[i]=(((dp[i-2]+dp[i-1])%mmd+dR[i-2]*sizes[i-1]%mmd)%mmd+dL[i-1]*sizes[i-2]%mmd)%mmd+sizes[i-1]*sizes[i-2]%mmd;
        dp[i]=dp[i]%mmd;
        dL[i]=((dL[i-2]+dL[i-1])%mmd+sizes[i-1]*lens[i-2]%mmd)%mmd;
        dR[i]=((dR[i-1]+dR[i-2])%mmd+sizes[i-2]*lens[i-1]%mmd)%mmd;
        sizes[i]=(sizes[i-1]+sizes[i-2])%mmd;
        lens[i]=(lens[i-1]+lens[i-2])%mmd;
    }
    scanf("%d",&T);
    int cas=1;
    while(T--)
    {
        scanf("%d",&n);
        printf("Case #%d: %I64d\n",cas++,dp[n]);
    }
    return 0;
}

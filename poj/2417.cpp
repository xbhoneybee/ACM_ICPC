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


using namespace std;

long long PowerMod(long long a, long long  b, long long c)
{
    long long ans = 1;
    a = a % c;
    while(b>0)
    {
    if(b&1)
    ans = (ans * a) % c;
    b = b>>1;
    a = (a * a) % c;
    }
    return ans;
}
map<long long ,int>mp;
long long discrete_log(long long x,long long n,long long m)
{
    //m 是质数
    long long C=ceil(sqrt(m));
    long long cur=n%m;
    for(int j=0;j<=C;j++)
    {
        mp[cur]=j;
        cur=cur*x%m;
    }
    long long tmp=PowerMod(x,C,m);
    cur=1;
    for(int i=1;i<=C;i++)
    {
        cur=cur*tmp%m;
        int t=mp[cur];
        if(t||cur==n%m)
        {
            return i*C-t;
        }
    }
    return -1;
}
int main()
{
    long long M,X,N,Y;//求Y
    while(scanf("%I64d %I64d %I64d",&M,&X,&N)!=EOF)
    {
        mp.clear();
        long long ans=discrete_log(X,N,M);
        if(ans==-1)
            printf("no solution\n");
        else printf("%I64d\n",ans);
    }
    return 0;
}

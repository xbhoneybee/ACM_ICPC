#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string.h>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#define inf 1000000000000000000
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
using namespace std;



// 组合数  预处理
const  int mod =1000003;
long long f[1000006];
ll PowerMod(ll a, ll b, ll c)
{
    ll ans = 1;
    a = a % c;
    while(b>0)
    {
    if(b % 2 == 1)
    ans = (ans * a) % c;
    b = b/2;
    a = (a * a) % c;
    }
    return ans;
}
long long Combination(long long n,long long m,long long mod)
{
    if(m==0) return 1;
    if(m>n) return 0;
    long long ans;
    /*      这样会超时 要预处理
    if(m>n-m) m=n-m;
    for(long long i=n;i>n-m;i--)
        ans=(ans*i)%mod;
    for(long long i=2;i<=m;i++)
       {ans*=PowerMod(i,mod-2,mod);ans%=mod;}
    */
    return ans=f[n]*PowerMod(f[m],mod-2,mod)*PowerMod(f[n-m],mod-2,mod)%mod;
}
void fact(long long n)
{
    f[0]=1;
    for(int i=1;i<n;i++)
        f[i]=f[i-1]*i%mod;
}
int main()
{
    int t,n,m,ans;
    scanf("%d",&t);
    fact(mod);
    for(int it=1;it<=t;it++)
    {
        scanf("%d%d",&n,&m);
        ans=Combination(n,m,mod);
        printf("Case %d: %d\n",it,ans);
    }
    return 0;
}
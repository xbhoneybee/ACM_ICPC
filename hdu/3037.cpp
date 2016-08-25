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
int Combination(ll n,ll m,ll p)
{
	ll a = 1,b = 1;
	if(m > n) return 0;
	while(m)
	{
		a = (a * n) % p;
		b = (b * m) % p;
		m--;
		n--;
	}
	return ((ll)a * (ll)PowerMod(b,p-2,p))%p;
}
ll lucas(ll n,ll m,ll mod)
{
    if(m==0) return 1;
    ll ans=Combination(n%mod,m%mod,mod)*lucas(n/mod,m/mod,mod)%mod;
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n,m,p;
        scanf("%I64d %I64d%I64d",&n,&m,&p);
        ll mn=m+n;
        ll ans= lucas(mn,m,p);
        printf("%I64d\n",ans);
    }
    return 0;
}

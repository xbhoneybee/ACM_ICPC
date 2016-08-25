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


ll oula(ll n)
{
    ll replaced=n;
    vector<ll> v;
    for(ll i=2;i<=n;i++)
    {
        if(n%i==0)
            v.push_back(i);
        while(n%i==0)
            n/=i;
    }
    if(n!=1) v.push_back(n);
    ll ans=replaced;
    ll number=v.size();
    for(ll i=0;i<number;i++)
        ans=ans/v[i]*(v[i]-1);
    return ans;
}
int main()
{
    ll n;
    while(scanf("%I64d",&n)&&n)
    {
        ll answer=oula(n);
        cout<<answer<<endl;
    }
    return 0;
}
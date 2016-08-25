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
#define mod 1000000007
#define iosfalse ios::sync_with_stdio(false);
using namespace std;
const int MAXN=1024;


ll gcd(ll x , ll y)
{
    if(!y)
    return x;
    else return gcd(y , x%y);
}
ll exgcd(ll a,ll b,ll &x,ll &y )
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    else {
        ll d=exgcd(b,a%b,x,y);
        ll tem=x;
        x=y;
        y=tem-a/b*y;
        return d;
    }
}
int main()
{
    ll x,y,m,n,L;
    cin>>x>>y>>m>>n>>L;
    ll gcdxy=gcd(n-m,L);
    if((x-y)%gcdxy!=0)
        cout<<"Impossible"<<endl;
    else{
        ll t,k;
        exgcd(n-m,L,t,k);
        ll dx=L/gcdxy;
        if(dx<0) dx=-dx;
        ll ans=t*(x-y)/gcdxy;
        ans=(ans%dx+dx)%dx;
        cout<<ans<<endl;
    }
    return 0;
}
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
    else return gcd(y,x%y);
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
    ll a,b,c,k;
    while(~scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&k))
    {
        if(a==0&&b==0&&c==0&&k==0)
            break;
        k=1LL<<k;
        ll gcdck=gcd(c,k);
        if((b-a)%gcdck!=0)
        {
            printf("FOREVER\n");
        }else{
        ll x,y;
        exgcd(c,k,x,y);
        x*=(b-a)/gcdck;
        y*=(b-a)/gcdck;
        ll dx=k/gcdck;
        if(dx<0) dx=-dx;
        printf("%I64d\n",(x%dx+dx)%dx); //×¢ÒâÐÞ¸Ädx>0;
        }
    }
    return 0;
}
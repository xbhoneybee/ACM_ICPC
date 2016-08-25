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



//代码的实现  学习一下
ll ans,n;
int check(ll x)
{
    if(x<2) return 0;
    ll tem=x;
    for(ll i=2;i*i<=x;i++) //i*i<=x
    {
        if(x%i==0)
        {
            if(x%(i*i)==0)
                return 0;
            x/=i;
        }
    }
    ans=min (ans,abs(tem*tem-n));
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        ll x=sqrt(n)+0.5; //+0.5很重要
        ans=inf;
        int flag=0;
        for(int i=0;;i++)
        {
            if(check(x+i))
                flag=1;
            if(check(x-i))
                flag=1;
            if(flag)
                break;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
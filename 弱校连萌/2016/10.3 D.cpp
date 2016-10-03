#include <iostream>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<sstream>
#include<queue>
#define ll long long
using namespace std;

ll a[52005];
int main()
{
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<52005;i++)
    {
        a[i]=(i+1)*(i)/2;
    }
    ll x=lower_bound(a,a+52005,n)-a;
    ll first=n-(x-1)*x/2+1;
    if(n==x*(x+1)/2)
    {
        for(int i=0;i<x;i++)
        printf(")");
        for(int i=0;i<x;i++)
        printf("(");
        printf("\n");
    }
    else {
    int i;
    for(i=1;i<first;i++)
    {
        printf(")");
    }
    printf("()");
    i+=2;
    for (;i<x+2;i++)
    printf(")");
    for(;i<=2*x;i++)
    printf("(");
    printf("\n");
    }
    return 0;
}

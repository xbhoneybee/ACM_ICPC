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


int n;
//计算a*x+b*y=gcd(a,b)的一组解x,y返回gcd(a,b)
ll exgcd(ll a , ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    ll d=exgcd(b,a%b,x,y);
    ll tem=x;
    x=y;
    y=tem-a/b*y;
    return d;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        bool ok=false;
        long long x,y;
        long long m0,mi,a0,ai;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                scanf("%I64d %I64d",&m0,&a0);
                continue;
            }
            else scanf("%I64d %I64d",&mi,&ai);
            if(ok)
                continue;
            long long gcdd=exgcd(m0,mi,x,y);
            if((ai-a0)%gcdd!=0)
            {
                printf("-1\n");
                ok=true;
                continue;
            }

            x*=(ai-a0)/gcdd;
            y*=(ai-a0)/gcdd;

            long long dx=mi/gcdd;
            x=(x%dx+dx)%dx;
            a0=a0+x*m0;
            m0=dx*m0;
        }
        if(ok==false)
        printf("%I64d\n",a0);
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<stdlib.h>
#include <sstream>
#include<deque> //双端队列
#define mod 1000000007
#define ll long long
#define LL long long
#define inf 10000000000000
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

long long magic[505][505];
int main()
{
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        scanf("%I64d",&magic[1][1]);
        printf("1\n");
        return 0;
    }
    int x,y;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            {
                scanf("%I64d",&magic[i][j]);
                if(magic[i][j]==0)
                    x=i,y=j;
            }
    set<long long >stx,sty;
    ll prex=0,prey=0;
    ll luprdo=0;
    ll ldorup=0;
    ll ans=0;
    for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=n;j++)
        {
            prex+=magic[i][j];
        }
        stx.insert(prex);
        prex=0;
      }
    if(stx.size()!=2)
    {
        printf("-1\n");
        return 0;
    }
    for(int j=1;j<=n;j++)
        {
            for(int i=1;i<=n;i++)
            {
            prey+=magic[i][j];
            }
            sty.insert(prey);
            prey=0;
        }
    if(sty.size()!=2)
    {
        printf("-1\n");
        return 0;
    }
    set<ll>::iterator ip;
    ip=stx.end();
    ip--;
    ans=*ip-*stx.begin();
    ip=sty.end();
    ip--;
    if(ans!= *ip-*sty.begin())
    {
        printf("-1\n");
        return 0;
    }
    for(int i=1;i<=n;i++)
        luprdo+=magic[i][i];
    for(int i=1;i<=n;i++)
        ldorup+=magic[n-i+1][i];
    ll sum=*ip;

    if(x!=y)
    {
        if(luprdo!=sum)
        {
        printf("-1\n");
        return 0;
        }
    }
    else {
        if(luprdo+ans!=sum)
        {
        printf("-1\n");
        return 0;
        }
    }
    if(x+y!=n+1)
    {
        if(ldorup!=sum)
        {
        printf("-1\n");
        return 0;
        }
    }
    else {
        if(ldorup+ans!=sum)
        {
        printf("-1\n");
        return 0;
        }
    }
    if(ans<=0)
        printf("-1\n");
    else
    printf("%I64d",ans);
    return 0;
}

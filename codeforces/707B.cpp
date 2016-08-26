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
#define mod 1000000007
#define ll long long
#define LL long long
#define inf 10000000000000
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

struct R
{
    int fm;
    int to;
    ll len;
} ride[100005];
int store[100005];
int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%I64d",&ride[i].fm,&ride[i].to,&ride[i].len);
    }
    if(k==0) {
        printf("-1\n");
        return 0;
    }
    for(int i=0;i<k;i++)
        {
            int t;
            scanf("%d",&t);
            store[t]=1;
        }
    ll ans=inf;
    for(int i=1;i<=m;i++)
    {
        if(store[ride[i].fm]==1&&store[ride[i].to]==0)
            ans=min(ans,ride[i].len);
        if(store[ride[i].fm]==0&&store[ride[i].to]==1)
            ans=min(ans,ride[i].len);
    }
    if(ans==inf)
        ans=-1;
    printf("%I64d\n",ans);
    return 0;
}

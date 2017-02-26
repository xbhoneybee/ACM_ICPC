#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<set>1
#include<vector>
#include<map>
#include<sstream>
#define ll long lo`ng
#define LL long long
#define inf 1000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

struct P{
int a,b,sup;
}p[200005];
int cmp(P p1,P p2)
{
    if(p1.sup!=p2.sup)
        return p1.sup<p2.sup;
    else return p1.b-p1.a>p2.b-p2.a;
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
       scanf("%d",&p[i].a);
    for(int i=0;i<n;i++)
        scanf("%d",&p[i].b);
    long long ans=0;
    ///k个a n-k个b
    for(int i=0;i<n;i++)
    {
        if(p[i].a<p[i].b)
            p[i].sup=1;
        else p[i].sup=2;
    }
    sort(p,p+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(i<k||p[i].sup==1)
            ans+=p[i].a;
        else ans+=p[i].b;
    }
    cout<<ans<<endl;
    return 0;
}

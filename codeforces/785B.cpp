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
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;



//greedy 2种

struct P
{
    long long l,r;
}an[200005],am[200005];
int cmp(P a,P b)
{
    if(a.l!=b.l)
        return a.l<b.l;
    else return a.r>b.r;
}
int cmp1(P a,P b)
{
    if(a.r!=b.r)
        return a.r<b.r;
    else return a.l>b.l;
}
int main()
{
    int n,m;
    cin>>n;
    for(int  i=0;i<n;i++)
        cin>>an[i].l>>an[i].r;
    cin>>m;
    for(int i=0;i<m;i++)
        cin>>am[i].l>>am[i].r;
    long long ans=0;
    sort(an,an+n,cmp);
    sort(am,am+m,cmp1);
    ans=max(ans,an[n-1].l-am[0].r);
    sort(am,am+m,cmp);
    sort(an,an+n,cmp1);
    ans=max(ans,am[m-1].l-an[0].r);
    cout<<ans<<endl;
    return 0;
}

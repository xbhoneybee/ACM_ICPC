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
#define inf 10000000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

int a[100005];
struct P{
int ava;
int id;
}ap[100005];
int cmp(P a,P b)
{
    if(a.ava==b.ava)
        return a.id<b.id;
    else return a.ava<b.ava;
}
int bsearch(int st,int ed,int aim)
{
    int l=st,r=ed;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(ap[mid].ava<aim)
            l=mid+1;
        else r=mid;
    }
    return l;
}
int main()
{
    int n,x;
    scanf("%d %d",&n,&x);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        ap[i].ava=a[i];
        ap[i].id=i;
    }
    sort(ap,ap+n,cmp);
    ll ans=0; ///test 18 
    for(int i=0;i<n;i++)
    {
        int goal=a[i]^x;
        int pos=bsearch(0,n,goal);
        if(ap[pos].ava>goal)
            continue;
        else {
            int posed=bsearch(0,n,goal+1);
            int l=pos,r=posed;
            while(l<r)
            {
                int mid=(l+r)/2;
                if(ap[mid].id<i)
                    l=mid+1;
                else r=mid;
            }
            if(ap[l].id==i)
                l++;
            if(posed-l>0)
            ans+=(posed-l);
        }
    }
    cout<<ans<<endl;
    return 0;
}

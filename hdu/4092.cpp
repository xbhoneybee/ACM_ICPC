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

int gcd(int x,int y)
{
    if(y==0)
    return x;
    else return gcd(y,x%y);
}
const int maxn=100005;
int n,Q;
int T;
int lazy1[maxn*4];
int a[maxn];
void build(int l,int r,int o)
{
    lazy1[o]=-1;
    if(l==r)
    {
        return ;
    }
    int m=(l+r)>>1;
    build(l,m,o<<1);
    build(m+1,r,o<<1|1);
}
void update(int t, int l, int r,int x, int L, int R,int o)//l,r 当前区间，L，R目标区间
{
	if (L <= l && r <= R)
	{
        if(t==1)
        {
            lazy1[o]=x;
        }
        else {
        if(lazy1[o]>=0)
        {
            if(lazy1[o]>x)
            lazy1[o]=gcd(lazy1[o],x);
        }else{
            if(l==r)
            {
                if(a[l]>x)
                    a[l]=gcd(x,a[l]);
                return;
            }
            update(t, l, (l+r)>>1,x, L, R,o<<1);
            update(t, ((l+r)>>1)+1, r,x, L, R,o<<1|1);
        }
        }
		return;
	}
	if (lazy1[o]>=0)
	{
        lazy1[o<<1]=lazy1[o];
        lazy1[o<<1|1]=lazy1[o];
		lazy1[o]=-1;
	}
	int m = (l + r) >> 1;
	if (L <= m)
		update(t, l, m,x, L, R,o<<1);
	if (R > m)
		update(t, m+1, r,x, L, R,o<<1|1);
}
void Query( int l, int r, int o)
{
    if (l==r)
	{
        if(lazy1[o]>=0)
        a[l]=lazy1[o];
        lazy1[o]=-1;
		return;
	}
	if (lazy1[o]>=0)
	{
        lazy1[o<<1]=lazy1[o];
        lazy1[o<<1|1]=lazy1[o];
        lazy1[o]=-1;
	}
	int m = (l + r) >> 1;
	Query(l,m,o<<1);
	Query(m+1,r,o<<1|1);
}
void output()
{
        Query(1,n,1);
        for(int i=1;i<=n;i++)
            {
            printf("%d ",a[i]);
            }
        printf("\n");
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        build(1,n,1);
        scanf("%d",&Q);
        for(int i=0;i<Q;i++)
        {
            int t,l,r,x;
            scanf("%d %d %d %d",&t,&l,&r,&x);
            update(t,1,n,x,l,r,1);
        }
        output();
    }
    return 0;
}

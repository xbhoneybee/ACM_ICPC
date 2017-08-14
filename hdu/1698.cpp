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
#define lowbit(x) x&-x

using namespace std;


///20170814 数据结构

const int maxn=500005;
int sum[maxn];
int tag[maxn];
int n;
void build(int L,int R,int o)
{
    tag[o]=0;
    if(L==R)
    {
        sum[o]=1;
        return ;
    }
    int M=(L+R)>>1;
    build(L,M,(o<<1));
    build(M+1,R,(o<<1|1));
    sum[o]=sum[o<<1]+sum[o<<1|1];
}
void update(int l,int r,int x,int L,int R,int o)
{
    if(L<=l&&r<=R)
    {
        sum[o]=(r-l+1)*x;
        tag[o]=x;
        return ;
    }
    int m= (l + r) >> 1;
    if (tag[o]>0)
	{
		tag[o<<1]=tag[o];
		sum[o<<1]=tag[o]*(m-l+1);
		tag[o<<1|1]=tag[o];
		sum[o<<1|1]=tag[o]*(r-m);
		tag[o]=0;
	}
	if (L <= m)
		update(l,m,x,L,R,(o<<1));
	if (R > m)
        update(m+1,r,x,L,R,(o<<1|1));
    sum[o]=sum[o<<1]+sum[o<<1|1];
}
int main()
{
    int T,id,q;
    scanf("%d",&T);
    id=1;
    while(T--)
    {
        scanf("%d %d",&n,&q);
        build(1,n,1);
        for(int i=0;i<q;i++)
        {
            int l,r,x;
            scanf("%d %d %d",&l,&r,&x);
            update(1,n,x,l,r,1);
        }
        printf("Case %d: The total value of the hook is %d.\n",id++,sum[1]);
    }
    return 0;
}

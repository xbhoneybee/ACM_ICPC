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

int d[100005];
int a[100005];
int n,k;
int T;
int upsort()
{
    memset(d,0,sizeof d);
    d[1]=a[1];
    int len=1,l,r,mid;
    for(int i=2;i<=n;i++)
    {
        if(d[len]<a[i])
            {
                d[++len]=a[i];
                continue;
            }
            l=1,r=len;
            while (l<=r)
            {
                mid=(l+(r-l)/2);
                if(d[mid]<a[i])
                    l=mid+1;
                else     r=mid-1;
            }
            d[l]=a[i];
    }
    return len;
}
int downsort()
{
    memset(d,0,sizeof d);
    d[1]=a[1];
    int len=1,l,r,mid;
    for(int i=2;i<=n;i++)
    {
        if(d[len]>a[i])
            {
                d[++len]=a[i];
                continue;
            }
            l=1,r=len;
            while (l<=r)
            {
                mid=(l+(r-l)/2);
                if(d[mid]>a[i])
                    l=mid+1;
                else     r=mid-1;
            }
            d[l]=a[i];
    }
    return len;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int up,down;
        up=upsort();
        down=downsort();
        if(up>=n-k||down>=n-k)
            printf("A is a magic array.\n");
        else printf("A is not a magic array.\n");
    }
    return 0;
}

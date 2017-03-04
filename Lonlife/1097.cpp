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
#include<set>
#include<vector>
#include<map>
#include<sstream>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x

using namespace std;

const int maxn=610000;
int a[maxn];
int d[maxn];
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=6;j++)
        {
            scanf("%d",&a[i*6+j]);
        }
        sort(a+i*6+1,a+i*6+7,cmp);
    }
    d[1]=a[1];
    int len=1,l,r,mid;
    for(int i=2;i<=6*n;i++)
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
            } //r=mid-1,l=mid+1,为了跳出循环
            d[l]=a[i];
    }
    printf("%d\n",len);
    }
    return 0;
}

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

/**
考虑进站的列车，假定第一个进站的是i号车，则最长的车队为i之后的最长上升子序列和最长下降子序列之和
*/
int a[2005];
int inc[2005];
int decr[2005];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
    for(int i=n;i>=1;i--)
        scanf("%d",&a[i]);
    inc[1]=1;
    decr[1]=1;
    int ans=0;
    for(int i=2;i<=n;i++)
    {
        inc[i]=decr[i]=1;
        for(int j=1;j<i;j++)
        {
            if(a[j]<a[i])
                inc[i]=max(inc[i],inc[j]+1);
            if(a[j]>a[i])
                decr[i]=max(decr[i],decr[j]+1);
        }
    }
    for(int i=1;i<=n;i++)
        ans=max(ans,decr[i]+inc[i]-1);
    printf("%d\n",ans);
    }
    return 0;
}

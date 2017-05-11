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

//poj 1836 
double dp[1005];
double a[1005];
int main()
{
    int n;
    while(cin>>n){
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;
    memset(dp,0,sizeof dp);
    for(int mid=1;mid<=n;mid++)
    {
        int l,r,len=0,lef=0;
        for(int i=1;i<mid;i++)
        {

            if(a[i]>=a[mid])
                continue;
            if(a[i]>dp[len])
            {
                dp[++len]=a[i];

                continue;
            }

            l=1,r=len;
            while(l<r)
            {
                int m=(l+r)/2;
                if(dp[m]<a[i])
                    l=m+1;
                else r=m;
            }
            dp[l]=a[i];

        }
        lef=len;
        len=0;
        dp[0]=a[mid];
        for(int i=mid+1;i<=n;i++)
        {
            if(a[i]<dp[len])
            {
                dp[++len]=a[i];
                continue;
            }
            l=1,r=len;
            while(l<r)
            {
                int m=(l+r)/2;
                if(dp[m]>a[i])
                    l=m+1;
                else r=m;
            }
            dp[l]=a[i];
        }
        ans=max(ans,lef+1+len);
        dp[0]=0;
    }
    cout<<n-ans<<endl;
    }
    return 0;
}

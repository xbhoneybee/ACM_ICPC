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


double dp[1005][1005];
int x[1005];
int y[1005];
double dist(int i,int j)
{
    double d=((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    return sqrt(d);
}
int n;
int main()
{
    iosfalse
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
            cin>>x[i]>>y[i];
        for(int i=1;i<n-1;i++)
        {
            dp[n-1][i]=dist(n,n-1)+dist(i,n);
        }
        for(int i=n-2;i>=2;i--)
        {
            for(int j=1;j<i;j++)
            {
                dp[i][j]=min(dp[i+1][i]+dist(j,i+1),dp[i+1][j]+dist(i,i+1));

            }
        }
        printf("%.2f\n",dist(1,2)+dp[2][1]);
    }
    return 0;
}

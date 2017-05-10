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

//uva 1331
double dp[60][60];
int n;
int x[60],y[60];
double dist(int a,int b)
{
    double ret=(x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
    return sqrt(ret);
}
double S(int i,int k,int j)
{
    double a=dist(i,k);
    double b=dist(j,k);
    double c=dist(i,j);
    double p=(a+b+c)/2;
    //海伦公式精度不够？
    //return (sqrt(p)*sqrt(p-a)*sqrt(p-b)*sqrt(p-c));
    //cout<<(sqrt(p)*sqrt(p-a)*sqrt(p-b)*sqrt(p-c))<<endl;
    //cout<<fabs((x[k] - x[i]) * (y[j] - y[i]) - (x[j] - x[i]) * (y[k] - y[i])) / 2.0 <<endl;
    return fabs((x[k] - x[i]) * (y[j] - y[i]) - (x[j] - x[i]) * (y[k] - y[i])) / 2.0 ;
}
bool check(int i,int k,int j)//i,k,j 内是否含点
{
    for(int a=1;a<=n;a++)
    {
        if(a==i||a==j||a==k)
            continue;
        if(fabs(S(i,k,j)-(S(i,k,a)+S(i,j,a)+S(j,k,a)))<1e-8)
            return true;
    }
    return false;
}
int main()
{
    iosfalse
    int t;
    cin>>t;
    while(t--){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
    }
    memset(dp,0,sizeof dp);
    for(int len=3;len<=n;len++)//length
    {
        for(int i=1;i+len-1<=n;i++)//start
        {
            dp[i][i+len-1]=1e18;
            for(int k=i+1;k<i+len-1;k++)
            {
                if(check(i,k,i+len-1))//注意如果中间三角形i-k-j中有其他的点,这样的三角形是不可以剖分的
                    continue;
                dp[i][i+len-1]=min(max(max(dp[i][k],dp[k][i+len-1]),S(i,k,i+len-1)),dp[i][i+len-1]);
            }
        }
    }
    printf("%.1f\n",dp[1][n]);
    }
    return 0;
}

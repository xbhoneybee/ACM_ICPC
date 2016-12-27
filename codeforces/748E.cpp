 #include <iostream>
#include<stdio.h>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<cstdlib>
#include <sstream>
#include <deque>
#include<list>
#include<ctime>
#define ll long long
#define LL long long
#define inf 10000.00
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

string getstring ( const int n )
{
std::stringstream newstr;
newstr<<n;
return newstr.str();
}
int getint ( string s )
{
return atoi(s.c_str());
}

//E
//玄学 向上取整
int a[1000006];
int dp[10000007];
int main()//dp+binary search//求a[i]可以分多少个时,dp求解
{
    int n;
    long long k;
    scanf("%d %I64d",&n,&k);
    int l,r=0,mid;
    for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            r=max(r,a[i]);
        }
    l=-1;
    int maxai=r;
    while(l<r)
    {
        mid=l+(r-l+1)/2;
        long long peo=0;
        memset(dp,0,sizeof dp);
        for(int i=mid;i<=maxai;i++)
        {
            dp[i]=dp[i/2]+dp[(i+1)/2];
            dp[i]=max(dp[i],1);
        }
        for(int i=0;i<n;i++)
        {
            peo+=dp[a[i]];
        }
        if(peo>=k)
            {
                l=mid;
            }
        else
            r=mid-1;
    }
    printf("%d\n",l);
    return 0;
}


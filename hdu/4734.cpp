#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<stdlib.h>
#include <sstream>
#include <deque>
#define mod 1000000007
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e18
#define lowbit(x) x&-x
using namespace std;

int dp[15][10000];//dp[i][j] i位数，f(x)不超过j的个数
int B[15];
ll x2[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096};
int f(ll x)
{
    int ret=0,i=0;
    while(x)
     {
         ret+=x2[i++]*(x%10);
         x/=10;
     }
     return ret;
}
int dfs(int i ,int j,int flag )//flag 控制边界
{
    if(j<0) return 0;
    if(i<1) return 1;// 0位数返回1是为了调用dfs(1,j,flag)时返回1
    int sum=0;
    if(!flag&&dp[i][j]!=-1) return dp[i][j];
    int endd=flag?B[i]:9;//是边界吗？是就用B数组
    for(int w=0;w<=endd;w++)
    {
        sum+=dfs(i-1,j-w*(1<<i-1),flag&&w==endd);
    }
    if(!flag)
        dp[i][j]=sum;
    return sum;
}
//数位dp eg b=394先找1-300，再找300-340 最后 340-349;
int main()
{
    iosfalse
    int t;
    cin>>t;
    memset(dp,-1,sizeof dp);//由于dp[i][j]值可能为0 因此初始化为-1表示未访问过
    for(int qc=1;qc<=t;qc++)
    {
     ll a,b;
    cin>>a>>b;
    int fa=f(a);
    int lenb=0;
    while(b)
     {
        B[++lenb]=b%10;
        b/=10;
     }

     cout<<"Case #"<<qc<<": "<<dfs(lenb,fa,1)<<endl;
    }
    return 0;
}

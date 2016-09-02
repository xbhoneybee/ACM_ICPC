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
#include <deque> //双端队列
#define mod 1000000007
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e18
#define lowbit(x) x&-x
using namespace std;

int dp[200007];//dp[i] 表示 when sum of s  = i ,the  value of f;
int main()
{
    int n;
    cin>>n;
    int s[105],f[105];
    for(int i=1;i<=n;i++)
    {
        cin>>s[i]>>f[i];
    }
    for(int i=0;i<=200000;i++)  //初始化  若都为0 则 说明dp[i] 在s的和为任意值时都可以使f和为0 显然不合理
        dp[i]=-inf;
    dp[100000]=0;
    for(int i=1;i<=n;i++)
        {
            if(s[i]<=0&&f[i]<=0)//优化   注意不能跳过s[i]+f[i]<=0的情况 虽然理论上贪心可以 但dp 会利用一些状态转移
               continue;

            if(s[i]>=0)
            {
                for(int j=200000;j>=s[i];j--)
                   if(dp[j-s[i]]>-inf)  
                    dp[j]=max(dp[j],dp[j-s[i]]+f[i]);

            }
            else
            {
                for(int j=s[i];j<=200000+s[i];j++)//  注意这里的循环范围 限定背包最大200000 为了使j-s[i]<+200000 
                    if(dp[j-s[i]]>-inf) //若状态合法
                    dp[j]=max(dp[j],dp[j-s[i]]+f[i]);
            }
        }
    int ans=-inf;
    for(int i=100000;i<=200000;i++)//在s和为非负的情况下
        if(dp[i]>=0)//f和为非负
        ans=max(ans,dp[i]+i-100000);
    cout<<ans<<endl;
    return 0;
}

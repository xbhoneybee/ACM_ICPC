#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>
#include<string.h>
#include<set>
#include<queue>
#include<cctype>
#include<map>
#define inf 1000000000
#define ll long long
#define mod 1000000007//  这里不要写成100000000+7 define是替换！！！
using namespace std;
#define iosfalse ios::sync_with_stdio(false);


//d完全背包问题
//还需要理解

int main()
{
    int dp[10000]={1};
    int v[5]={1,5,10,25,50};
    for(int i=0;i<=4;i++)
        for(int j=v[i];j<=7500;j++)
        {
            dp[j]=dp[j]+dp[j-v[i]];
            //状态转移：j元钱可以有 由第i种coin组成，每次加上新的第i种硬币的组成方法
        }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        cout<<dp[n]<<endl;
    }
    return 0;
}
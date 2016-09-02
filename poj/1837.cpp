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
#define inf 10000000000000
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e18
#define lowbit(x) x&-x
using namespace std;

//ppj 1837
//二维费用01 背包  一共要放 n件物品 每件物品有一个weight =（力矩+7500） 求方法数+=
//结果为 dp[n][7500] 7500 表示平衡状态 方法数
int dp[25][15005];

int main()
{
    int c,g,pos[25],w[25];
    cin>>c>>g;
    for(int i=0;i<c;i++)
        cin>>pos[i];
    for(int i=1;i<=g;i++)
        cin>>w[i];

        dp[0][7500]=1;
    for(int i=1;i<=g;i++)
        for(int j=15000;j>=1;j--)
        {
            for(int k=0;k<c;k++)
            {
                if(j-w[i]*pos[k]>=0&&j-w[i]*pos[k]<=15000&&dp[i-1][j-w[i]*pos[k]])
                dp[i][j]+=dp[i-1][j-w[i]*pos[k]];
            }
        }

    cout<<dp[g][7500]<<endl;
    return 0;
}

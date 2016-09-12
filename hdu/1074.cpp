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
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e18
#define lowbit(x) x&-x
using namespace std;

//N 的范围是一种状态压缩dp的暗示
//并且对于dp转移若从0到2^n-1,则转移左边每个state比右边state大 所以在之前计算过;
//于是根据这种转移 不需要初始化写完一个作业的状态，不需要memset dp数组；
struct DP
{
    int hascost;
    int reduction;
};
DP dp[(1<<15)+10];
int pre[(1<<15)+10];
string s[200];
void output(int x)  //利用递归输出,学习一个！
{
    if(!x) return ;
    output(x-(1<<pre[x]));
    cout<<s[pre[x]]<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,cost[20],deadl[20];
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>s[i]>>deadl[i]>>cost[i];
        for(int state=1;state<= ((1<<n) -1) ;state++)
        {
            dp[state].reduction=inf;
            for(int i=n-1;i>=0;i--)//这里要减序 为了字典序递增的更新
            {   //理解一下
                if(state&(1<<i))
                {
                    int tmp=state&(~(1<<i));
                    int tv;
                    tv = dp[tmp].hascost+cost[i]>deadl[i]?dp[tmp].reduction+dp[tmp].hascost+cost[i]-deadl[i]:dp[tmp].reduction;
                   if(dp[state].reduction>tv)                                                                             //0  还是这个？？？
                   {
                       dp[state].reduction=tv;
                       dp[state].hascost=dp[tmp].hascost+cost[i];
                      pre[state]=i;//到达状态state的前驱,为了最后输出完成作业的顺序 
                   }
                }
            }
        }
        cout<<dp[(1<<n)-1].reduction<<endl;
        output((1<<n)-1);
        //输出课程顺序
    }
    return 0;
}

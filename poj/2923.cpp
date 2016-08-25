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
#include<stack>
#define inf 1000000000
#define ll long long
#define mod 1000000007//  这里不要写成100000000+7 define是替换！！！
using namespace std;
#define iosfalse ios::sync_with_stdio(false);


/*
状态压缩DP+背包，
本题的解题思路是先枚举选择若干个时的状态，
总状态量为1<<n，判断这些状态集合里的那些物品能否一次就
运走，如果能运走，那就把这个状态看成一个物品。预处理完能
从枚举中找到tot个物品，再用这tot个物品中没有交集
（也就是两个状态不能同时含有一个物品）的物品进
行01背包，每个物品的体积是state[i]，价值是1，求
包含n个物品的最少价值也就是dp[(1<<n)-1]（dp[i]表示状态i需要运的最少次数)。
状态转移方程:dp[j|k] = min(dp[j|k],dp[k]+1) (k为state[i,1<=j<=(1<<n)-1])。
算法复杂度O((2^N)*N)
*/
int n,c1,c2;
int w[15];
bool vis[1030];//vis[i]==1表示能分总重i的 furniture为一块被c1装下
int dp[1030];//dp[i]表示数i用二进制表示运走所需次数
int state[1030];
bool isok(int x)//判断状态x是否可以运走
{
    int sum=0;
    memset(vis,0,sizeof vis);
    vis[0]=1;
    for(int i=0;i<n;i++)
    {
        if((x>>i)&1)//x的第i位为1
        {
            sum+=w[i];
            for(int j=c1;j>=w[i];j--)//这个真的非常巧妙 开始看半天都不懂，自己模拟一遍才懂
            {                   //比如说此状态有c1、c2、c3,3个体积，第一次操作把体积c1标记为1，
                if(vis[j-w[i]])//第二次操作把c2和c1+c2两种体积标记为1，第三次把c3和前面的组合标记为1，
                    vis[j]=1;//最后这些体积能组合成的所有体积就都被标记成了1
            }
        }
    }
    if(sum>c1+c2)  //装不下
        return 0;
    for(int i=0;i<=c1;i++)
    {
        if(vis[i]&&sum-i<=c2)//如果可以分成i 和sum-i
            return 1;//满足i可以被v1装下(前面for循环是对于v1的，vis[i]表示体积i可以被v1装下)
                     //sun-i可以被v2装下
    }
    return 0;
}
int tot;
void init()
{
    tot=0;
    for(int i=1;i<(1<<n);i++)
    {
        dp[i]=inf;
        if(isok(i))
            state[tot++]=i;
    }
}
int main()
{
    iosfalse
    int t;
    cin>>t;
    for(int tst=1;tst<=t;tst++)
    {
        cin>>n>>c1>>c2;
        for(int i=0;i<n;i++)
            cin>>w[i];
        init();
        int V=(1<<n)-1;
        dp[0]=0;//没有物品 0次运走
        for(int i=0;i<tot;i++)//枚举所有可行用一次运走
            for(int j=V;j>=0;j--)//原版的背包是dp[j] = min(dp[j],dp[j-c[i]]+w[i])
                                //但是显然二进制不好表示减，但是可以用|抽象加
                                //这就相当于背包改版成dp[j+c[i]] = min(dp[j+c[i]],dp[j] + w[i])
        {
            if(dp[j]==inf)
                continue;
            if((j&state[i])==0)//无交集
            {
                dp[j|state[i]]=min(dp[j]+1,dp[j|state[i]]);
            }

        }
        int ans=dp[V];
        cout<<"Scenario #"<<tst<<":"<<endl;
        cout<<ans<<endl;
        cout<<endl;
    }
    return 0;
}

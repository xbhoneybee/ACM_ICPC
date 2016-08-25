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
#define mod 10000//  这里不要写成100000000+7 define是替换！！！
using namespace std;
#define iosfalse ios::sync_with_stdio(false);

//区间dp

int main()
{
    int t;
    scanf("%d",&t);
    for(int m=1;m<=t;m++)
    {
        int n;
        scanf("%d",&n);
        int diao[105];
        int dp[105][105]={0};
        int sum[105]={0};
        for(int i=1;i<=n;i++)
            {
                scanf("%d",&diao[i]);
                sum[i]=diao[i]+sum[i-1];//前缀和，前i个屌丝的diao值
            }
            //dp[i][j]表示i到j这一段的最小值，初始化数据将i到j(j>i) 的dp inf;
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    dp[i][j]=inf;
            for(int l=1;l<=n;l++) //   l 区间长度
                for(int i=1;i<=n-l+1;i++) //i 枚举起点
            {
                int j=i+l;  //j为结尾(包含)
                for(int k=1;k<=j-i+1;k++)
                {//对于dp[i][j]的第i个人，就有可能第1个上场，也可以第j-i+1个上场。考虑第K个上场
                    dp[i][j]=min(dp[i][j],dp[i+1][i+k-1]+dp[i+k][j]+k*(sum[j]-sum[i+k-1])+diao[i]*(k-1));
                    //第  i+1  到 i+k-1  总共有k-1个人要比i先出栈，
                    //第 i+k   到j 总共j-i-k+1个人在i后面出栈

                                            //第i个人第k个上场 diao 值 diao[i]*(k-1)
                //其余人排在第k+1个之后,也就是一个子问题dp[i+k][j]，
                //对于这个区间的人，由于排在第k+1个之后，整体愤怒值要加上k*(sum[j]-sum[i+k-1])
                }                           //第i个人第k个上场 diao 值 diao[i]*(k-1)
            }
          int   ans=dp[1][n];
        cout<<"Case #"<<m<<": "<<ans<<endl;
    }
    return 0;
}
//可以分开进多组，不能枚举，宝宝心里苦
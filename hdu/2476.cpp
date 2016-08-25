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

// 区间dp
//刷字符串

int main()
{
    char a[105],b[105];
    while(scanf("%s",a)!=EOF)
    {
        scanf("%s",b);
        int n=strlen (b);
        //dp[i][j]为 i起点j结束的字符串刷成一样所需最小次数
        int dp[105][105]={0};
        for(int j=0;j<n;j++)  //j为尾部
              for(int i=j;i>=0;i--) //i为开头
        {
            dp[i][j]=dp[i+1][j]+1;//从尾部刷，每次刷一个的 值 存入dp[i][j] 最大
            //最开始默认a为空 将a刷成b需要从后向前刷 每次刷一个
            //eg aaaaa -> bbbba->aaaba->ddaba->cdaba
            for(int k=i+1;k<=j;k++)
            {
                //寻找 b中i k相同 可能减少刷的次数
                if(b[i]==b[k])
                    dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]);
                                           //i+1 k 2组数均可
                                //由于 i k相同 所以应有dp[i][k-1]=dp[i+1][k]
                                //eg abcabc  从右向左 刷 初始化 最左边a 不用刷
            }
        }
        int ans[105];
        for(int i=0;i<n;i++)
            ans[i]=dp[0][i];//记录空字符串a 到b 所需
         for(int i=0;i<n;i++)
         {
             if(a[i]==b[i])
                {   if(i>0)
                    ans[i]=ans[i-1];//对应相等 不刷
                    else ans[i]=0;
                }
             else{
                //不相等 则从前i个中找j 分开刷
                for(int j=0;j<i;j++)
                    ans[i]=min(ans[i],ans[j]+dp[j+1][i]);
             }
         }
         cout<<ans[n-1]<<endl;
    }
    return 0;
}

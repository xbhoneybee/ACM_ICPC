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

//dp
//假设现在队列由i-1个人变成了i个，由于谁后进到队列是无所谓的，
//不妨假设最矮的人是最后一个进入队列的，那么其所占的位置会有三种情况，
//第一种情况是站在队首，增加1个在前面能看到的人数，
//第二种情况是站在队尾，增加1个在后面能看到的人数，
//第三种情况是站在队伍中间，一共有i-2个位置可以站，但不会增加可见的人数。
//这样就能得到

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int l,r;
        cin>>l>>r;
        int dp[20][20][20]={0};
        //dp[i][j][k]表示一个k人从左看i个右看j个的组合数
        dp[1][1][1]=1;
        for(int k=2;k<=n;k++)
        for(int i=1;i<=k;i++)
            for(int j=1;j<=k;j++)
        {
            dp[i][j][k]=dp[i-1][j][k-1]+dp[i][j-1][k-1]+dp[i][j][k-1]*(k-2);
        }
    cout<<dp[l][r][n]<<endl;
    }
    return 0;
}
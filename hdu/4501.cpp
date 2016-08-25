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

int dp[105][105][10];
int main()
{
    int n,v1,v2,k;
    int a[105],b[105],val[105];
    while (scanf("%d %d %d %d",&n,&v1,&v2,&k)!=EOF){
    for(int i=1;i<=n;i++)
        scanf("%d %d %d",&a[i],&b[i],&val[i]);
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++)
      for(int j=v1;j>=0;j--)
            for(int j2=v2;j2>=0;j2--)
                for(int jk=k;jk>=0;jk--)
                {//4种选择  1不要，原来dp储存  2用钱  3用积分  4用免费 
                //若不开临时变量 在多维度影响下 滚动数组会失效
                int t=0;
                if(j>=a[i])
                t=max(t,dp[j-a[i]][j2][jk]+val[i]);
                if(j2>=b[i])
                t=max(t,dp[j][j2-b[i]][jk]+val[i]);
                if(jk>=1)
                t=max(t,dp[j][j2][jk-1]+val[i]);
                dp[j][j2][jk]=max(dp[j][j2][jk],t);
                }
        cout<<dp[v1][v2][k]<<endl;
   }
    return 0;
}
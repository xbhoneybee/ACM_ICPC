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

//  dp 这个问题的实质是求最长公共子序列，只是这两个序列分别是串S的前一部分和串S后一部分的逆序列。
//int dp[5005][5005]; 会爆内存 采取滚动数组策略

int dp[2][5005];
int main()
{
    iosfalse
    int n;
    char a[5050];
    char b[5050];
    while(scanf("%d",&n)!=EOF){
    memset(dp,0,sizeof dp);
    scanf("%s",a);   //cin 和scanf不要混用
    int i;
    for( i=0;i<n;i++)
        b[i]=a[n-1-i];
    b[i]='\0';
    int ans=0;
    for(i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
    {
        if(a[i-1]==b[j-1]) dp[i%2][j]=dp[1-i%2][j-1]+1;//滚动数组
        else dp[i%2][j]=max(dp[1-i%2][j],dp[i%2][j-1]);
    }
    ans=dp[n%2][n];
    cout<<n-ans<<endl;
    }
    return 0;
}
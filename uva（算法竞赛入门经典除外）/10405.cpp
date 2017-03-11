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

//  dp lcs  wa点有空格
//第一道dp!!!

int dp[1005][1005]={0};
int main()
{
   while(!cin.eof())
   {
        string  s1,s2;
        getline(cin,s1);// getline 不用吃\n
        int len1=s1.size();  //wa在奇怪的地方？估计文件最后有一个空行
        if(len1==0) break;
        getline(cin,s2);
   //   cout<<s1<<endl;
   //   cout<<s2<<endl;
    int len2=s2.size();
    for(int i=0;i<len1;i++)
    for(int j=0;j<len2;j++)
   {
    if(i==0||j==0)
    {
        if(s1[i]==s2[j])
            dp[i][j]=1;
        else if(i) dp[i][j]=dp[i-1][j];
        else if(j) dp[i][j]=dp[i][j-1];
    }
    else if(s1[i]==s2[j])
    {
        dp[i][j]=dp[i-1][j-1]+1;
    }
    else {
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
   }
    cout<<dp[len1-1][len2-1]<<endl;
    memset(dp,0,sizeof dp);
   }
    return 0;
}

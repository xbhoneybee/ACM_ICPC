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
#define mod 1000000007
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e18
#define lowbit(x) x&-x
using namespace std;

//dp[i][0]代表长度为i不含49的数  
//dp[i][1]代表长度为i不含49且最高位为9的数  
//dp[i][2]代表长度为i含有49的数  
long long dp[22][3];
int bit[22];//注意bit为倒序排列n eg：n=1234;bit=4321;
void init()
{
    dp[0][0]=1;//长度为0赋值为1 为了使长度为1时dp[1][0]=10;dp[1][1]=1;dp[1][2]=0;
    dp[0][1]=0;dp[0][2]=0;
    for(int i=1;i<=21;i++)
    {
        dp[i][0]=dp[i-1][0]*10-dp[i-1][1];
        dp[i][1]=dp[i-1][0];
        dp[i][2]=dp[i-1][2]*10+dp[i-1][1];
    }
}
long long cal(long long n)
{
    memset(bit,0,sizeof bit);
    int len=0;
    while(n)
    {
        bit[++len]=n%10;
        n/=10;
    }
    long long ans=0;
    bool has=false;//n本身是否含49
    for(int i=len;i>=1;i--)//倒序计算  使得bit 变正序输出
    {
        ans+=dp[i-1][2]*bit[i];
        if(!has)
        {
            if(bit[i]>4)
                ans+=dp[i-1][1];
        }
        else ans+=dp[i-1][0]*bit[i];//一旦找到49 随便选

        if(bit[i+1]==4&&bit[i]==9)
            has=true;
    }
    if(has)
            ans++;
    return ans;

}
//以491为例，先求出所有比400小的数中有多少符合题意的，然后4这一位确定以后，再求所有比490小，再求出所有比491小  
//i=3 求出数 049 149 249 349  
//i=2 求出数 449  
//i=1 求出数 490  
//自身包含49 所以求出数491  
int main()
{
    init();
    long long n;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<cal(n)<<endl;
    }
    return 0;
}

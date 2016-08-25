#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string.h>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include <sstream>
#define mod 1000000007
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
using namespace std;


// G  dp +kmp
int Next[100005];//优化求next数组方法
int zero[100005];
void getNext(char b[],int m)
{
    int j,k;
    j=0;k=-1;
    Next[0]=-1;
    while(j<m)
    {
        if(k==-1||b[j]==b[k])
        {
            j++;k++;
            if(b[j]!=b[k])
            Next[j]=k;
            else Next[j]=Next[k];
        }
        else
        {
            k=Next[k];
        }
    }
}
void KMP_Index(char a[],char b[])
{
    int i=0,j=0;
    int n=strlen(a);
    int m=strlen(b);
    getNext(b,m);
    while(i<n)
    {
        if(j==-1||a[i]==b[j])
        {
            i++;j++;
        }else j=Next[j];

    if(j==m){  //每次匹配一个字母j++ 此时j为匹配字母下一位 若为m
    zero[i]=1;//匹配完的下一位放1 表示下标从1开始的匹配完放1
    j=Next[j];
    }
    }
   return ;
}
char sa[100005];
char sb[100005];
ll  dp[100005];
int main()
{
    int T;
    int t=0;
    scanf("%d",&T);
    while(T--)
    {
        t++;
        printf("Case #%d: ",t);
        scanf("%s%s",sa,sb);
        memset(Next,0,sizeof Next);
        memset(zero,0,sizeof zero);
        memset(dp,0,sizeof dp);
        KMP_Index(sa,sb);
        int len=strlen(sa);
        int m=strlen(sb);
        dp[0]=1;

        for(int i=1;i<=len;i++)  //下标从1 开始计算
        {
            dp[i]=dp[i-1];
            if(zero[i]==1)
                dp[i]=(dp[i]+dp[i-m])%mod;

        }
        printf("%I64d\n",dp[len]);

    }
    return 0;
}
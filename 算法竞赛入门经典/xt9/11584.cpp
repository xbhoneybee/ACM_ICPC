//#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<vector>
#include<map>
#include<sstream>
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x

using namespace std;

//11584

char ch[1010];
int dp[1010];
bool ispal[1005][1005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%s",ch+1);
        int len=strlen(ch+1);
        dp[0]=0; //不更新就wa，但是应该没数据能更改dp[0]才对
        memset(ispal,false,sizeof ispal);
        int n=len;
        for(int cen=1;cen<=len;cen++)//枚举中心预处理
        {
            for(int l=0;l<len;l++)
            {
                if(cen-l<1||cen+l>n||ch[cen+l]!=ch[cen-l])
                    break;
                ispal[cen-l][cen+l]=true;
            }
            for(int l=0;l<len;l++)
            {
                if(cen-l<1||cen+l+1>n||ch[cen+l+1]!=ch[cen-l])
                    break;
                ispal[cen-l][cen+l+1]=true;
            }
        }
        for(int i=1;i<=len;i++)
        {
            dp[i]=1e8;
            for(int j=1;j<=i;j++)
            {
                if(ispal[j][i])
                {
                    dp[i]=min(dp[i],dp[j-1]+1);
                }
            }
        }
        cout<<dp[len]<<endl;
    }
    return 0;
}

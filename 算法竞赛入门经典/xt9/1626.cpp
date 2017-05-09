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


//uva 1626

char ch[210];
int dp[210][210];
int n;
bool match(int i,int j)
{
    if(i>n||j>n||i<1||j<1||i>=j)
        return false;
    if(ch[i]=='['&&ch[j]==']')
        return true;
    if(ch[i]=='('&&ch[j]==')')
        return true;
    return false;
}


void print_ans(int i,int j)
{
    if(i>j)
        return ;
    if(i==j)
    {
        if(ch[i]=='('||ch[i]==')')
            printf("()");
        else printf("[]");
        return;
    }
    int ans=dp[i][j];
    if(match(i,j)&&ans==dp[i+1][j-1])
    {
        printf("%c",ch[i]);
        print_ans(i+1,j-1);
        printf("%c",ch[j]);
        return ;
    }
    for(int k=i;k<j;k++)
    {
        if(ans==dp[i][k]+dp[k+1][j])
        {
            print_ans(i,k);
            print_ans(k+1,j);
            return ;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        gets(ch+1);
        gets(ch+1);
        n=strlen(ch+1);
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++)
        {
            dp[i][i]=1;
            if(i+1<=n)
            {
                if(match(i,i+1))
                    dp[i][i+1]=0;
                else dp[i][i+1]=2;
            }
            for(int j=i+2;j<=n;j++)
                dp[i][j]=1e9;
        }

        for(int len=3;len<=n;len++)//length
        {
            for(int i=1;i+len-1<=n;i++)//start
            {

            if(match(i,i+len-1))
                dp[i][i+len-1]=min(dp[i][i+len-1],dp[i+1][i+len-2]);
            for(int k=i;k<i+len-1;k++)
                {
                dp[i][i+len-1]=min(dp[i][k]+dp[k+1][i+len-1],dp[i][i+len-1]);
                }
            }
        }
        print_ans(1,n);
        printf("\n");
        if(t) printf("\n");
    }
    return 0;
}

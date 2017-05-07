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

//hiho  1520
/*
string getstr(int xx)
{
    string strx="";
    while(xx>0)
    {
        int t=xx%10;
        xx/=10;
        char ch=t+'0';
        strx+=ch;
    }
    reverse(strx.begin(),strx.end());
    return strx;
}
int main()
{
    string str;
    cin>>str;
    int x,y;
    cin>>x>>y;
    if(str.size()==1)
    {
        if(str[0]=='?')
            {
                if(y<10)
                    cout<<y<<endl;
                else cout<<"No solution"<<endl;
            }
        else {
            if((str[0]='0')%x==y)
            cout<<str<<endl;
            else cout<<"No solution"<<endl;
        }
        return 0;
    }
    set<string>st;
    string strx=getstr(x);
    string stry=getstr(y);
    if(strx.size()>str.size())
    {
        if(str.size()!=stry.size())
           {
               cout<<"No solution"<<endl;
               return 0;
           }
        else{
            for(int i=0;i<str.size();i++)
            {
                if(str[i]!='?'&&str[i]!=stry[i])
                {
                    cout<<"No solution"<<endl;
                    return 0;
                }
            }
            cout<<y<<endl;
        }
    }else {



    }
    return 0;
}
*/

//uva1625

char ch1[5005];
char ch2[5005];
int dp[2][5001];
int st1[30],st2[30],ed1[30],ed2[30];
int getv(int x,int y)
{
    int cnt=0;
    for(int i=0;i<26;i++)
    {
        if((x>=st1[i]||y>=st2[i])&&(x<ed1[i]||y<ed2[i]))
            cnt++;
    }
    return cnt;
}
int main()
{
    int t;
    iosfalse
    cin>>t;
    while(t--)
    {
        cin>>ch1+1>>ch2+1;
        int n=strlen(ch1+1);
        int m=strlen(ch2+1);
        memset(dp,0,sizeof dp);
        for(int i=0;i<26;i++)
        {
            st1[i]=st2[i]=1000000;
            ed1[i]=ed2[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            st1[ch1[i]-'A']=min(st1[ch1[i]-'A'],i);
            ed1[ch1[i]-'A']=i;
        }
        for(int i=1;i<=m;i++)
        {
           st2[ch2[i]-'A']=min(st2[ch2[i]-'A'],i);
           ed2[ch2[i]-'A']=i;
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                int t1=1e8,t2=1e8;
                if(i==0&&j==0)
                    continue;
                if(i)
                {
                    t1=dp[(i-1)%2][j]+getv(i-1,j);
                }
                if(j)
                {
                    t2=dp[i%2][j-1]+getv(i,j-1);
                }
                dp[i%2][j]=min(t1,t2);
            }
        }
        cout<<dp[n%2][m]<<endl;
    }
    return 0;
}

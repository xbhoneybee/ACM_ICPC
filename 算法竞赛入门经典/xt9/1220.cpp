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

//uva 1220

int n;
vector<int>son[210];
int f[210][2];
int d[210][2];
//dp[u][0]表示以u为root,不选u最多节点数 f[u][0]=1表示 解唯一
//dp[u][1] root u contain u的节点数  f[u][1]=1 表示 含u解唯一
int dp(int root,int have)
{
    if(d[root][have]>=0)
        return d[root][have];
    if(son[root].size()==0)
    {
        f[root][have]=1;
        if(have==1)
            return d[root][have]=1;
        else return d[root][have]=0;
    }
    if(have==1)
    {
        int sum=1;
        f[root][have]=1;
        for(int i=0;i<son[root].size();i++)
            {
                sum+=dp(son[root][i],0);
                if(f[son[root][i]][0]==0)
                    f[root][have]=0;
            }
        return d[root][have]=sum;
    }
    if(have==0)
    {
        int sum=0;
        f[root][0]=1;
        for(int i=0;i<son[root].size();i++)
            {
                int t0=dp(son[root][i],0);
                int t1=dp(son[root][i],1);
                sum+=max(t0,t1);
                if(t1==t0)
                    f[root][have]=0;
                if(t1<t0)
                {
                    if(f[son[root][i]][0]==0)
                        f[root][have]=0;
                }else{
                    if(f[son[root][i]][1]==0)
                        f[root][have]=0;
                }
            }
        return d[root][have]=sum;
    }
}
int main()
{
    //iosfalse
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&n)&&n)
    {
        map<string,int>table;
        memset(f,0,sizeof f);
        memset(d,-1,sizeof d);
        string str;
        cin>>str;
        table[str]=0;
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            string strbos;
            cin>>str>>strbos;
            int f,s;
            if(table.count(str))
                s=table[str];
            else {s=cnt;table[str]=cnt++;}
            if(table.count(strbos))
                f=table[strbos];
            else {f=cnt;table[strbos]=cnt++;}
            son[f].push_back(s);
        }
        int ans1=dp(0,0);
        int ans2=dp(0,1);
        if(ans1==ans2)
        {
            cout<<ans1<<" No"<<endl;
        }
        else if(ans1>ans2)
        {
            cout<<ans1;
            if(f[0][0]==1)
                cout<<" Yes"<<endl;
            else cout<<" No"<<endl;
        }else{
            cout<<ans2;
            if(f[0][1]==1)
                cout<<" Yes"<<endl;
            else cout<<" No"<<endl;
        }
        for(int i=0;i<=n+3;i++)
            son[i].clear();
    }
    return 0;
}

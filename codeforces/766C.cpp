#include <bits/stdc++.h>
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
#define ll long long
#define LL long long
#define inf 10000000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;
///dp 

const long long mmd=1e9+7;
int main()
{
    //freopen("output.txt","w",stdout);
    int N;
    char str[1005];
    int a[30]={0};
    scanf("%d",&N);
    scanf("%s",str+1);
    for(int i=0;i<26;i++)
        scanf("%d",&a[i]);
    ll dp[1005]={0};
    dp[0]=1;
    int sec=0;
    for(int i=1;i<=N;i++)
        {
            int x=a[str[i]-'a'];
            for(int j=i-1;j>=i-x&&j>=0;j--)
            {
            dp[i]=(dp[i]+dp[j])%mmd;
            if(a[str[j]-'a']>=x)
                ;
            else {
                    x=a[str[j]-'a'];
                }
            sec=max(i-j,sec);
            }
        }
    cout<<(dp[N]%mmd)<<endl;
    int thir=1,cnt=0;
    for(int i=1,x=a[str[i]-'a'];i<=N;i++)
    {
        x=min(x,a[str[i]-'a']);
        if(cnt<x)
            cnt++;
        else {
            thir++;
            cnt=1;
            x=a[str[i]-'a'];
        }
    }
    cout<<sec<<endl;
    cout<<thir<<endl;
    return 0;
}

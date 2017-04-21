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
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x

using namespace std;


////cf ed19 E dp+暴力
int a[100005];
int dp[100005][400];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int k=1;k<=400;k++)
    {
        for(int i=n;i>=1;i--)
        {
            if(i+a[i]+k<=n)
            dp[i][k]=dp[i+a[i]+k][k]+1;
            else dp[i][k]=1;
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int p,k;
        cin>>p>>k;
        if(k>400)
        {
            int cnt=0;
            while(p<=n)
            {
                p=p+k+a[p];
                cnt++;
            }
            cout<<cnt<<endl;
        }else {
            cout<<dp[p][k]<<endl;;
        }
    }
    return 0;
}

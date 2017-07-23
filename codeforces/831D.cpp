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

int dp[1005][2005];
int n,k,p;
int r[1005];
int key[2005];
int go(int x,int y)
{
   return abs(r[x]-key[y])+abs(key[y]-p);
}
int main()
{
    iosfalse
    cin>>n>>k>>p;
    for(int i=1;i<=n;i++)
        cin>>r[i];
    for(int i=1;i<=k;i++)
        cin>>key[i];
    sort(r+1,r+1+n);
    sort(key+1,key+1+k);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=k;j++)
    {
        if(i==j)
            dp[i][j]=max(dp[i-1][j-1],go(i,j));
        else dp[i][j]=min(dp[i][j-1],max(dp[i-1][j-1],go(i,j)));
    }
    cout<<dp[n][k]<<endl;
    return 0;
}

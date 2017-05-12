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



// poj 1276 
//数据奇葩，难受

int cash,n;
int num[11];
int val[11];
int dp[100005];
int main()
{
    while(scanf("%d",&cash)!=EOF){
        scanf("%d",&n);
    memset(dp,0,sizeof dp);

    for(int i=1;i<=n;i++)
        {
           scanf("%d %d",&num[i],&val[i]);
        }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int k=ans;k>=0;k--)
            {
                if(dp[k]||k==0)
                {
                    for(int j=1;j<=num[i];j++)
                    {
                        int tmp=k+j*val[i];
                        if(tmp>cash)
                            continue;
                        dp[tmp]=1;
                        ans=max(ans,tmp);
                    }
                }
            }
    }
    cout<<ans<<endl;
    }
    return 0;
}

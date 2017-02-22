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
#define ll long long
#define LL long long
#define inf 1000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

double dp[1005];
int k,q,p,ans[1005];
int main()
{
    cin>>k>>q;
    dp[0]=1.0;
    p=1;
    for(int i=1;p<=1000;i++)
        {
            for(int j=k;j>0;j--)
            {

            dp[j]=dp[j-1]*((k-j+1.0)/k)+dp[j]*((double)j/k);
            }
            while(p<=1000&&dp[k]>p/2000.0)
            {
                ans[p++]=i;
            }
            dp[0]=0.0;
        }
    for(int i=0;i<q;i++)
    {
        cin>>p;
        cout<<ans[p]<<endl;
    }
    return 0;
}

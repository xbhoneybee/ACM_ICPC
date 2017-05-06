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

//题意：电压高的灯泡可以代替电压低的灯泡（等数量替代）

int n;
struct PP{
int V,scost,cost,num;
}p[1005];
int cmp(PP a,PP b)
{
    return a.V<b.V;
}
int pre[1005];
int dp[1005];
int main()
{
    iosfalse
    while(cin>>n&&n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>p[i].V>>p[i].scost>>p[i].cost>>p[i].num;
            dp[i]=1e9;
        }
        sort(p+1,p+1+n,cmp);
        for(int i=1;i<=n;i++)
        {
            pre[i]=pre[i-1]+p[i].num;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                dp[i]=min((pre[i]-pre[j])*p[i].cost+p[i].scost+dp[j],dp[i]);
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}

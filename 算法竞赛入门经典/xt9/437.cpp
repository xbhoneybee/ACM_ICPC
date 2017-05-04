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



int n;
int cas=1;
struct pan{
int a,b,c;
pan(int x,int y,int z)
{
    if(x>y)
        swap(x,y);
    a=x;b=y;c=z;
}
};
vector<pan>vec;
int dp[100];
int dfs(int x)
{
    if(dp[x]>0)
        return dp[x];
    int het=0;
    for(int i=0;i<3*n;i++)
    {
        if(i==x)
            continue;
        if(vec[i].a<vec[x].a&&vec[i].b<vec[x].b)
        {
            het=max(het,dfs(i));
        }
    }
    dp[x]=het+vec[x].c;
    return dp[x];
}
int main()
{
    iosfalse
    while(cin>>n&&n)
    {
        vec.clear();
        memset(dp,0,sizeof dp);
        for(int i=0;i<n;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            vec.push_back(pan(x,y,z));
            vec.push_back(pan(x,z,y));
            vec.push_back(pan(y,z,x));
        }
        int ans=0;
        for(int i=0;i<3*n;i++)
            {
                dfs(i);
                ans=max(ans,dp[i]);
            }
        cout<<"Case "<<cas++<<": maximum height = "<<ans<<endl;
    }
    return 0;
}

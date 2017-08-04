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

// DFS TLE  想到遍历所有边的方法还有Floyd于是修改floyd
int n;
double ans;
vector<pair<int,int> >vec;
double ava[202][202];
double cal(int a,int b)
{
    return sqrt((vec[a].first-vec[b].first)*(vec[a].first-vec[b].first)+(vec[a].second-vec[b].second)*(vec[a].second-vec[b].second));
}
void  floyd()
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            if(ava[i][k]>0)
            for(int j=0;j<n;j++)
            {
                if(ava[i][j]>max(ava[i][k],ava[k][j]))
                    ava[i][j]=max(ava[i][k],ava[k][j]);
                if(i+j==1)
                    ans=min(ans,ava[i][j]);
            }
}
int main()
{
    int id=1;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        ans=1e18;
        vec.clear();
        memset(ava,-1,sizeof ava);
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            vec.push_back(make_pair(x,y));
        }
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
            ava[i][j]=ava[j][i]=cal(i,j);
            }
        floyd();
        printf("Scenario #%d\n",id++);
        printf("Frog Distance = %.3f\n\n",ans);
    }
    return 0;
}

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


//poj 3249
int n,m;
int val[100005];
vector<int>vec[100005];
int indegree[100005];
int topuord[100005];
int dp[100005];
int main()
{
    iosfalse
    while(scanf("%d %d",&n,&m)!=EOF){
    for(int i=1;i<=n;i++)
        {
            scanf("%d",&val[i]);
            vec[i].clear();
            dp[i]=-2e9;
        }
    memset(indegree,0,sizeof indegree);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        vec[x].push_back(y);
        indegree[y]++;
    }
    queue<int>que;
    for(int i=1;i<=n;i++)
        if(indegree[i]==0)
            {
                que.push(i);
                dp[i]=val[i];
            }
    int cnt=1;
    while(!que.empty())
    {
        int head=que.front();
        topuord[cnt++]=head;
        que.pop();
        for(int i=0;i<vec[head].size();i++)
        {
            indegree[vec[head][i]]--;
            if(indegree[vec[head][i]]==0)
                que.push(vec[head][i]);
        }
    }
    int ans=-2e9-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<vec[topuord[i]].size();j++)
        {
            dp[vec[topuord[i]][j]]=max(dp[vec[topuord[i]][j]],dp[topuord[i]]+val[vec[topuord[i]][j]]);
        }
        if(vec[topuord[i]].size()==0)
            ans=max(ans,dp[topuord[i]]);
    }
    printf("%d\n",ans);
    }
    return 0;
}

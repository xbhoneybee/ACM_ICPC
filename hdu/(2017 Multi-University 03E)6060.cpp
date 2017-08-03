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

//对于每条边的使用次数最多为min(k,root[rt])次，root[rt]为rt子树所含点数
const int maxn=1000006;
int n,k;
struct Edge
{
    int from;
    int to;
    int weight;
    Edge(int f, int t, int w):from(f), to(t), weight(w) {}
};
vector<int> G[maxn]; // G[i] 存储顶点 i 出发的边的编号
vector<Edge> edges;
int deep[maxn];
long long ans=0;
int dfs(int rt,int fa,int dist)
{
    deep[rt]=1;
    if(G[rt].size()==1&&edges[G[rt][0]].to==fa)
        {
            ans=ans+min(deep[rt],k)*1LL*dist;
            return deep[rt];
        }
    for(int i=0;i<G[rt].size();i++)
        {
        int tt=edges[G[rt][i]].to;
        if(tt==fa)
            continue;
        deep[rt]=deep[rt]+dfs(tt,rt,edges[G[rt][i]].weight);
        }
    ans=ans+min(deep[rt],k)*1LL*dist;
    return deep[rt];
}
int main()
{
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        for(int i=0;i<=n;i++)
            G[i].clear();
        edges.clear();
        for(int i=1;i<n;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            edges.push_back(Edge(a,b,c));
            G[a].push_back(edges.size()-1);
            edges.push_back(Edge(b,a,c));
            G[b].push_back(edges.size()-1);
        }
        ans=0;
        dfs(1,0,0);
        printf("%I64d\n",ans);
    }
    return 0;
}

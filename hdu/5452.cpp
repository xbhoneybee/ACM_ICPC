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

using namespace std;

//HDU 5452

const int maxn=20005;
const int maxh=20;//2^20深度
int deep[maxn];
int num[maxn];
int anc[maxn][maxh];
int rt;//树根
int dist[maxn];
struct Edge
{
    int from;
    int to;
    Edge(int f, int t):from(f), to(t){}
};
vector<int> G[maxn];
vector<Edge> edges;
void dfs(int root,int from)//子树根
{
    if(root==rt){
    deep[root]=1;
    dist[root]=0;
    for(int i=0;i<maxh;i++)
        anc[root][i]=root;
    }else{
    for(int i=1;i<maxh;i++)
    {
        int y=anc[root][i-1];
        anc[root][i]=anc[y][i-1];
    }
    }
    for(int i=0;i<G[root].size();i++)
        {
            Edge e=edges[G[root][i]];
            if(e.to==from)
                continue;
            deep[e.to]=deep[root]+1;
            dist[e.to]=dist[root]+1;
            anc[e.to][0]=root;
            dfs(e.to,root);
        }
}
void swim(int &x,int H)//将x向上移动H步
{
    for(int i=0;H>0;i++)
    {
        if(H&1)
            x=anc[x][i];//二进制思想
        H/=2;
    }
}
int lca(int x,int y)
{
    int i;
    if(deep[x]>deep[y])//保证y在下方
        swap(x,y);
    swim(y,deep[y]-deep[x]);
    if(x==y)
        return x;
    for(;;)
    {
        for(i=0;anc[x][i]!=anc[y][i];i++);
        if(i==0){
            return anc[x][0];
        }
        x=anc[x][i-1];
        y=anc[y][i-1];
    }
    return -1;
}
void dfs2(int root,int fa)
{

}
void dfind(int root,int fa,int &ans)
{
    for(int i=0;i<G[root].size();i++)
    {
        if(edges[G[root][i]].to!=fa)
        {
            dfind(edges[G[root][i]].to,root,ans);
            num[root]+=num[edges[G[root][i]].to];
        }
    }
    if(root!=rt)
    {
        ans=min(ans,num[root]);
    }
}
int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        rt=1;
        for(int i=0;i<=n;i++)
            G[i].clear();
        edges.clear();
        memset(num,0,sizeof num);
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            edges.push_back(Edge(u,v));
            G[u].push_back(edges.size()-1);
            edges.push_back(Edge(v,u));
            G[v].push_back(edges.size()-1);
        }
        dfs(1,0);
        for(int i=0;i<m-n+1;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            int alca=(lca(u,v));
            num[alca]-=2;
            num[u]++;
            num[v]++;
        }
        int ans=m;
        dfind(1,0,ans);
        printf("Case #%d: %d\n",cas++,ans+1);
    }
    return 0;
}

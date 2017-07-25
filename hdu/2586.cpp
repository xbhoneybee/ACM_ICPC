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

const int maxn=40005;
const int maxh=20;//2^20深度
int deep[maxn];
int anc[maxn][maxh];
int rt;//树根
int dist[maxn];
struct Edge
{
    int from;
    int to;
    int weight;
    Edge(int f, int t,int w):from(f), to(t),weight(w){}
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
            dist[e.to]=dist[root]+e.weight;
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
int main()
{
    iosfalse
    int T;
    cin>>T;
    while(T--)
    {
        int n,q;
        cin>>n>>q;
        for(int i=1;i<n;i++)
        {
            int f,t,w;
            cin>>f>>t>>w;
            edges.push_back(Edge(f,t,w));
            G[f].push_back(edges.size()-1);
            edges.push_back(Edge(t,f,w));
            G[t].push_back(edges.size()-1);
        }
        rt=1;
        dfs(1,-1);

        for(int i=0;i<q;i++)
        {
            int a,b;
            cin>>a>>b;
            int ancesstor=lca(a,b);
            cout<<dist[a]+dist[b]-dist[ancesstor]*2<<endl;
        }
    }
    return 0;
}

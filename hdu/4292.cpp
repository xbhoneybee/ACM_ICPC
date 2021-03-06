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
#define lowbit(x) x&-x
using namespace std;

const int maxn=808,inf=0x7fffffff;
struct edge{
    int from,to,cap,flow;
    edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};
struct dinic{
    int n,m,s,t;
    vector<edge>edges;
    vector<int>g[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];
    void init(int n){
        this->n=n;
        for(int i=0;i<n;i++) g[i].clear();
        edges.clear();
    }
    void addedge(int from,int to,int cap){
        edges.push_back(edge(from,to,cap,0));
        edges.push_back(edge(to,from,0,0));//反向弧
        m=edges.size();
        g[from].push_back(m-2);
        g[to].push_back(m-1);
    }
    bool bfs(){
        memset(vis,0,sizeof(vis));
        queue<int>q;
        q.push(s);
        d[s]=0;
        vis[s]=1;
        while(!q.empty()){
            int x=q.front();q.pop();
            for(int i=0;i<(int)g[x].size();i++){
                edge&e=edges[g[x][i]];
                if(!vis[e.to]&&e.cap>e.flow){
                    vis[e.to]=1;
                    d[e.to]=d[x]+1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int dfs(int x,int a){
        if(x==t||a==0) return a;
        int flow=0,f;
        for(int&i=cur[x];i<(int)g[x].size();i++){
            edge&e=edges[g[x][i]];
            if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0){
                e.flow+=f;
                edges[g[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0) break;
            }
        }
        return flow;
    }
    int maxflow(int s,int t){
        this->s=s;this->t=t;
        int flow=0;
        while(bfs()){
            memset(cur,0,sizeof(cur));
            flow+=dfs(s,inf);
        }
        return flow;
    }
}dc;
int food[300],drink[300];
int main()
{
    int n,f,d;
    while(scanf("%d%d%d",&n,&f,&d)!=EOF){
        dc.init(2*n+f+d+10);
        for(int i=0;i<f;i++)
            {
                scanf("%d",&food[i]);
                dc.addedge(0,2*n+1+i,food[i]);
            }
        for(int i=0;i<d;i++)
            {
                scanf("%d",&drink[i]);
                dc.addedge(2*n+f+1+i,2*n+f+d+1,drink[i]);
            }
        for(int i=0;i<n;i++)
        {
            char ld[220];
            scanf("%s",ld);
            for(int j=0;j<f;j++)
            {
                if(ld[j]=='Y')
                    dc.addedge(2*n+1+j,i+1,1);
            }
        }
        for(int i=0;i<n;i++)
        {
            char ld[220];
            scanf("%s",ld);
            for(int j=0;j<d;j++)
            {
                if(ld[j]=='Y')
                    dc.addedge(n+1+i,2*n+f+1+j,1);
            }
        }
        for(int i=1;i<=n;i++)
            dc.addedge(i,i+n,1);
        int ans=dc.maxflow(0,2*n+f+d+1);
        printf("%d\n",ans);
    }
    return 0;
}
//以人为中间节点，拆开成2个点，建图

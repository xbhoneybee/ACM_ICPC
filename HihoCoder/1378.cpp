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
#define iosfalse ios::sync_with_stdio(falllllse);
#define lowbit(x) x&-x
using namespace std;


const int maxn=555,inf=0x7fffffff;
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
}solve;
int Sset[550];
int bfsvis[550];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    {
        //solve.init(n+10);
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            solve.addedge(a,b,c);
        }
        int ans=solve.maxflow(1,n);
        //之后BFS跑一边求与s连接的点
        queue<int>que;
        que.push(1);
        Sset[1]=1;
        bfsvis[1]=1;
        int B=1;
        while(!que.empty())
        {
            int head=que.front();
            que.pop();
            for(int i=0;i<solve.g[head].size();i++)
            {
                if(bfsvis[solve.edges[solve.g[head][i]].to]==0&&(solve.edges[solve.g[head][i]].cap>0)&&(solve.edges[solve.g[head][i]].flow<solve.edges[solve.g[head][i]].cap))
                {
                    Sset[solve.edges[solve.g[head][i]].to]=1;B++;
                    que.push(solve.edges[solve.g[head][i]].to);
                    bfsvis[solve.edges[solve.g[head][i]].to]=1;
                }
            }
        }
        printf("%d %d\n",ans,B);
        for(int i=1;i<n;i++)
        {
            if(Sset[i])
                cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}

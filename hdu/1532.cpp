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
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

using namespace std;
const int maxn=202,inf=0x7fffffff;
struct edge{
    int from,to,cap,flow;
    edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};
struct Edmonds_Karp{
    int n,m;
    vector<edge>edges;//边数的两倍
    vector<int>g[maxn];//邻接表，g[i][j]表示节点i的第j条边在e数组中的序号
    int a[maxn];//当起点到i的可改进量
    int p[maxn];//最短路树上p的入弧编号
    void init(int n){
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
    int Maxflow(int s,int t){
        int flow=0;
        for(;;){
            memset(a,0,sizeof(a));
            queue<int>q;
            q.push(s);
            a[s]=inf;
            while(!q.empty()){
                int x=q.front();q.pop();
                for(int i=0;i<(int)g[x].size();i++){
                    edge&e=edges[g[x][i]];
                    if(!a[e.to]&&e.cap>e.flow){
                        p[e.to]=g[x][i];
                        a[e.to]=min(a[x],e.cap-e.flow);
                        q.push(e.to);
                    }
                }
                if(a[t]) break;//如果有增广路,退出
            }
            if(!a[t]) break;//没有增广路，现在结果即为最大流
            for(int u=t;u!=s;u=edges[p[u]].from){
                edges[p[u]].flow+=a[t];
                edges[p[u]^1].flow-=a[t];
            }
            flow+=a[t];
        }
        return flow;
    }
}solve;
int main()
{
    int M,N;
    while(scanf("%d %d",&M,&N)==2)
    {
        solve.n=N;
        solve.init(N);//注意solve 内部vector最开始没初始化为空。
        for(int i=0;i<M ;i++)
        {
            int u,v,c;
            scanf("%d %d %d",&u,&v,&c);
            solve.addedge(u,v,c);
        }
        int ans=solve.Maxflow(1,solve.n);
        printf("%d\n",ans);
    }
    return 0;
}

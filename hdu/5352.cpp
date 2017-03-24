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

const int maxn=702,inf=0x7fffffff;
struct Edge//边
{
    int from,to,cap,flow,cost;//出点，入点，容量，当前流量，费用（也就是权值）
    Edge(int u,int v,int c,int f,int w):from(u),to(v),cap(c),flow(f),cost(w){}
};
struct MCMF
{
    int n,m;
    vector<Edge> edges;//保存表
    vector<int> G[maxn];//保存邻接关系
    int inq[maxn];//判断一个点是否在队列当中（SPFA算法当中要用）
    int d[maxn];//起点到d[i]的最短路径保存值
    int p[maxn];//用来记录路径，保存上一条弧
    int a[maxn];//找到增广路径后的改进量
    void init(int xb)//初始化
    {
        for(int i=0;i<=xb;i++)//从 0 开始的TLE  TAT
            G[i].clear();
            edges.clear();
    }
    void AddEdge(int from,int to,int cap,int cost)//添加边
    {
        edges.push_back(Edge(from,to,cap,0,cost));//正向
        edges.push_back(Edge(to,from,0,0,-cost));//反向
        m=edges.size();
        G[from].push_back(m-2);//按照边的编号保存邻接关系
        G[to].push_back(m-1);
    }
    bool BellmanFord(int s,int t,int& flow,long long& cost)//最短路径算法其实是spfa
    {
        for(int i=1;i<=n;i++)
            d[i]=inf;
        memset(inq,0,sizeof(inq));
        d[s]=0;
        inq[s]=1;
        p[s]=0;
        a[s]=inf;
        queue<int> Q;
        Q.push(s);
        while(!Q.empty())
        {
            int u=Q.front();
            Q.pop();
            inq[u]=0;
            for(int i=0;i<G[u].size();i++){
                Edge &e=edges[G[u][i]];
                if(e.cap>e.flow&&d[e.to]>d[u]+e.cost)
                {
                    d[e.to]=d[u]+e.cost;
                    p[e.to]=G[u][i];
                    a[e.to]=min(a[u],e.cap-e.flow);
                    if(!inq[e.to])//是否在队列当中
                    {
                        Q.push(e.to);
                        inq[e.to]=1;
                    }
                }
            }
        }
        if(d[t]==inf)//如果d[t]没有被更新，相当于没找到增广路径，则没有最大流也没有最小费用
            return false;
        flow+=a[t];//更新最大流
        cost+=(long long )d[t]*(long long)a[t];//单位流量乘以单位路径长度用来计算消耗
        for(int u=t;u!=s;u=edges[p[u]].from)//通过使用p[]保存的上一个边的值来对刚刚找到的增广路径上面的流量进行更新
        {
        edges[p[u]].flow+=a[t];//正向变更新
        edges[p[u]^1].flow-=a[t];//反向变更新（用位运算实现的）
        }
        return true;
    }
    int MincostMaxflow(int s,int t,long long& cost)//计算从s到t的最小消耗cost，返回最大流
    {
    int flow = 0;
    cost=0;
    while(BellmanFord(s,t,flow,cost));//不断寻找最短增广路径，直到找不到为止
    return flow;
    }
}sl;
int mp[205][205];
int vis[205];
void dfs(int st,int lim,int ed)
{
    vis[st]=1;
    sl.AddEdge(st,ed,1,0);
    for(int i=1;i<=lim;i++)
    {
        if(mp[st][i]==1&&vis[i]==0)
        {
            dfs(i,lim,ed);
        }
    }
}
int main()
{
    int n,m,k,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        sl.init(m+n+1);
        memset(mp,0,sizeof mp);
        for(int i=1;i<=n;i++)
            sl.AddEdge(0,i,1,0);
        int opone=1,cost=m+10;
        for(int i=1;i<=m;i++)
        {
            int op;
            scanf("%d",&op);
            if(op==1)
            {
                memset(vis,0,sizeof vis);
                opone++;
                sl.AddEdge(n+opone,n+1,k,cost);
                int x;
                scanf("%d",&x);
                dfs(x,n,n+opone);
                cost--;
            }else if(op==2)
            {
                int a,b;
                scanf("%d %d",&a,&b);
                mp[a][b]=1;
                mp[b][a]=1;
            }else{
                int p;
                scanf("%d",&p);
                while(p--)
                {
                    int a,b;
                    scanf("%d %d",&a,&b);
                    mp[a][b]=mp[b][a]=0;
                }
            }
        }
        long long  sum_cost=0;
        sl.n=n+opone+1;//注意不要将sl.n=n+m+1;会TLE
        int ans=sl.MincostMaxflow(0,n+1,sum_cost);
        printf("%d\n",ans);
        int flag=0;
        for(int i=0;i<sl.edges.size();i++)
        {
            if(flag == 0 && sl.edges[i].to == n+1)
            {
                printf("%d", sl.edges[i].flow);
                flag = 1;
            }
            else if(sl.edges[i].to == n+1)
            {
                printf(" %d",sl. edges[i].flow);
            }
        }
        printf("\n");
    }
    return 0;
}
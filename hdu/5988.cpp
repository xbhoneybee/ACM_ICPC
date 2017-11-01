#include <bits/stdc++.h>
#include<sstream>
#include<ctime>
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

/**
对于每个人单独计算概率，累乘为结果
对于乘法取对数就是加法
求崩溃概率最小即为不崩坏概率最大
TLE 了加eps减少运算
我太菜了，比赛没做出来
*/
const double eps=1e-8;
const int maxn=130;
const double inf=0x7fffffff;
struct Edge//边
{
    int from,to,cap,flow;//出点，入点，容量，当前流量，费用（也就是权值）
    double cost;
    Edge(int u,int v,int c,int f,double w):from(u),to(v),cap(c),flow(f),cost(w){}
};
struct MCMF
{
    int n,m;
    vector<Edge> edges;//保存表
    vector<int> G[maxn];//保存邻接关系
    int inq[maxn];//判断一个点是否在队列当中（SPFA算法当中要用）
    double d[maxn];//起点到d[i]的最短路径保存值
    int p[maxn];//用来记录路径，保存上一条弧
    int a[maxn];//找到增广路径后的改进量
    void init(int n)//初始化
    {
        this->n=n;
        for(int i=0;i<=n;i++)
            G[i].clear();
        edges.clear();
        memset(a,0,sizeof a);
        memset(p,0,sizeof p);
    }
    void AddEdge(int from,int to,int cap,double cost)//添加边
    {
        edges.push_back(Edge(from,to,cap,0,cost));//正向
        edges.push_back(Edge(to,from,0,0,-cost));//反向
        m=edges.size();
        G[from].push_back(m-2);//按照边的编号保存邻接关系
        G[to].push_back(m-1);
    }
    bool BellmanFord(int s,int t,int& flow,double& cost)//最短路径算法其实是spfa
    {
        for(int i=0;i<=n;i++)
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
                if(e.cap>e.flow&&d[e.to]>d[u]+e.cost+eps)
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
        if(d[t]>=inf-10)//如果d[t]没有被更新，相当于没找到增广路径，则没有最大流也没有最小费用
            return false;
        flow+=a[t];//更新最大流
        cost+= d[t]*a[t];//单位流量乘以单位路径长度用来计算消耗
        for(int u=t;u!=s;u=edges[p[u]].from)//通过使用p[]保存的上一个边的值来对刚刚找到的增广路径上面的流量进行更新
        {
        edges[p[u]].flow+=a[t];//正向变更新
        edges[p[u]^1].flow-=a[t];//反向变更新（用位运算实现的）
        }
        return true;
    }
    int MincostMaxflow(int s,int t,double& cost)//计算从s到t的最小消耗cost，返回最大流
    {
    int flow = 0;
    cost=0;
    while(BellmanFord(s,t,flow,cost));//不断寻找最短增广路径，直到找不到为止
    return flow;
    }
}sl;
int main()
{
    int n,m,T;
    scanf("%d",&T);
    while(T--){
    scanf("%d %d",&n,&m);
    sl.init(n+20);
    for(int i=1;i<=n;i++)
    {
        int s,b;
        scanf("%d %d",&s,&b);
        if(s-b>0)
        {
            sl.AddEdge(0,i,s-b,0);
        }else if(s-b<0)
        {
            sl.AddEdge(i,n+1,b-s,0);
        }
    }
    while(m--)
    {
        int a,b,c;
        double p;
        scanf("%d %d %d %lf",&a,&b,&c,&p);
        if(c>0){
        sl.AddEdge(a,b,1,0);
        }
        p=-log2(1.0-p);
        if(c>1){
        sl.AddEdge(a,b,c-1,p);
        }
    }
    double ct=0;
    bool ok=sl.MincostMaxflow(0,n+1,ct);
    ct=pow(2,-ct);
    printf("%.2f\n",1.0-ct);
    }
    return 0;
}

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

const int maxn=202,inf=0x7fffffff;
struct edge{
    int from,to,cap,flow;
    edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};
map<pair<int,int>,int>ans;
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
            stack<int>q;
            q.push(s);
            a[s]=inf;
            while(!q.empty()){
                int x=q.top();q.pop();
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
                if(u!=t&&edges[p[u]].from!=s&&abs(u-edges[p[u]].from)!=(n-1)/2)
                    {
                        ans[make_pair(edges[p[u]].from-(n-1)/2,u)]+=a[t];
                    }
            }
            flow+=a[t];
        }
        return flow;
    }
}solve;
struct Point{
int cap;
int st[11];
int ed[11];
};
int main()
{
    int m,N;
    while(scanf("%d %d",&m,&N)!=EOF)
    {
        vector<Point>ppt;
        solve.n=2*N+1;
        solve.init(2*N+10);//注意solve 内部vector最开始没初始化为空。
        ans.clear();
        for(int i=0;i<N;i++)
        {
            Point p1;
            cin>>p1.cap;
            for(int j=0;j<m;j++)
                cin>>p1.st[j];
            for(int j=0;j<m;j++)
                cin>>p1.ed[j];
            ppt.push_back(p1);
        }
        for(int i=0;i<N;i++)
        {
            for(int k=0;k<m;k++)
            {
                if(ppt[i].st[k]==1)
                    break;
                if(k==m-1)
                    solve.addedge(0,i+1,5*1e5);
            }
            for(int k=0;k<m;k++)
            {
                if(ppt[i].ed[k]!=1)
                    break;
                if(k==m-1)
                    solve.addedge(N+i+1,2*N+1,5*1e5);
            }
            for(int j=0;j<N;j++)
            {
                if(i==j)
                    continue;
                bool ae=true;
                for(int k=0;k<m;k++)
                {
                    if((ppt[i].ed[k]==ppt[j].st[k])||(ppt[j].st[k]==2))
                        continue;
                    else {ae=false;break;}
                }
                if(ae==true)
                    solve.addedge(i+N+1,j+1,5*1e5);
                if(ae==true)
                    continue;
                ae=true;
                for(int k=0;k<m;k++)
                {
                    if((ppt[i].st[k]==ppt[j].ed[k])||(ppt[i].st[k]==2))
                        continue;
                    else {ae=false;break;}
                }
                if(ae==true)
                    solve.addedge(j+N+1,i+1,5*1e5);
            }
        }
        for(int i=0;i<N;i++)
        {
            solve.addedge(i+1,i+1+N,ppt[i].cap);
        }
        int out=solve.Maxflow(0,2*N+1);
        cout<<out<<" "<<ans.size()<<endl;
        map<pair<int,int>,int>::iterator ip;
        for(ip=ans.begin();ip!=ans.end();ip++)
        {
            cout<<(ip->first).first<<" "<<(ip->first).second<<" "<<(ip->second)<<endl;
        }
    }
    return 0;
}
//拆点大法好
//另外 将bfs的queue 换成stack 变成dfs 才能ac  玄学问题

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

const int Ni = 100005;
const long long  INF = 1e18;
struct node{
    int x;
    long long d;
    node(){}
    node(int a,long long b){x=a;d=b;}
    bool operator < (const node & a) const
    {
        if(d==a.d) return x<a.x;
        else return d > a.d;
    }
};
vector<node> eg[Ni];
long long  dis[Ni];
int n,m;
void Dijkstra(int s)
{
    int i;
    for(i=0;i<=n+m*2+10;i++)
        dis[i]=INF;
    dis[s]=0;
    //用优先队列优化
    priority_queue<node> q;
    q.push(node(s,dis[s]));
    while(!q.empty())
    {
        node x=q.top();q.pop();
        for(i=0;i<eg[x.x].size();i++)
        {
            node y=eg[x.x][i];
            if(dis[y.x]>x.d+y.d)
            {
                dis[y.x]=x.d+y.d;
                q.push(node(y.x,dis[y.x]));
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int ki;
        cin>>ki;
        for(int j=0;j<ki;j++)
        {
            int u;
            cin>>u;
            eg[u].push_back(node(i+n,0));
            eg[i+n+m].push_back(node(u,0));
        }
    }
    int m1;
    cin>>m1;
    for(int i=0;i<m1;i++)
    {
        int u,v,x;
        cin>>u>>v>>x;
        eg[u].push_back(node(v,x));
        eg[v].push_back(node(u,x));
    }
    int m2;
    cin>>m2;
    for(int i=0;i<m2;i++)
    {
        int a,b,x;
        cin>>a>>b>>x;
        eg[n+a].push_back(node(b+n+m,x));
        eg[n+b].push_back(node(n+a+m,x));
    }
    int s,t;
    cin>>s>>t;
    Dijkstra(s);
    if(dis[t]==1e18)
        dis[t]=-1;
    cout<<dis[t]<<endl;
    return 0;
}

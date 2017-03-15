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
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
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
}dc;
int cap[555];
int main()
{
    int n,m,k;
    cin>>n;
    //st=0 ed=520
    dc.init(521);
    map<string,int>mpedge;
    map<string,vector<int> >mpid;
    int id=1;
    for(int i=0;i<n;i++)
    {
        string t;
        cin>>t;
        if(mpedge.count(t))
        {
            mpedge[t]++;
        }else {
            mpedge[t]=1;
            mpid[t].push_back(id++);
        }
    }
    cin>>m;
    map<string,int>::iterator ip;
    for(ip=mpedge.begin();ip!=mpedge.end();ip++)
    {
        int time=ip->second;
        dc.addedge(mpid[ip->first][0],520,time);
        cap[mpid[ip->first][0]]=time;
    }
    mpedge.clear();
    int middle=id-1;
    for(int i=0;i<m;i++)
    {
        string name,t;
        cin>>name>>t;
        if(mpedge.count(t))
        {
            mpedge[t]++;
        }else {
            mpedge[t]=1;
            mpid[t].push_back(id++);
        }
    }
    for(ip=mpedge.begin();ip!=mpedge.end();ip++)
    {
        int time=ip->second;
        if(mpid[ip->first].size()==1)
        dc.addedge(0,mpid[ip->first][0],time);
        else dc.addedge(0,mpid[ip->first][1],time);
    }
    cin>>k;
    for(int i=0;i<k;i++)
    {
        string r,p;
        cin>>r>>p;
        int nump=-1,numr=-1;
        if(mpid.count(r)==0)
        {
            numr=0;
            mpid[r].push_back(id++);
        }
        else if(mpid[r].size()==1)
            {
                if(mpid[r][0]>middle)
                    numr=0;
                else {
                    numr=1;
                    mpid[r].push_back(id++);
                }
            }
        else numr=1;
        if(mpid.count(p)==0)
            {
            nump=0;
            mpid[p].push_back(id++);
            }
        else if(mpid[p].size()==1)
            {
                if(mpid[p][0]>middle)
                    nump=0;
                else {
                    nump=1;
                    mpid[p].push_back(id++);
                }
            }
        else nump=1;
        dc.addedge(mpid[r][numr],mpid[p][nump],10000);//在 plug 中 r->p
    }
    map<string,vector<int> >::iterator ip1;
    for(ip1=mpid.begin();ip1!=mpid.end();ip1++)
    {
        if((ip1->second).size()==2)
        {
            dc.addedge((ip1->second).at(1),(ip1->second).at(0),cap[(ip1->second).at(0)]);
        }
    }
    int ans=m-dc.maxflow(0,520);
    cout<<ans<<endl;
    return 0;
}

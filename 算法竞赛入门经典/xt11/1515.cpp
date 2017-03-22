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


const int maxn=2550;
const int inf=0x7fffffff;
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
}tmp;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
char mp[60][60];
int main(){
    int t,n,m,d,f,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&m,&n);
        scanf("%d %d %d",&d,&f,&b);
        tmp.init(n*m+10);
        long long res=0;
        for(int i=0;i<n;i++)
            scanf("%s",mp[i]);
        for(int i=0;i<m;i++)
        {
            if(mp[0][i]=='.')
            {
                mp[0][i]='#';
                res+=f;
            }
            if(mp[n-1][i]=='.')
            {
                mp[n-1][i]='#';
                res+=f;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(mp[i][0]=='.')
            {
                mp[i][0]='#';
                res+=f;
            }
            if(mp[i][m-1]=='.')
            {
                mp[i][m-1]='#';
                res+=f;
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
            if(i==0||i==n-1||j==0||j==m-1)
                {
                tmp.addedge(0,i*m+j+1,inf);
                }
            else{
                if(mp[i][j]=='#')
                    tmp.addedge(0,i*m+j+1,d);
                else tmp.addedge(i*m+j+1,n*m+1,f);
            }
            for(int k=0;k<4;k++)
                {
                    int ti=i+dx[k];
                    int tj=j+dy[k];
                    if(ti<0||tj<0||ti>=n||tj>=m)
                        continue;
                    tmp.addedge(i*m+j+1,ti*m+tj+1,b);
                }
            }
        res+=tmp.maxflow(0,n*m+1);
        cout<<res<<endl;
    }
    return 0;
}

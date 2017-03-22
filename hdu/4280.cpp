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

struct Edge{
    int from,to,cap,flow;
};
const int maxn=100010;
const int INF=0x7fffffff;
struct ISAP{
    int n,m,s,t;//结点数，边数（包括反向弧），源点编号，汇点编号
    vector<Edge>edges;
    vector<int>G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];
    int p[maxn];
    int num[maxn];
    void init(int x){
        for(int i=0;i<x;i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from,int to,int cap){
        edges.push_back((Edge){from,to,cap,0});
        edges.push_back((Edge){to,from,0,0});
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    bool RevBFS(){
        memset(vis,0,sizeof(vis));
        queue<int>Q;
        Q.push(t);
        d[t]=0;
        vis[t]=1;
        while(!Q.empty()){
            int x=Q.front();Q.pop();
            for(int i=0;i<G[x].size();i++){
                Edge &e =edges[G[x][i]^1];
                if(!vis[e.from]&&e.cap>e.flow){
                    vis[e.from]=1;
                    d[e.from]=d[x]+1;
                    Q.push(e.from);
                }
            }
        }
        return vis[s];
    }
    int Augment(){
        int x=t, a=INF;
        while(x!=s){
            Edge &e = edges[p[x]];
            a= min(a,e.cap-e.flow);
            x=edges[p[x]].from;
        }
        x=t;
        while(x!=s){
            edges[p[x]].flow+=a;
            edges[p[x]^1].flow-=a;
            x=edges[p[x]].from;
        }
        return a;
    }
    long long Maxflow(int s,int t,int n){
        this->s=s,this->t=t,this->n=n;
        long long flow=0;
        RevBFS();
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++){
            num[d[i]]++;
        }
        int x=s;
        memset(cur,0,sizeof(cur));
        while(d[s]<n){
            if(x==t){
                flow+=Augment();
                x=s;
            }
            int ok=0;
            for(int i=cur[x];i<G[x].size();i++){
                Edge &e =edges[G[x][i]];
                if(e.cap>e.flow&&d[x]==d[e.to]+1){
                    ok=1;
                    p[e.to]=G[x][i];
                    cur[x]=i;
                    x=e.to;
                    break;
                }
            }
            if(!ok){
                int m=n-1;
                for(int i=0;i<G[x].size();i++){
                    Edge &e =edges[G[x][i]];
                    if(e.cap>e.flow)
                        m=min(m,d[e.to]);
                }
                if(--num[d[x]]==0)
                    break;
                num[d[x]=m+1]++;
                cur[x]=0;
                if(x!=s)
                    x=edges[p[x]].from;
            }
        }
        return flow;
    }
}tmp;
int main(){
    int t,n,m,a,b,c;
    long long res;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        int lef,rig;
        tmp.init(n+5);
        int maxx=-INF,minn=INF;
        for(int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            if(x>maxx) {maxx=x;rig=i;}
            if(x<minn) {minn=x;lef=i;}
        }
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            tmp.AddEdge(a,b,c);
            tmp.AddEdge(b,a,c);
        }
        res=tmp.Maxflow(lef,rig,n);
        cout<<res<<endl;
    }
    return 0;
}

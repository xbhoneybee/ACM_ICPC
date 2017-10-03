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

using namespace std;

//M

const int Maxv=2100006;
struct Edge
{
    int from;
    int to;
    long long weight;
    Edge(int f, int t, long long w):from(f), to(t), weight(w) {}
};
vector<int> G[Maxv];
vector<Edge> edges;
struct State{
int AB;
long long time;
int pos;
State(int c,long long t,int p):AB(c),time(t),pos(p){}
friend bool operator < (const State &t1, const State &t2){
return t1.time > t2.time; // 按照z 的顺序来决定t1 和t2 的顺序
}
};
priority_queue<State>que;
map<int,long long>book[2];
set<int>vec;
long long minT=1e18;
bool vis[2][Maxv];
int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<=n+m;i++)
            G[i].clear();
        edges.clear();
        for(int i=1;i<=m;i++)
        {
            int nums,newp=i+n;
            long long w;
            scanf("%I64d %d",&w,&nums);
            for(int j=0;j<nums;j++)
            {
                int u;
                scanf("%d",&u);
                edges.push_back(Edge(u,newp,w));
                G[u].push_back(edges.size()-1);
                edges.push_back(Edge(newp,u,0));
                G[newp].push_back(edges.size()-1);
            }
        }
        while(!que.empty())
            que.pop();
        book[0].clear();book[1].clear();
        minT=1e18;
        vec.clear();
        memset(vis,false,sizeof vis);
        que.push(State(0,0,1));
        que.push(State(1,0,n));
        book[0][1]=0;
        book[1][n]=0;
        vis[0][1]=vis[1][n]=true;
        while(!que.empty())
        {
            State head=que.top();
            que.pop();
            //cout<<"cur pos"<<head.pos<<" stAB "<<head.AB<<" "<<" time "<<head.time<<endl;
            if(book[head.AB^1].count(head.pos))
            {
                long long other=book[head.AB^1][head.pos];
                if(max(other,head.time)<minT)
                {
                    vec.clear();
                    if(head.pos<=n)
                    vec.insert(head.pos);
                    minT=max(other,head.time);
                }else if(max(other,head.time)==minT)
                {
                    if(head.pos<=n)
                    vec.insert(head.pos);
                }
            }

            //没找到继续BFS
            for(int e=0;e<G[head.pos].size();e++)
            {
                int to_p=edges[G[head.pos][e]].to;
                if(vis[head.AB][to_p]==true)
                    continue;
                vis[head.AB][to_p]=true;
                long long cost=head.time+edges[G[head.pos][e]].weight;
                que.push(State(head.AB,cost,to_p));
                book[head.AB][to_p]=cost;
            }

        }
        printf("Case #%d: ",cas++);
        if(vec.size()==0)
            printf("Evil John\n");
        else {
            printf("%I64d\n",minT);
            for(set<int>::iterator ipv=vec.begin();ipv!=vec.end();ipv++)
            {
                if(ipv!=vec.begin())
                    printf(" ");
                printf("%d",*ipv);
            }
            printf("\n");
        }
    }
    return 0;
}

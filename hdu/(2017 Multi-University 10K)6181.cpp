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

using namespace std;

const int maxn = 100000 + 5;
const int maxm =100000 + 5;
const long long INF = 1e18;
struct P{
    int to;
    long long dis;
    P() {}
    P(int _to, long long _dis) : to(_to), dis(_dis) {}
    friend bool operator<(P a, P b) { return a.dis > b.dis; }
};

struct Edge{
    int u, v, next;
    long long dis;
};

int n, m;
int a, b, num;
long long c;
int head[maxn];
Edge edge[maxm * 2];
long long sum1[maxn];
long long  dist1[maxn], dist2[maxn];

void addEdge(int u, int v, long long dis){
    edge[num].u = u;
    edge[num].v = v;
    edge[num].dis = dis;
    edge[num].next = head[u];
    head[u] = num++;
}

void input(){
    scanf("%d%d", &n, &m);
    num = 0;
    memset(head, -1, sizeof(head));
    for(int i = 0; i < m; i++){
        scanf("%d %d %I64d", &a, &b, &c);
        addEdge(a, b, c);
        addEdge(b, a, c);
    }
}

void dijkstra(long long dist[], ll sumt[], int s){
    fill(dist + 1, dist + 1 + n, INF);
    fill(sumt + 1, sumt + 1 + n, 0);
    fill(dist2 + 1, dist2 + 1 + n, INF);
    priority_queue <P> q;
    while(!q.empty()) q.pop();

    dist[s] = 0; sumt[s] = 1;
    q.push(P(s, 0));

    while(!q.empty()){
        P p = q.top(); q.pop();
        int u = p.to;
        if(p.dis > dist2[u]) continue;
        for(int i = head[u]; i != -1; i = edge[i].next){
            int v = edge[i].v;
            long long d2=p.dis+edge[i].dis;
            if(dist[v]>d2)
            {
                swap(dist[v],d2);
                sumt[v] = sumt[u];
                q.push(P(v,dist[v]));
            }
            else if(dist[v] ==d2){
                sumt[v] =sumt[v] + sumt[u];
            }
            if(dist2[v]>d2&&dist[v]<d2)
            {
                dist2[v]=d2;
                q.push(P(v,dist2[v]));
            }
        }
    }
}
void solve(){
    dijkstra(dist1, sum1, 1);
    if(sum1[n]>1)
    printf("%I64d\n",dist1[n]);
    else
    printf("%I64d\n",dist2[n]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        input();
        solve();
    }
    return 0;
}

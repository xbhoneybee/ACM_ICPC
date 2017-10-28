#include <bits/stdc++.h>
#include<sstream>
#include<ctime>
#define iosfalse ios::sync_with_stdio(false);
using namespace std;


#define N 1010
#define INF 0x7fffffff

vector<int>Edge[N];
struct P
{
    long long x, y, r;
    int  c;
}p[N];
int belong[N], vis[N], cnt, num, dfn[N], low[N], in[N];
int cost[N];
stack<int> sta;

void init() {
    cnt = num = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(belong, 0, sizeof(belong));
    memset(vis, 0, sizeof(vis));
    memset(in, 0, sizeof(in));
    while(sta.size()) sta.pop();
}

bool Conc(int from,int to)
{
    long long dist=(p[from].x-p[to].x)*(p[from].x-p[to].x)
    +(p[from].y-p[to].y)*(p[from].y-p[to].y);
    if(dist<=p[from].r*p[from].r)
        return true;
    return false;
}
void tarjan(int u) {
    vis[u] = 1;
    sta.push(u);
    dfn[u] = low[u] = ++cnt;
    for(int i = 0; i<Edge[u].size(); i++) {
        int v=Edge[u][i];
        if(!dfn[v]) {
            tarjan(v);
            if(low[v] < low[u]) low[u] = low[v];
        } else if(vis[v]) {
            if(dfn[v] < low[u]) low[u] = dfn[v];
        }
    }
    if(dfn[u] == low[u]) {
        ++num;
        while(true) {
            int v = sta.top(); sta.pop();
            belong[v] = num; vis[v] = 0;
            cost[num]=min(cost[num],p[v].c);
            if(v == u) break;
        }
    }
}

int main()
{
    iosfalse
    int t, cas = 1;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        init();
        for(int i=1;i<=n;i++)
            {
                Edge[i].clear();
                cost[i]=1e8;
            }
        for(int i=1;i<=n;i++)
        {
            cin>>p[i].x>>p[i].y>>p[i].r>>p[i].c;
            for(int j=1;j<i;j++)
            {
                if(Conc(i,j))
                    Edge[i].push_back(j);
                if(Conc(j,i))
                    Edge[j].push_back(i);
            }
        }
        for(int i = 1; i <= n; i++)
         if(!dfn[i]) tarjan(i);
        for(int u = 1; u <= n; u++) {
            for(int i = 0; i<Edge[u].size(); i++) {
                int v = Edge[u][i];
                if(belong[u] != belong[v]) {
                    in[belong[v]]++;
                }
            }
        }
        long long ans = 0;
        for(int i = 1; i <= num; i++) {
            if(in[i] == 0) {
                ans += cost[i];
            }
        }
        cout<<"Case #"<<cas++<<": "<<ans<<endl;
    }
    return 0;
}

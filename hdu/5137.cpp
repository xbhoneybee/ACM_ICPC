#include<bits/stdc++.h>
#include <iostream>
using namespace std;



//K
const int INF = 0x3f3f3f3f;
const int maxn = 30 + 5;
struct Edge {
    int from, to, dist;
};
struct SPFA {
    int d[maxn], cnt[maxn], p[maxn];
    int n, m;
    bool inq[maxn];
    vector<int> G[maxn];
    vector<Edge> edges;

    void init(int n) {
        this->n = n;
        for (int i = 1; i <= n; ++i) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int dist) {
        edges.push_back(Edge{from, to, dist});
        int m = edges.size();
        G[from].push_back(m-1);
    }

    bool spfa(int s) {
        for(int i=0;i<=n;i++)
            d[i]=INF;
        memset(cnt,0,sizeof cnt);
        memset(inq,0,sizeof inq);
        d[s] = 0;
        queue<int> q;
        q.push(s);
        inq[s] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            inq[u] = false;
            for (int i = 0; i < G[u].size(); ++i) {
                Edge &e = edges[G[u][i]];
                if (d[e.to] > d[u] + e.dist) {
                    d[e.to] = d[u] + e.dist;
                    p[e.to] = G[u][i];
                    if (!inq[e.to]) {
                        q.push(e.to); inq[e.to] = true;
                        if (++cnt[e.to] > n) return false;
                    }
                }
            }
        }
        return true;
    }

};

SPFA solver;

int main() {
    int n, m, a, b, c;
    while(cin >> n >> m&&n&&m) {
        solver.init(n);
        while(m--) {
            cin >> a >> b >> c;
            solver.AddEdge(a, b, c);
            solver.AddEdge(b, a, c);
        }
        int ans=0;
        for(int i=2;i<n;i++)
        {
            vector<int>cpy;
            for(int j=0;j<solver.G[i].size();j++)
            {
                cpy.push_back(solver.G[i][j]);
            }
            solver.G[i].clear();
            solver.spfa(1);
            ans=max(ans,solver.d[n]);
            for(int j=0;j<cpy.size();j++)
                solver.G[i].push_back(cpy[j]);
        }
        if(ans<INF)
        cout << ans << endl;
        else cout<<"Inf"<<endl;
    }
    return 0;
}

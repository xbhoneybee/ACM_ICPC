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


/**
这题本来看完后以为和百度之星一样是费用流，准备建图。队友说可以dfs扫一遍，我们发现扫2遍：一遍在这里卖掉或者从这里买一个算一下。反向扫一下即可。
*/
const int maxn = 100005;
int val[maxn];
int n;
struct Edge
{
    int from;
    int to;
    int weight;
    Edge(int f, int t, int w) :from(f), to(t), weight(w) {}
};
vector<int> G[maxn];
vector<Edge> edges;
int getmon;
void dfs1(int rt, int fa, int curmon)
{
    getmon = max(getmon, val[rt] + curmon);//getmon 当前可获利值 不卖和卖
    curmon = max(curmon, -val[rt]);//curmon当前资金值 现在这里买东西，到别处卖掉
    for (int i = 0; i<G[rt].size(); i++)
    {
        int son = edges[G[rt][i]].to;
        if (son == fa)
            continue;
        dfs1(son, rt, curmon - edges[G[rt][i]].weight);
    }
}//这次dfs会忽略在dfs起点卖东西的方案，所以有了dfs2
void dfs2(int rt, int fa, int curmon)
{
    getmon = max(getmon, -val[rt] + curmon);//  这里不买和买  
    curmon = max(curmon, val[rt]);
    for (int i = 0; i<G[rt].size(); i++)
    {
        int son = edges[G[rt][i]].to;
        if (son == fa)
            continue;
        dfs2(son, rt, curmon - edges[G[rt][i]].weight);
    }

}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &val[i]);
            G[i].clear();
        }
        edges.clear();
        for (int i = 1; i<n; i++)
        {
            int u, v, s;
            scanf("%d %d %d", &u, &v, &s);
            edges.push_back(Edge(u, v, s));
            G[u].push_back(edges.size() - 1);
            edges.push_back(Edge(v, u, s));
            G[v].push_back(edges.size() - 1);
        }
        int ans = 0;
        getmon = 0;
        dfs1(1, 0, -100000000);
        ans = max(ans, getmon);
        getmon = 0;
        dfs2(1, 0, 0);
        ans = max(ans, getmon);
        printf("%d\n", ans);
    }
    return 0;
}

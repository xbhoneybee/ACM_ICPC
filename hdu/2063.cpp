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
//裸最大匹配 AC

const int maxn=1005;
struct Edge
{
    int from;
    int to;
    Edge(int f, int t):from(f), to(t) {}
};
vector<int> G[maxn];
vector<Edge> edges;
typedef vector<int>::iterator iterator_t;
int num_left;//左节点以0开始，右节点以num_left开始；
int matching[maxn];
int check[maxn]; //每次清零标记是否在路中
bool dfs(int u)
{
    for (iterator_t i = G[u].begin(); i != G[u].end(); ++i) { // 对 u 的每个邻接点
        int v = edges[*i].to;
        if (!check[v]) {     // 要求不在交替路中
            check[v] = true; // 放入交替路
            if (matching[v] == -1 || dfs(matching[v])) {
                // 如果是未盖点，说明交替路为增广路，则交换路径，并返回成功
                matching[v] = u;
                matching[u] = v;
                return true;
            }
        }
    }
    return false; // 不存在增广路，返回失败
}
int hungarian()
{
    int ans = 0;
    memset(matching, -1, sizeof(matching));
    for (int u=0; u < num_left; ++u) {
        if (matching[u] == -1) {
            memset(check, 0, sizeof(check));
            if (dfs(u))
                ++ans;
        }
    }
    return ans;
}
int main()
{
    int k,n,m;
    while(scanf("%d",&k)!=EOF)
    {
        if(k==0)
            break;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n+m+1;i++)
            G[i].clear();
        edges.clear();
        num_left=n;
        for(int i=0;i<k;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            a--;
            b--;
            b+=num_left;
            edges.push_back(Edge(a,b));
            G[a].push_back(edges.size()-1);
            edges.push_back(Edge(b,a));
            G[b].push_back(edges.size()-1);
        }
        printf("%d\n",hungarian());
    }
    return 0;
}

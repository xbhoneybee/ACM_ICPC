#include <bits/stdc++.h>
#include<sstream>
#include<ctime>
#define iosfalse ios::sync_with_stdio(false);

using namespace std;

struct Edge
{
    int from;
    int to;
    Edge(int f, int t):from(f), to(t){}
};
vector<int> G[300];
vector<Edge> edges;
typedef vector<int>::iterator iterator_t;
int num_left;
int matching[300];
int check[300];
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
string str[101];
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        string goal;
        cin>>goal;
        for(int i=0;i<=300;i++)
            G[i].clear();
        edges.clear();
        for(int i=0;i<n;i++)
            cin>>str[i];
        num_left=n;
        for(int i=0;i<n;i++)
        {
            bool had[30];
            memset(had,false,sizeof had);
            for(int j=0;j<str[i].size();j++)
            {
               had[str[i][j]-'a']=true;
            }
            for(int k=0;k<goal.size();k++)
                {
                    if(had[goal[k]-'a'])
                    {
                    edges.push_back(Edge(k+n,i));
                    G[k+n].push_back(edges.size()-1);
                    edges.push_back(Edge(i,n+k));
                    G[i].push_back(edges.size()-1);
                    }
                }
        }
        if(hungarian()==goal.size())
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

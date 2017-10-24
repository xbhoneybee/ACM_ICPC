#include <bits/stdc++.h>
#include<sstream>
#include<ctime>
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

//A

const int Ni = 200;
const int INF = 1<<30;
struct node{
    int to,d,raind;
    node(){}
    node(int a,int b,int c){to=a;d=b;raind=c;}
    bool operator < (const node & a) const
    {
        if(raind==a.raind) return to<a.to;
        else return raind > a.raind;
    }
};
vector<node> edges[Ni];
int dis[Ni],n;
int disd[Ni];
int T,m1,m2,L;
void Dijkstra(int s)
{
    int i;
    for(i=0;i<=n;i++)
        {
            dis[i]=INF;
            disd[i]=INF;
        }
    dis[s]=0;
    disd[s]=0;
    //用优先队列优化
    priority_queue<node> q;
    q.push(node(s,dis[s],disd[s]));
    while(!q.empty())
    {
        node head=q.top();q.pop();
        for(i=0;i<edges[head.to].size();i++)
        {
            node y=edges[head.to][i];
            if(dis[y.to]>head.raind+y.raind&&head.d+y.d<=L)
            {
                dis[y.to]=head.raind+y.raind;

                q.push(node(y.to,head.d+y.d,dis[y.to]));
            }
        }
    }
}
int main()
{
    iosfalse
    cin>>T;
    while(T--)
    {
        cin>>n>>m1>>m2>>L;
        for(int i=0;i<=n;i++)
            edges[i].clear();
        for(int i=0;i<m1;i++)
        {
            int a,b;
            cin>>a>>b;
            edges[a].push_back(node(b,1,0));
            edges[b].push_back(node(a,1,0));
        }
        for(int i=0;i<m2;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            edges[a].push_back(node(b,c,c));
            edges[b].push_back(node(a,c,c));
        }
        Dijkstra(1);
        if(dis[n]==INF)
            dis[n]=-1;
        cout<<dis[n]<<endl;
    }
    return 0;
}

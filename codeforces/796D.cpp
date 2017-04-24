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
#define lowbit(x) x&-x

using namespace std;

//cf div2 408 D

struct Edge{
int from,to,id;
bool aped;
Edge(int u,int v,int i)
{from=u;to=v;id=i;aped=false;}
};
vector<Edge>edges;
vector<int>G[300005];
bool vis[300005];
int main()
{
    iosfalse
    int n,k,d;
    cin>>n>>k>>d;
    queue<int>que;
    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        que.push(x);
        vis[x]=true;
    }
    int cnt=1;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        edges.push_back(Edge(u,v,cnt));
        G[u].push_back(edges.size()-1);
        edges.push_back(Edge(v,u,cnt++));
        G[v].push_back(edges.size()-1);
    }
    set<int>deledge;
    while(!que.empty())
    {
        int head=que.front();
        que.pop();
        for(int j=0;j<G[head].size();j++)
           {
               int to=edges[G[head][j]].to;
               if(edges[G[head][j]].aped)
                continue;
               edges[G[head][j]].aped=true;
               edges[G[head][j]^1].aped=true;
               if(vis[to]==false)
               {
                   vis[to]=true;
                   que.push(to);
               }else{
                    deledge.insert(edges[G[head][j]].id);
               }
           }
    }
    cout<<deledge.size()<<endl;
    set<int>::iterator ip;
    for(ip=deledge.begin();ip!=deledge.end();ip++)
        cout<<*ip<<" ";
    cout<<endl;
    return 0;
}

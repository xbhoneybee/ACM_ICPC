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
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
const int inf=1e9;
using namespace std;

/// 2种颜色染色二分图右顶点集

const int __maxNodes=200005;
struct Edge
{
    int from;
    int to;
    int weight;
    Edge(int f, int t, int w):from(f), to(t), weight(w) {}
};
vector<int> G[__maxNodes];
vector<Edge> edges;
typedef vector<int>::iterator iterator_t;
int num_edges;
int num_left;
int num_right;//左节点以0开始，右节点以num_left开始；
int state[__maxNodes];
int ans=1;
void solve(int door)
{
    int to_p1=edges[G[door][0]].to;
    int to_p2=edges[G[door][1]].to;
    if(state[door]==0)
    {
        if(state[to_p1]==-1&&state[to_p2]==-1)
            {
                state[to_p1]=0;state[to_p2]=1;
                for(int i=0;i<G[to_p1].size();i++)
                {
                    solve(edges[G[to_p1][i]].to);
                }
                for(int i=0;i<G[to_p2].size();i++)
                {
                    solve(edges[G[to_p2][i]].to);
                }
            }
        else if(state[to_p1]==-1)
            {
                state[to_p1]= state[to_p2]==0?1:0;
                for(int i=0;i<G[to_p1].size();i++)
                {
                    solve(edges[G[to_p1][i]].to);
                }
            }
        else if(state[to_p2]==-1)
            {
                state[to_p2]= state[to_p1]==0?1:0;
                for(int i=0;i<G[to_p2].size();i++)
                {
                    solve(edges[G[to_p2][i]].to);
                }
            }
        else if(state[to_p2]==state[to_p1])
        {
            ans=0;return;
        }
    }else {
        if(state[to_p1]==-1)
            {
                state[to_p1]=state[to_p2];
                for(int i=0;i<G[to_p1].size();i++)
                {
                    solve(edges[G[to_p1][i]].to);
                }
            }
        else if(state[to_p2]==-1)
            {
                state[to_p2]= state[to_p1];
                for(int i=0;i<G[to_p2].size();i++)
                {
                    solve(edges[G[to_p2][i]].to);
                }
            }
        else if(state[to_p2]!=state[to_p1])
        {
            ans=0;return;
        }
    }
}
int main()
{
    cin>>num_left>>num_right;
    memset(state,-1,sizeof state);
    for(int i=0;i<num_left;i++)
        cin>>state[i];
    for(int i=0;i<num_right;i++)
    {
        int m;
        cin>>m;
        for(int j=0;j<m;j++)
        {
            int door;
            cin>>door;
            door--;
            G[door].push_back(num_edges++);
            edges.push_back(Edge(door,i+num_left,1));
            G[i+num_left].push_back(num_edges++);
            edges.push_back(Edge(i+num_left,door,1));
        }
    }
    for(int i=0;i<num_left;i++)
        if(state[i]==0&&ans==1)
        {
            solve(i);
        }
    if(ans==1)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

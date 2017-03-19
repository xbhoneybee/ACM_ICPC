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


const int __maxNodes=150001;
int pre[__maxNodes];
long long number[__maxNodes];
int findfater(int x)
{
    int r=x;
    while(pre[r]!=r)
        r=pre[r];
    int i=x,j;
    while(i!=r)//路径压缩（注意路径压缩后的并查集树深度不是1！！！）
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
void join(int x,int y)
{
    int fx=findfater(x),fy=findfater(y);
    if(fx==fy) {

        return;
    }
    pre[fy]=fx;
}
void initial(int n)
{
    for(int i=1;i<=n;i++)
        pre[i]=i;
}
struct Edge
{
    int from;
    int to;
    int weight;
    Edge(int f, int t, int w):from(f), to(t), weight(w) {}
};
vector<int> G[__maxNodes];
vector<Edge> edges;
int num_edges;
int vis[__maxNodes];
int main()
{
    int n,m;
    cin>>n>>m;
    bool isok=true;
    initial(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        join(a,b);
        edges.push_back(Edge(a,b,1));
        G[a].push_back(num_edges++);
        edges.push_back(Edge(b,a,1));
        G[b].push_back(num_edges++);
    }
    for(int i=1;i<=n;i++)
    {
        int fa=findfater(i);
        if(fa!=i)
        number[fa]++;
    }
    for(int i=1;i<=n;i++)
    {
        int fa=findfater(i);
        if((G[i].size()!=G[fa].size())||(G[i].size()!=number[fa]))
        {
            //cout<<G[i].size()<<" "<<G[fa].size()<<" "<<number[fa]<<endl;
            isok=false;
            break;
        }
    }
    if(isok)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

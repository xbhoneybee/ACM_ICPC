#include <bits/stdc++.h>
#include<sstream>
#include<ctime>
#define iosfalse ios::sync_with_stdio(false);
#define Pair pair<int,int>
using namespace std;
const int maxn=10005;
vector<int>G[maxn];
bool vis[maxn];
int n,m;
int main()
{
    iosfalse
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
    }
    queue<pair<int,int> >que;
    Pair p=make_pair(1,0);
    que.push(p);
    int ans=-1;
    while(!que.empty())
    {
        Pair head=que.front();
        que.pop();
        for(int i=0;i<G[head.first].size();i++)
        {
            if(G[head.first][i]==1)
                {
                   ans=head.second+1;
                   break;
                }
            if(!vis[G[head.first][i]])
            que.push(make_pair(G[head.first][i],head.second+1));
            vis[G[head.first][i]]=true;
        }
        if(ans>0)
            break;
    }
    cout<<ans<<endl;
    return 0;
}

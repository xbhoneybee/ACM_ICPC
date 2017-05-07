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
//B
//写的很蠢

char mp[505][505];
bool vis[505][505][4];
int n,m;
struct P{
int x,y;
int tox,toy;
int step;
friend bool operator < (const P &t1, const P &t2){
return t1.step > t2.step; // 按照z 的顺序来决定t1 和t2 的顺序
}
};
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int getdit(int x,int y)
{
    if(x==0&&y==1)
        return 0;
    if(x==0&&y==-1)
        return 1;
    if(x==-1&&y==0)
        return 2;
    if(x==1&&y==0)
        return 3;
}
int solve(int x,int y)
{
    priority_queue<P>que;//改成优先队列AC
    for(int i=0;i<4;i++)
        vis[x][y][i]=true;
    for(int t=0;t<4;t++)
    {
        int tx=x+dx[t];
        int ty=y+dy[t];
        if(tx<0||ty<0||tx>=n||ty>=m||mp[tx][ty]=='#')
            continue;
        if(mp[tx][ty]=='T')
            return 0;
        P p;
        p.step=0;
        p.tox=dx[t];
        p.toy=dy[t];
        p.x=tx;
        p.y=ty;
        que.push(p);
    }

    int ans=100000000;
    while(!que.empty())
    {
        P head=que.top();
        que.pop();
        int dit=getdit(head.tox,head.toy);
        vis[head.x][head.y][dit]=true;
        if(head.x+head.tox<0||head.y+head.toy<0||head.x+head.tox>=n||head.y+head.toy>=m||mp[head.x+head.tox][head.y+head.toy]=='#')
        {
            for(int t=0;t<4;t++)
            {
                if(t==dit||(dx[t]+dx[dit]==0&&dy[t]+dy[dit]==0))
                    continue;
                int tx=head.x+dx[t];
                int ty=head.y+dy[t];
                if(tx<0||ty<0||tx>=n||ty>=m||mp[tx][ty]=='#')
                    continue;
                if(mp[tx][ty]=='T')
                    {
                        ans=min(ans,head.step+1);
                        continue;
                    }
                    P p;
                    p.step=head.step+1;
                    p.tox=dx[t];
                    p.toy=dy[t];
                    p.x=tx;
                    p.y=ty;
                    if(vis[p.x][p.y][t]==false)
                    que.push(p);
            }
        }
        else if(mp[head.x+head.tox][head.y+head.toy]=='T')
        {
            ans=min(ans,head.step);
        }
        else
        {
            head.x=head.x+head.tox;
            head.y=head.y+head.toy;
            if(vis[head.x][head.y][dit]==false)
            que.push(head);
        }
    }
    if(ans==100000000)
        ans=-1;
    return ans;
}
int main()
{
    iosfalse
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>mp[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mp[i][j]=='S')
            {
                int ans=solve(i,j);
                cout<<ans<<endl;
                return 0;
            }
        }
    }
    return 0;
}

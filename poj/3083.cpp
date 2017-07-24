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


//c++ ac,g++wa

int T;
char mp[50][50];
int vis[50][50];
int from[50][50];
int dx[]={-1,0,1,0};//现在left=(之前方向+4-1)%4
int dy[]={0,-1,0,1};//现在right=(之前方向+1)%4
int w,h;
int endx,endy,stax,stay;
int bfs()
{
    //二坐标[y][x]
    memset(vis,0,sizeof vis);
    queue<pair<int,int> >que;
    que.push(make_pair(stay,stax));
    vis[stay][stax]=1;
    while(!que.empty())
    {
        pair<int,int>head=que.front();
        que.pop();
        for(int t=0;t<4;t++)
        {
            int tx=head.second+dx[t];
            int ty=head.first+dy[t];
            if(tx<0||tx>=w||ty<0||ty>=h||mp[ty][tx]=='#'||vis[ty][tx]>0)
                continue;
            vis[ty][tx]=vis[head.first][head.second]+1;
            if(mp[ty][tx]=='E')
            {
                return vis[endy][endx]-vis[stay][stax]+1;
            }
            que.push(make_pair(ty,tx));
        }
    }
}
int lrfs(int clocks)
{
    memset(vis,0,sizeof vis);
    memset(from,-1,sizeof from);
    stack<pair<int,int> >que;
    que.push(make_pair(stay,stax));
    vis[stay][stax]=1;
    while(!que.empty())
    {
        pair<int,int>head=que.top();
        que.pop();
        if(from[head.first][head.second]==-1)
        {
            for(int t=0;t<4;t++)
            {
            int tx=head.second+dx[t];
            int ty=head.first+dy[t];
            if(tx<0||tx>=w||ty<0||ty>=h||mp[ty][tx]=='#')
                continue;
            vis[ty][tx]=vis[head.first][head.second]+1;
            que.push(make_pair(ty,tx));
            from[ty][tx]=t;
            if(mp[ty][tx]=='E')
                {
                return vis[endy][endx]-vis[stay][stax]+1;
                }
            break;
            }
        }else {
            for(int t=from[head.first][head.second]+clocks,it=0;it<4;it++)
            {
            t=(t+4)%4;
            int tx=head.second+dx[t];
            int ty=head.first+dy[t];
            if(tx<0||tx>=w||ty<0||ty>=h||mp[ty][tx]=='#')
                {
                    t=(t-clocks+4)%4;
                    continue;
                }
            vis[ty][tx]=vis[head.first][head.second]+1;
            from[ty][tx]=t;
            que.push(make_pair(ty,tx));
            if(mp[ty][tx]=='E')
                {
                return vis[endy][endx]-vis[stay][stax]+1;
                }
            }
        }
    }
}
int main()
{
    iosfalse
    cin>>T;
    while(T--){
        memset(mp,0,sizeof mp);
        cin>>w>>h;
        for(int i=0;i<h;i++)
            cin>>mp[i];
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
        {
            if(mp[i][j]=='S')
            {
                stax=j;stay=i;
            }
            if(mp[i][j]=='E')
            {
                endx=j;endy=i;
            }
        }
        int thr=bfs();
        int fir=lrfs(-1);
        int sec=lrfs(1);
        cout<<fir<<" "<<sec<<" "<<thr<<endl;
    }
    return 0;
}

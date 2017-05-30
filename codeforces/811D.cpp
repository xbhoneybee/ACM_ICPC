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

//交互题 bfs找路径,由于不能走到*，所以不能先测试是否changeUDLR
int n,m;
char mp[101][101];
bool vis[101][101];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};//0 R 1 L 2 D 3 U
short pre[105][105];
int goalx,goaly;
void bfs()
{
    queue<pair<short,short> >que;
    que.push(make_pair(1,1));
    while(!que.empty())
    {
        pair<short,short> p=que.front();
        que.pop();
        vis[p.first][p.second]=true;
        for(int t=0;t<4;t++)
        {
            int tx=p.first+dx[t];
            int ty=p.second+dy[t];
            if(tx<=0||ty<=0||tx>n||ty>m||mp[tx][ty]=='*')
                continue;
            if(mp[tx][ty]=='F')
            {
                pre[tx][ty]=t;
                goalx=tx;goaly=ty;
                return;
            }
            if(vis[tx][ty]==false)
                {
                    que.push(make_pair(tx,ty));
                    vis[tx][ty]=true;//sb了，bfs这里就可以加标记以免MLE
                    pre[tx][ty]=t;
                }
        }
    }
}
void getpre(int &x,int &y,int t)
{
    if(t==0)
    {
        y--;
    }else if(t==1)
    {
        y++;
    }else if(t==2)
    {
        x--;
    }else{
        x++;
    }
}
stack<short>path;
void getPath()
{
    int x=goalx;
    int y=goaly;
    while(x!=1||y!=1)
    {
        path.push(pre[x][y]);
        getpre(x,y,pre[x][y]);
    }
}
bool changeLR=false,changeUD=false;
char getcc(int t)
{
    if(t==0)
    {
        if(changeLR)
            return 'L';
        else return 'R';
    }else if(t==1)
    {
        if(changeLR)
            return 'R';
        else return 'L';
    }else if(t==2)
    {
         if(changeUD)
            return 'U';
        else return 'D';
    }else {
        if(changeUD)
            return 'D';
        else return 'U';
    }
}
int main()
{
    cin>>n>>m;
    string str;
    for(int i=1;i<=n;i++)
        {
            cin>>mp[i]+1;
        }
    bfs();
    getPath();
    int curx=1,cury=1;
    int getx,gety;
    while(!path.empty())
    {
        char ch=getcc(path.top());
        cout<<ch<<endl;
        //fflush(stdout);
        cin>>getx>>gety;
        curx+=dx[path.top()];
        cury+=dy[path.top()];
        if(getx==curx&&gety==cury)
            path.pop();
        else {
            curx-=dx[path.top()];
            cury-=dy[path.top()];
            if(path.top()<2)
                changeLR=true;
            else changeUD=true;
        }
    }

    return 0;
}

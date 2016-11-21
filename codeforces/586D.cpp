#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<cstdlib>
#include <sstream>
#include <deque>
#include<list>
#include<time.h>
#define ll long long
#define LL long long
#define inf 1000000009
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

// add vis[][] store weather visited to prevent mle
char mp[3][105];
int vis[3][105];
int dx[]={-1,1,0};
int dy[]={0,0,0};
int n,k;
int stx,sty;
struct P
{
    int x,y;
};
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        int flag=0;
        memset(mp,0,sizeof mp);
        memset(vis,0,sizeof vis);
        for(int i=0;i<3;i++)
            scanf("%s",mp[i]);
        for(int i=0;i<3;i++)
            for(int j=0;j<n;j++)
                if(mp[i][j]=='s')
            {stx=i;sty=j;break;}
        for(int i=0;i<3;i++)
        {
            int len=strlen(mp[i]);
            mp[i][len]='.';
            mp[i][len+1]='.';
        }
            queue<P> q;
            for(int i=0;i<3;i++)
            {
                if(mp[stx][sty+1]=='.'){
                int tx=stx+dx[i];int ty=sty+1+dy[i];
                if(tx>=0&&tx<3&&ty>=0&&ty<n&&mp[tx][ty]=='.'&&mp[tx][ty+1]=='.'&&mp[tx][ty+2]=='.')
                {
                    P a;a.x=tx;a.y=ty+2;
                    q.push(a);
                    vis[a.x][a.y]=1;
                }
                }
            }
            while(!q.empty())
            {
                P ta=q.front();
                q.pop();
                if(ta.y>=n-1)
                {
                    flag=1;
                    break;
                }
                //cout<<ta.x<<"  "<<ta.y<<endl;
                for(int i=0;i<3;i++)
                {
                    if(mp[ta.x][ta.y+1]=='.'){
                int tx=ta.x+dx[i];int ty=ta.y+dy[i]+1;
                if(tx>=0&&tx<3&&ty>=0&&ty<n&&mp[tx][ty]=='.'&&mp[tx][ty+1]=='.'&&mp[tx][ty+2]=='.')
                {
                    P a;a.x=tx;a.y=ty+2;
                    if(vis[a.x][a.y]==0)
                    q.push(a),vis[a.x][a.y]=1;
                }
                    }
                }
            }
        if(flag==1)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}










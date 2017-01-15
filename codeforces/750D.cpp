#include <bits/stdc++.h>
#define ll long long
#define LL long long
#define inf 10000.00
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;
string getstring ( const int n )
{
std::stringstream newstr;
newstr<<n;
return newstr.str();
}
int getint ( string s )
{
return atoi(s.c_str());
}
//        0 1 2 3  4  5 6  7 8
int dx[]={0,0,0,-1,1,-1,1,-1,1};
int dy[]={0,1,-1,0,0,1,1,-1,-1};
void getdir(int now,int& n1,int& n2)
{
    switch(now){
    case 1:n1=5;n2=6;break;
    case 2:n1=7;n2=8;break;
    case 3:n1=5;n2=7;break;
    case 4:n1=6;n2=8;break;
    case 5:n1=1;n2=3;break;
    case 6:n1=1;n2=4;break;
    case 7:n1=3;n2=2;break;
    case 8:n1=2;n2=4;break;
    }
}
int mp[300][300];
int len[33];
int n;
struct P{
int x,y,state;
};
bool vis[300][300][9][6][32];// warning MLE
void explode(int i,P p,int cnt)
{
    if(vis[p.x][p.y][p.state][len[cnt]][cnt]==1)//without memory ,TLE 
        return ;
    vis[p.x][p.y][p.state][len[cnt]][cnt]=1;
    int x1=p.x;
    int y1=p.y;
    int x2=p.x;
    int y2=p.y;
    int change1,change2;
    getdir(p.state,change1,change2);
    for(int j=0;j<len[i];j++)
        {
            x1+=dx[change1];y1+=dy[change1];
            mp[x1][y1]=1;
            x2+=dx[change2];y2+=dy[change2];
            mp[x2][y2]=1;
        }
    P pp1,pp2;
    pp1.x=x1;pp1.y=y1;pp1.state=change1;
    pp2.x=x2;pp2.y=y2;pp2.state=change2;
    if(i+1<n)
    {
        explode(i+1,pp1,cnt+1);
        explode(i+1,pp2,cnt+1);
    }
}
int  main()
{
    scanf("%d",&n);
    int x=150,y=150;
    for(int i=0;i<n;i++)
        scanf("%d",&len[i]);
    for(int j=0;j<len[0];j++)
    {
        x+dx[1];y+=dy[1];
        mp[x][y]=1;
    }
    P p;
    p.x=x;p.y=y;p.state=1;
    memset(vis,0,sizeof vis);
    explode(1,p,0);
    int ans=0;
    for(int i=0;i<300;i++)
        for(int j=0;j<300;j++)
        if(mp[i][j]!=0)
        ans++;
   printf("%d\n",ans);
    return 0;
}

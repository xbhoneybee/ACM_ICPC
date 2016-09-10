#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<stdlib.h>
#include <sstream>
#include <deque>
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e18
#define lowbit(x) x&-x
using namespace std;
//一开始看错题，看成最短路了 宛如一个智障！
// change  spfa  使用矩阵存边,去掉重边
//light oj 1002
const int maxv=600;
int n,m;
int mp[maxv][maxv];
int flag[maxv];
int dminmax[maxv];
void Init()
{
    memset(mp,-1,sizeof mp);
    memset(flag, 0, sizeof(flag));
    memset(dminmax,-1,sizeof dminmax);
}
int spfa(int src)//src 起点
{
    queue<int> q;
    for(int i = 0; i <n; i++)
        dminmax[i] =-1;
    dminmax[src]=0;
    q.push(src);
    flag[src]=1;
    int tmk;
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        flag[x]=0;
        for(int i = 0; i<n; i++)
           if(mp[x][i]!=-1)
            {
                tmk=dminmax[i];
                if(dminmax[i]==-1)//如果首次访问某点
                    dminmax[i]=max(dminmax[x],mp[x][i]);
                else dminmax[i]=min(dminmax[i],max(dminmax[x],mp[x][i]));//再次访问
                if(tmk==dminmax[i])//未做修改则点不入队,否则会tle
                    continue;
                if(!flag[i])
                {
                flag[i] = 1;
                q.push(i);
                }
            }
    }
    return 0;
}
int main()
{
    int t,it=0,start;
    int a,b,c;
    scanf("%d",&t);
    while(t--)
    {
    Init();
    it++;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
       mp[a][b]=mp[b][a]=(mp[a][b]==-1? c : min(c,mp[a][b]));//因为求"某条路的最大边"之中的最小值,筛去较长边
    }
    scanf("%d",&start);
    spfa(start);
    printf("Case %d:\n",it);
    for(int i=0;i<n;i++)
    {
        if(dminmax[i]!=-1)
        printf("%d\n",dminmax[i]);
        else printf("Impossible\n");
    }
    }
    return 0;
}

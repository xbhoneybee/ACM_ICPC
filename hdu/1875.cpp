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
#define mod 1000000007
#define ll long long
#define LL long long
#define inf 100000000
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

//只需判断加入图的点是否等于n即知道是否为连通图

struct Node
{
    int fm,to;
    double dis;
}node[10005];
struct P
{
    int x,y;
}p[105];
int fa[105],n,numedge=0;
bool cmp(Node a,Node b)
{
    return a.dis < b.dis;
}
int getfa(int x){//getfa是在并查集森林中找到x的祖先
    if(fa[x]==x) return fa[x];
    else return fa[x] = getfa(fa[x]);
}
int same(int x,int y){
    return getfa(x)==getfa(y);
}
void merge(int x,int y)
{
    int fax=getfa(x),fay=getfa(y);
    fa[fax]=fay;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
    scanf("%d",&n);
    set<int> qt;
    for(int i=1;i<=n;i++)
    {
       scanf("%d%d",&p[i].x,&p[i].y);
       for(int j=1;j<i;j++)
       {
           double temdis=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
           if(temdis>=10&&temdis<=1000)
            {
                numedge++;
                qt.insert(i);
                qt.insert(j);
               node[numedge].fm=i;
               node[numedge].to=j;
               node[numedge].dis=temdis;

            }
       }
    }
    int ttt=qt.size();
    if(ttt!=n)
    {
        printf("oh!\n");
        continue;
    }
    sort(node+1,node+numedge+1,cmp);//对边按边权进行升序排序

    for(int i=1;i<=n;i++)
    fa[i]=i;   //并查集初始化
    int rst=n;
    double ans=0;//rst表示目前的点共存在于多少个集合中，初始情况是每个点都在不同的集合中
    for(int i=1;i<=numedge && rst>1;i++)
    {
        int x=node[i].fm,y=node[i].to;
        if(same(x,y)) continue;//same函数是查询两个点是否在同一集合中
        else
        {
            merge(x,y);//merge函数用来将两个点合并到同一集合中
            rst--;//每次将两个不同集合中的点合并，都将使rst值减1
            ans+=node[i].dis*100;//这条边是最小生成树中的边，将答案加上边权
        }
    }
    printf("%.1f\n",ans);
    numedge=0;
    }
    return 0;
}

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
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

//这道题比赛时不知道怎么把最坏情况时间从O(n^2)的dfs降低
//有很多种解法 树状数组/线段树+离散化 | 树堆Treap
//都是利用优先级排序后log查询满足k/a[i]数量
//treap 解法：
//树状数组解法：重点在如何将tree 依照权值变成数组对待
const int N=100005;
int c[N<<1];//开2倍？？？
void add(int i,int val,int n)//将第i个元素增加val注意i不可为零
{
     while(i<=n)//n为所开数组上界
     {          //注意这里新加变量n？？？？
         c[i]+=val;
         i+=lowbit(i);
     }
}
int sum(int i)//求前i项和
{
     int s=0;
     while(i>0)
     {
         s+=c[i];
         i-=lowbit(i);
     }
     return s;
}
LL n,k,ans,a[N<<1];//*2???
int xin;//???
vector<int> v[N];
int p[N<<1];//??

void dfs(int rt)//??
{
    int pos;
    pos=a[rt+n];//??
    ans+=sum(pos);
    add(a[rt],1,xin);
    for(int i=0;i<v[rt].size();i++)
    {
        int son=v[rt][i];
            dfs(son);
    }
    add(a[rt],-1,xin);

}
bool f[N];
bool cmp(int x,int y)
{
    return a[x]<a[y];//依照权值排序
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d %I64d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d",a+i);
            if(a[i]==0) a[n+i]=inf;
            else a[n+i]=k/a[i];
            p[i]=i;
            p[n+i]=n+i;
        }
        sort(p+1,p+n+n+1,cmp);  //离散化
        xin=0;
        int pre=-1;
        for(int i=1;i<=2*n;i++)
        {
            if(a[p[i]]>pre)
            {
                pre=a[p[i]];a[p[i]]=++xin;
            }else {
                pre=a[p[i]];a[p[i]]=xin;
            }
        }
        memset(f,0,sizeof f);
        for(int i=1;i<n;i++)
        {
            int u,y;
            scanf("%d %d",&u,&y);
            v[u].push_back(y);
            f[y]=1;//标记非根节点
        }
        memset(c,0,sizeof c);
        ans=0;
        for(int i=1;i<=n;i++)
        {
            if(f[i]==false)//找到根节点
            {
                dfs(i);break;
            }
        }
        printf("%I64d\n",ans);
        for(int i=1;i<=n;i++)
            v[i].clear();//注意依次clear

    }
    return 0;
}

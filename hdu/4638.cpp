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
#include <deque> //双端队列
#define mod 1000000007
#define ll long long
#define LL long long
#define inf 10000000000000
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e18
#define lowbit(x) x&-x
using namespace std;
//hdu4638
//分组和位置无关 比如 3 2 1 7 8 4 可以分 2 组
//首先应该想到要对所有询问离线处理，先预处理好[1, i]的结果
//还是不懂 需要再自己写一次
const int N=100050;
int c[N];
vector <int > e[N];
struct node {
int r ,num; //query 的 r 值和 次序
};
vector <node> q[N];
int m,n;
int sum (int x)
{
    int res=0;
    while(x>0)
    {
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}
void add(int x,int d)
{
    while(x<=n)
    {
        c[x]+=d;
        x+=lowbit(x);
    }
}
int loc[N];
int a [N];
int ans[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(c,0,sizeof c);
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            loc[a[i]]=i;
        }
        for(int i=1;i<=n;i++)
            e[i].clear();
        for(int i=1;i<=n;i++)
        {
            if(a[i]>1)
            {
                if(loc[a[i]-1]>loc[a[i]])//若a[i]-1在 a[i]右边
                    e[loc[a[i]]].push_back(loc[a[i]-1]);//在a[i]的位置上  放a[i]-1的位置
                else e[loc[a[i]-1]].push_back(loc[a[i]]);//在a[i]-1 的位置放 a[i]的位置
            }
        }
        for(int i=1;i<=m;i++)
            q[i].clear();
        for(int i=1;i<=m;i++)
        {
            int l,r;
             node tmp;
             scanf("%d %d",&l,&r);
             tmp.num=i,tmp.r=r;//对于每组query 记录 次序 右边界
             q[l].push_back(tmp);//相同左边界存在一起
        }
        for(int i=n;i>=1;i--)
        {
            for(int j=0;j<e[i].size();j++)
            {
                int v;
                v=e[i][j];//从右向左，对每个点的右边存在相邻的点的位置+1;
                add(v,1);
            }
            for(int j=0;j<q[i].size();j++)//对于每个点为左边界的query 计算 
            {
                ans[q[i][j].num]=q[i][j].r-i-sum(q[i][j].r)+1;
                //                区间内点个数 - 连续段个数
            }
        }
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    }
    return 0;
}

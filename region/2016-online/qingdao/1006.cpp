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
#include<list>
#include<time.h>
#define ll long long
#define LL long long
#define inf 1e18
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

//注意自回路
//0 ^ x =x
//数据没给存在多个环的情况，所以去掉并查集也能ac
int pre[100005];
int a[100005];
int inde[100005];
int connect=0;
int loop=0;
void initial(int n)
{
    for(int i=1;i<=n;i++)
        pre[i]=i;
    memset(a,0,sizeof a);
    memset(inde,0,sizeof inde);
    connect=0;
    loop=0;
}
int findfather(int x)
{
    int r=pre[x];
    while(x!=r)
    {
        x=pre[x];
        r=pre[x];
    }
    return r;
}
void join(int x,int y)
{
    if(x==y) loop=1;
    inde[x]++;inde[y]++;
    x=findfather(x);y=findfather(y);
    pre[x]=y;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        initial(n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<m;i++)
        {
            int f,s;
            scanf("%d %d",&f,&s);
            //并查集 查连通性 若2个以上连通分量（不考虑单独点）则impossible 若1个（不考虑单独点）
            //则对连通集内每个点做一个异或运算 找出是否有入度为1的点 有则输出结果
            //若无 则对所有点与之前结果异或一遍求最大值
            //复习并查集，并不是简单的pre[x]=y;
            join(s,f);
        }
        int indegree=0;
        for(int i=1;i<=n;i++)
        {
            if(inde[i]&1) indegree++;
        }
        if(indegree>2||indegree==1)
        {
            cout<<"Impossible"<<endl;
            continue;
        }
        int k=1;
        for(int i=1;i<=n;i++)
        {
            if(pre[i]!=i)
            {
                k=i;break;
            }
        }
        int ppr=pre[k];
        int preloop=pre[k];
        for(int i=1;i<=n;i++)
        {
            if(pre[i]==ppr)
               {
                continue;
               }
            if(pre[i]!=ppr&&pre[i]==i)
            {
                continue;
            }
            if(pre[i]!=ppr&&pre[i]!=i)
            {
                connect=1;
                break;
            }
        }
        if(connect==1)
        {
            cout<<"Impossible"<<endl;
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(pre[i]==preloop)
                {
                if(((inde[i]+1)/2)%2==1)
                   ans^=a[i];
                }

        }
        if(indegree==0)
        {
            int maxans=0;
            for(int i=1;i<=n;i++)
            {
            if(pre[i]==preloop)
                maxans=max(maxans,ans^a[i]);
            }
            ans=maxans;
        }
        cout<<ans<<endl;
    }
    return 0;
}

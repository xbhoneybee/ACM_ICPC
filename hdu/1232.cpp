#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <math.h>
#include <string.h>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#define inf 1000000000
#define ll long long
#define mod 1000000007//  这里不要写成100000000+7 define是替换！！！
#define iosfalse ios::sync_with_stdio(false);
using namespace std;
const int MAXN=1025;
//分析 每个城镇是否与其他连通 连通则为一个连通分支，
//求出一个有temp个连通分支 只需temp-1条边可使整体连通
//经典（第一道）并查集问题
int fa[1024];
void initial(int n)//初始化每个镇都独立
{
    for(int i=1;i<=n;i++)
        fa[i]=i;
}
int findd(int x)//查询
{
    while(fa[x]!=x)
        x=fa[x];
    return x;
}
void combine(int a,int b)//连接
{
    int ta=findd(a);
    int tb=findd(b);
    if(ta!=tb)
        fa[ta]=tb;
}
int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m)&&n)
    {
        initial(n);
        for(int i=1;i<=m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            combine(a,b);
        }
        int temp=0;
        for(int i=1;i<=n;i++)
        {
            if(fa[i]==i)//寻找连通的最开始的镇
                temp++;
        }
        printf("%d\n",temp-1);
    }
    return 0;
}
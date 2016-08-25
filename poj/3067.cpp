#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string.h>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#define inf 1000000000000000000
#define ll long long
#define mod 1000000007
#define iosfalse ios::sync_with_stdio(false);
using namespace std;
const int MAXN=1024;

//求cross 数量其实是求逆序对数量
//对Am,An和Bm,Bn两条高速公路A,B，有相交点必须（Am-Bm）*(An-Bn)<0
int c[MAXN];
int t,n,m,k;
struct P
{
int l,r;
} p[MAXN*MAXN];//最多有这么多条路
int cmp( P a,P b)
{
    if(a.l!=b.l) return a.l<b.l;
    else return a.r<b.r;
}
int lowbit(int x)//计算lowbit
{
     return x&(-x);
}
void update(int i,int val)//将第i个元素增加val注意i不可为零
 {
     while(i<=m)//M为数组上界
     {
         c[i]+=val;
         i+=lowbit(i);
     }
 }
ll sum(int i)//求前i项和 最多1e6 *1e6 爆int
 {
     ll s=0;
     while(i>0)
     {
         s+=c[i];
         i-=lowbit(i);
     }
     return s;
 }
int main()
{

    scanf("%d",&t);
    for(int it=1;it<=t;it++)
    {
        ll ans=0;
        scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d %d",&p[i].l,&p[i].r);
    }
    sort(p+1,p+k+1,cmp);
    memset(c,0,sizeof c);
    for(int i=1;i<=k;i++)
    {
        update(p[i].r,1);
        ans+=i-sum(p[i].r);
        //i为当前已插入的元素的个数，getsum返回了小于等于当前r值的元素个数，相减即为满足条件的元素个数
        //若小于等于当前元素个数等于i 则无逆序对 否则则有i- sum（i）的逆序对
    }
        printf("Test case %d: %I64d\n",it,ans);
    }
    return 0;
}
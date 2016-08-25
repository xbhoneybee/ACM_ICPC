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
using namespace std;
#define iosfalse ios::sync_with_stdio(false);

//灵活使用树状数组
//n^2复杂度肯定TLE 求每一个数的F*S 可以将每棵树按高度排序 这样S一定 对于F 如果累加 O (n) 想到O(log n)用树状数组
//预处理
//c对应的原数组存每个idx下标的idx之和，d对应原数组存每个idx下标的元素个数。
//c用来处理一个数前面或者后面比它大或者小的数之和，d用来处理这个数前比它大或者小的个数的和
ll c[100005],d[100005];
int lowbit(int x)
{
     return x&(-x);
}
void addc(int i,ll val)
{
     while(i<=100005)
     {
         c[i]+=val;
         i+=lowbit(i);
     }
 }
ll sumc(int i)
 {
     ll s=0;
     while(i>0)
     {
         s+=c[i];
         i-=lowbit(i);
     }
     return s;
 }
void addd(int i,ll val)
 {
     while(i<=100005)
     {
         d[i]+=val;
         i+=lowbit(i);
     }
 }
ll sumd(int i)
 {
     ll s=0;
     while(i>0)
     {
         s+=d[i];
         i-=lowbit(i);
     }
     return s;
 }
 struct T
 {
    int x,h,idh,idx;
 }tree[100005];
int cmpx( T a, T b)
{
    return a.x<b.x;
}
int cmph(T a,T b)
{
    return a.h<b.h;
}
int cmpidh( T a, T b)
{
    return a.idh<b.idh;
}
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=1;i<=n;i++)
        {
           scanf("%d %d",&tree[i].x,&tree[i].h);
        }
        sort(tree+1,tree+1+n,cmpx);
        for(int i=1;i<=n;i++)
        {
            if(i>1)
            {
                if(tree[i].x!=tree[i-1].x)
                    tree[i].idx=i;
                else tree[i].idx=tree[i-1].idx;
            }
            else tree[i].idx=1;
        }
        int maxx=tree[n].idx;
        sort(tree+1,tree+1+n,cmph);
        for(int i=1;i<=n;i++)
        {
            if(i>1)
            {
                if(tree[i].h!=tree[i-1].h)
                    tree[i].idh=i;
                else tree[i].idh=tree[i-1].idh;
            }
            else tree[i].idh=1;
        }
        sort(tree+1,tree+1+n,cmpidh);
        for(int i=1;i<=n;i++)
        {
            addc(tree[i].idx,tree[i].idx);
            addd(tree[i].idx,1);
        }
        ll ans=0,tem1,tem2;
        for(int i=1;i<n;i++)
        {
           //wa 点 不能用abs直接算 要预处理(用树状数组)idx比他大和比他小的树的个数 ll tem=tree[i].idh*abs((n-i)*tree[i].idx-(sumd(n)-sumd(i)));
            tem1=sumd(tree[i].idx-1)*tree[i].idx-sumc(tree[i].idx-1);
            tem2=(sumd(maxx)-sumd(tree[i].idx))*tree[i].idx-(sumc(maxx)-sumc(tree[i].idx));
            ans+=(tem1-tem2)*tree[i].idh;
            addc(tree[i].idx,-tree[i].idx);//要把这个数删除，以免下面会重复求这个数
            addd(tree[i].idx,-1);
        }
        printf("%I64d\n",ans);
        memset(c,0,sizeof c);
        memset(d,0,sizeof d);
    }
    return 0;
}

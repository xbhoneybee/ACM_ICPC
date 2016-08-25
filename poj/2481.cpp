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

//这里求区间真包含自己的，和逆序对相比有些不同 逆序对要求a[i]>a[j]  i<j
struct C{
int s,e,id;
}cow[100005];
int c[100005];
int cmp(C a ,C b )
{
    if(a.s!=b.s) return a.s<b.s;
    else return a.e>b.e;
}
int lowbit(int x)//计算lowbit
{
     return x&(-x);
}
 void add(int i,int val)//将第i个元素增加val注意i不可为零
 {
     while(i<=100002)//n为所开数组上界
     {
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
int ans[100005];
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&cow[i].s,&cow[i].e);
            cow[i].id=i;
            cow[i].s++;
            cow[i].e++;
        }
        sort(cow+1,cow+1+n,cmp);
        for(int i=1;i<=n;i++)
        {

            if(i>1&&cow[i].e==cow[i-1].e&&cow[i].s==cow[i-1].s)
                ans[cow[i].id]=ans[cow[i-1].id];
            else{
            ans[cow[i].id]=i-1-sum(cow[i].e-1);
            }
            add(cow[i].e,1);
        }
        for(int i=1;i<n;i++)
            cout<<ans[i]<<' ';
        cout<<ans[n]<<endl;
        memset(c,0,sizeof c);
    }
    return 0;
}
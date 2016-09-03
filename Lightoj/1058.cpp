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
#define mod 1000000007
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e18
#define lowbit(x) x&-x
using namespace std;
//light oj 1058
struct line
{
   int midx,midy;
};
line l[600000];
int repeat[600000];
int px[1005];
int py[1005];
line makeline(int x1,int y1,int x2,int y2)
{
    line tmp;
    tmp.midy=(y1+y2);
    tmp.midx=(x1+x2);
    return tmp;
}
int cmp(line a,line b)
{
    if(a.midx!=b.midx)
        return a.midx<b.midx;
    else return a.midy<b.midy;
}
long long Combination(long long n,long long m)
{
    if(m>n) return 0;
    long long ans=1;
    if(m>n-m) m=n-m;
    for(long long i=n;i>n-m;i--)
        ans=(ans*i);
    for(long long i=2;i<=m;i++)
    {
        ans/=i;
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    int it=0;
    while(t--)
    {
        it++;
        int n;
        int tot=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
           scanf("%d %d",&px[i],&py[i]);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
        {
            l[tot++]=makeline(px[i],py[i],px[j],py[j]);
        }
        ll ans=0;
        sort(l,l+tot,cmp);
        int ttp=1,cot=0;
        for(int i=0;i<tot-1;i++)
            {
                if(l[i].midx==l[i+1].midx&&l[i].midy==l[i+1].midy)
                    ttp++;
                else
                {
                    repeat[cot++]=ttp;
                    ttp=1;
                }
            }
            if(ttp!=1)
                repeat[cot++]=ttp;
        for(int i=0;i<cot;i++)
            if(repeat[i]>1)
        {
            ans+=Combination(repeat[i],2);
        }
        printf("Case %d: %lld\n",it,ans);
    }
    return 0;
}





//这题有些莫名其妙 我之前用两边平行且相等 TLE 都是O n^2 这是为什么？
//light oj 1058
struct line
{
    double k,len;
    int x1,y1,x2,y2;
};
line l[600000];
int px[1005];
int py[1005];
line makeline(int x1,int y1,int x2,int y2)
{
    line tmp;
    double len=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    tmp.len=len;
    if((x1-x2)!=0)
    tmp.k=(y1-y2)/(x1-x2);
    else tmp.k=inf;
    tmp.x1=x1;tmp.x2=x2;tmp.y1=y1;tmp.y2=y2;
    return tmp;
}
int main()
{
    int t;
    scanf("%d",&t);
    int it=0;
    while(t--)
    {
        it++;
        int n;
        int tot=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
           scanf("%d %d",&px[i],&py[i]);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
        {
            l[tot++]=makeline(px[i],py[i],px[j],py[j]);
        }
        ll ans=0;
        for(int i=0;i<tot;i++)
            for(int j=i+1;j<tot;j++)
            {
                if(fabs(l[i].k-l[j].k)<1e-8&&fabs(l[i].len-l[j].len)<1e-8)//坑 点 平行且相等 还要求不在一条直线上
                    {
                        if((l[j].x1-l[i].x2)==0&&l[j].y1!=l[i].y2)
                        ans++;
                        else if( (l[j].x1-l[i].x2)!=0&&fabs((l[j].y1-l[i].y2)/(l[j].x1-l[i].x2)-l[i].k)>1e-6)
                        {
                        ans++;
                        //cout<<"--------------------------"<<endl;
                        //cout<< i<<" "<<j<<endl;
                        //cout<<l[i].k<<"     "<<l[i].len<<endl;
                        //cout<<'('<<l[i].x1<<','<<l[i].y1<<')'<<"   "<<'('<<l[i].x2<<','<<l[i].y2<<')'<<endl;
                        //cout<<l[j].k<<"     "<<l[j].len<<endl;
                        //cout<<'('<<l[j].x1<<','<<l[j].y1<<')'<<"   "<<'('<<l[j].x2<<','<<l[j].y2<<')'<<endl;
                        //cout<<"--------------------------"<<endl;
                        }
                    }
            }
        ans/=2;
        printf("Case %d: %lld\n",it,ans);
    }
    return 0;
}

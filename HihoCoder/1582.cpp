//#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<vector>
#include<map>
#include<sstream>
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::snync_with_stdio(false);

using namespace std;


const int N=205;
int n,tot;//n为二维平面上点的个数，tot为凸包上点的个数
struct node
{
    int x,y,id;
}a[N],p[N];//p[]用来储存凸包
char ans[205];
int dis(node a,node b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
//叉积：返回结果为正说明p2在向量p0p1的左边（三点构成逆时针方向）；为负则相反；为0则三点共线(叉积的性质很重要)
double multi(node p0,node p1,node p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int multiint(node p0,node p1,node p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}///
int cmp(node p1,node p2)//极角排序；
{
    int x=multiint(p1,p2,a[0]);
    if(x>0||(x==0&&dis(p1,a[0])<dis(p2,a[0]))) return 1;
    return 0;
}
void Graham()
{
    int k=0;
    for(int i=0;i<n;i++)
        if(a[i].y<a[k].y||(a[i].y==a[k].y&&a[i].x<a[k].x))
        {
            k=i;
        }
    swap(a[0],a[k]);
    sort(a+1,a+n,cmp);
    tot=2,p[0]=a[0],p[1]=a[1];
    for(int i=2;i<n;i++)
    {
        while(tot>1&&multi(p[tot-1],p[tot-2],a[i])>=0) tot--;
        p[tot++]=a[i];
    }
}

bool online(node st,node ed)
{
    for(int i=0;i<n;i++)
    {
        if(a[i].id!=st.id&&a[i].id!=ed.id)
        {
            if(multiint(st,a[i],ed)==0)
                return true;
        }
    }
    return false;
}
void findans()
{

    for(int i=0;i<tot-1;i++)
    {
       if(online(p[i],p[i+1]))
       {
            ans[p[i].id]=ans[p[i+1].id]='A';
            return ;
       }
    }
    if(online(p[tot-1],p[0]))
    {
    ans[p[tot-1].id]=ans[p[0].id]='A';
    return ;
    }
    for(int i=0;i<tot;i++)
    {
        ans[p[i].id]='A';//坑点，三角形围起来其他点
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int id=0;id<T;id++)
    {
        memset(ans,0,sizeof ans);
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&a[i].x,&a[i].y);
            ans[i]='B';
            a[i].id=i;
        }
        if(n==1||n==2)
        {
            printf("NO\n");
            continue;
        }
        memset(p,0,sizeof p);
        Graham();
        if(tot==2)
        {
            //所有 共线
            printf("YES\n");
            ans[p[0].id]=ans[p[1].id]='A';
            printf("%s\n",ans);
            continue;
        }else{
            //
            if(n==3)
            {
                printf("NO\n");
                continue;
            }else {
                printf("YES\n");
                if(tot>=4)
                {
                ans[p[0].id]=ans[p[2].id]='A';//应为凸包上的0和2;
                }else{
                findans();
                }
                printf("%s\n",ans);
                continue;
            }
        }
    }

    return 0;
}

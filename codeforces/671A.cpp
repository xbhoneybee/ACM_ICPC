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
#include <sstream>
#define inf 10000000000
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
using namespace std;


// wa点 只有a或b取  思考不全面！！

struct P{
int i;
double x,y;
double disa;
double disb;
double dist;
}p[100005];
int cmpa(P a,P b)
{
    return a.disa+b.dist<b.disa+a.dist;   //wa 点两点比较！！！
}
int cmpb(P a,P b)
{
    return a.disb+b.dist<b.disb+a.dist;
}
int main()
{
    double ax,ay,bx,by,tx,ty;
    scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&tx,&ty);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&p[i].x,&p[i].y);
        p[i].i=i;
        p[i].disa=sqrt((ax-p[i].x)*(ax-p[i].x)+(ay-p[i].y)*(ay-p[i].y));
        p[i].disb=sqrt((bx-p[i].x)*(bx-p[i].x)+(by-p[i].y)*(by-p[i].y));
        p[i].dist=sqrt((tx-p[i].x)*(tx-p[i].x)+(ty-p[i].y)*(ty-p[i].y));
    }
    sort(p,p+n,cmpa);
    int temp=p[0].i;
    int temp2=p[1].i;
    double ansa =0;
    for(int i=0;i<n;i++)
    {
        if(i==0) ansa=ansa+p[i].disa+p[i].dist;
        else ansa=ansa+p[i].dist*2;
    }
    sort(p,p+n,cmpb);
    double ans=0;
    double ans1=0;
    double ansb=0;
    for(int i=0;i<n;i++)
    {
        if(i==0) ansb=ansb+p[i].disb+p[i].dist;
        else ansb=ansb+p[i].dist*2;
    }
    if(p[0].i==temp)
    {
        {
            ans=ans+p[0].disb+p[0].dist;
            for(int i=1;i<n;i++)
            {
                if(p[i].i!=temp2)
                    ans=ans+p[i].dist*2;
                else ans=ans+p[i].disa+p[i].dist;
            }
        }

        {
            ans1=ans1+p[0].disa+p[0].dist;
            ans1=ans1+p[1].disb+p[1].dist;
            for(int i=2;i<n;i++)
               {
                    ans1=ans1+p[i].dist*2;
               }
        }

        ans=min(ans,ans1);//不用知道怎么分情况
    }
    else{
    ans=ans+p[0].disb+p[0].dist;
    for(int i=1;i<n;i++)
    {
        if(p[i].i!=temp)
            {ans=ans+p[i].dist*2;}
        else {ans=ans+p[i].disa+p[i].dist;}
    }
    }
    ans=min(ans,ansa);
    ans=min(ans,ansb);
    printf("%.14f\n",ans);
    return 0;
}

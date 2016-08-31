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
#include<deque> //双端队列
#define mod 1000000007
#define ll long long
#define LL long long
#define inf 10000000000000
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e18
using namespace std;
//poj 2318
int y1x[5003],y2x[5003];
int n,m,x1,y1,x2,y2;
struct Point{
int x,y;
};
Point p[5003];
int ans[5005];
int upordown(int x,int y,int lux,int luy,int rdx,int rdy )
{
    ll tem =(rdy-luy)*(lux-x)-(rdx-lux)*(luy-y);
    if(tem>0) return 1;//在线右上
    else return -1;//在线左下
}
void add(int x,int y)
{
    if(upordown(x,y,y1x[1],y1,y2x[1],y2)<0)
    {
        //cout<<"add   00000"<<endl;
        ans[0]++; return ;
    }

   if(upordown(x,y,y1x[n],y1,y2x[n],y2)>0)
   {
    //   cout<<"add   nnn "<<endl;
       ans[n]++; return ;
   }

   int l=1,r=n;
    while(l<r)  //修改
    {
        int mid=(l+r)>>1;
       //  cout<<"mid   "<<mid<<endl;
        // if(mid==1) break;
        if(upordown(x,y,y1x[mid],y1,y2x[mid],y2)<0)
        {
            r=mid;
        }
        else l=mid+1;
    }
    ans[l-1]++;
}
int main()
{
    while(cin>>n>>m>>x1>>y1>>x2>>y2&&n)
    {
        memset(ans,0,sizeof ans);
        for(int i=1;i<=n;i++)
            cin>>y1x[i]>>y2x[i];
        for(int i=1;i<=m;i++)
            cin>>p[i].x>>p[i].y;
        for(int i=1;i<=m;i++)
        {
            add(p[i].x,p[i].y);
           // cout<<i<<endl;
        }
        for(int i=0;i<=n;i++)
            cout<<i<<": "<<ans[i]<<endl;
        cout<<endl;
    }

    return 0;
}

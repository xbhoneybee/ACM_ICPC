#include <bits/stdc++.h>
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
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x

using namespace std;

/// 二分逼近 输出小数不要用cout

int pos[60005];
int v[60005];
int n;
const double eps=1e-8;
double solve(int a,int b)
{
    double L=a,R=b;
    while(true)
    {
        double mid=(L+R)/2,ml=(L+mid)/2,mr=(mid+R)/2;
        double tmid=0,tl=0,tr=0,tml=0,tmr=0;
        for(int i=0;i<n;i++)
        {
            tmid=max(tmid,fabs(mid-pos[i])/v[i]);
            tl=max(tl,fabs(L-pos[i])/v[i]);
            tr=max(tr,fabs(R-pos[i])/v[i]);
            tml=max(tml,fabs(ml-pos[i])/v[i]);
            tmr=max(tmr,fabs(mr-pos[i])/v[i]);
        }
        if(fabs(tml-tmid)<eps&&fabs(tmid-tmr)<eps)
            return tmid;
        if(tmid<tml&&tml<tl)
        {
            L=ml;
        }
        if(tmid<tmr&&tmr<tr)
        {
            R=mr;
        }
    }
}
int main()
{
    cin>>n;
    int sm=1e9,bg=0;
    for(int i=0;i<n;i++)
        {
            cin>>pos[i];
            sm=min(sm,pos[i]);
            bg=max(bg,pos[i]);
        }
    for(int i=0;i<n;i++)
        cin>>v[i];
    double ans=0;
    ans=solve(sm,bg);
    printf("%.8f\n",ans);
    return 0;
}

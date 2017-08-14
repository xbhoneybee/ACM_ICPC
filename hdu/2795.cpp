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
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x

using namespace std;


const int maxn=800005;
int h,w,n;
int maxv[maxn];
void init()
{
    if(h>n)
        h=n;
}
void Build(int L,int R)
{
    for(int i=1;i<=h*4;i++)
        maxv[i]=w;
}
inline  int Query(int L,int R,int goal,int o)
{
    if(maxv[o]<goal)
        return -1;
    if(L==R)
    {
        if(maxv[o]>=goal)
        {
            maxv[o]-=goal;
            return L;
        }
        else return -1;
    }
    int lo=o<<1;
    int ro=o<<1|1;
    int M=(L+R)>>1;
    int ret=Query(L,M,goal,lo);
    if(ret==-1)
        ret=Query(M+1,R,goal,ro);
    maxv[o]=max(maxv[o<<1],maxv[o<<1|1]);
    return ret;
}
int main()
{
    iosfalse
    while(scanf("%d %d %d",&h,&w,&n)!=EOF)
    {
        init();
        Build(1,h);
        for(int i=1;i<=n;i++)
        {
            int ww;
            scanf("%d",&ww);
            if(ww>maxv[1])
                printf("-1\n");
            else {
                printf("%d\n",Query(1,h,ww,1));
            }
        }
    }
    return 0;
}

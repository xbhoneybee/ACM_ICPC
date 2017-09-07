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

using namespace std;

int n,k;
struct P{
int id;
int newid;
int cost;
}fly[300005];
bool cmp(P a,P b)
{
    if(a.cost!=b.cost)
    return a.cost>b.cost;
    else return a.id<b.id;
}
int ansid[300005];
bool vis[300005];
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&fly[i].cost);
        fly[i].id=fly[i].newid=i;
    }
    sort(fly+1,fly+1+n,cmp);
    memset(vis,false,sizeof vis);
    long long cnt=1,pos=1;
    long long sum=0;
    while(cnt<=n)
    {
        if(vis[pos]==true)
        {
            pos++;
            continue;
        }
        if(fly[cnt].id<=pos+k)
        {
            vis[pos]=true;
            ansid[fly[cnt].id]=pos+k;
            sum+=(pos+k-fly[cnt].id)*fly[cnt].cost;
            cnt++;
            pos++;
        }else {
            vis[fly[cnt].id-k]=true;
            ansid[fly[cnt].id]=fly[cnt].id;
            cnt++;
        }
    }
    printf("%I64d\n",sum);
    for(int i=1;i<=n;i++)
    {
        printf("%d ",ansid[i]);
    }
    printf("\n");
    return 0;
}

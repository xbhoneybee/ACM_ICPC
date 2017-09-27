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
struct P{
int st,ed;
long long ned;
}p[1005];
long long all[105];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            printf("*\n");
            break;
        }
        memset(all,0,sizeof all);
        for(int i=0;i<n;i++)
        {
            long long k;
            scanf("%d %d %lld",&p[i].st,&p[i].ed,&k);
            all[p[i].st]+=k;
            all[p[i].ed]-=k;//注意有坑
        }
        long long maxv=0;
        for(int i=1;i<=100;i++)
        {
            all[i]+=all[i-1];
            maxv=max(maxv,all[i]);
        }
        printf("%lld\n",maxv);
    }
    return 0;
}

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


int n,m;
int p[105];
bool vis[105];
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&p[i]);
        }
        int q;
        scanf("%d",&q);
        memset(vis,false,sizeof vis);
        for(int i=0;i<q;i++)
        {
            int t;
            scanf("%d",&t);
            vis[t]=true;
        }
        int ans=10000000;
        int day1,day2;
        for(int st=0;st<n;st++)
        {
            int min1=p[st],min2=1000000,d1=st,d2=st+1;
            if(vis[st]==true)
                continue;
            int okday=0;
            for(int i=st;i<n;i++)
            {
                if(vis[i]==false)
                    okday++;
                if(okday>=m)
                    break;
            }
            if(okday<m)
                continue;
            for(int j=1,add=0;j<m&&st+j+add<n;j++)
            {
                while(st+j+add<n&&vis[st+j+add]==true)
                    add++;
                if(st+j+add>=n)
                    break;
                if(p[st+j+add]<min2)
                {
                    min2=p[st+j+add];
                    d2=st+j+add;
                }
            }
            if(min1+min2<ans)
            {
                ans=min1+min2;
                day1=d1;
                day2=d2;
            }
        }
        if(day1>day2)
            swap(day1,day2);
        printf("%d %d\n",day1,day2);
    }
    return 0;
}

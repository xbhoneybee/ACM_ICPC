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

long long mp[105][105];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int T,n,m;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        memset(mp,0,sizeof mp);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                {
                    if((i+j)%2==0)
                    mp[i][j]=1;
                }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
            for(int t=0;t<4;t++)
                {
                int tx=i+dx[t];
                int ty=j+dy[t];
                if(tx<0||ty<0||tx>=n||ty>=m)
                    continue;
                if(mp[tx][ty]==0)
                    mp[i][j]*=2;
                }
            }
        long long ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans+=mp[i][j];
        printf("%I64d\n",ans);
    }
    return 0;
}

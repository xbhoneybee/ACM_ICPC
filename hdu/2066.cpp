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
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;


//最开始我愚蠢的准备从每个s点出发找一遍找d 找的最小值 则为结果
//因为Floyd 会对每个点都进行计算 只需标记是否是near 以及 goal 即可寻找最小值
int n=1000;
int mp[1005][1005];
int t,d,s;
int ans;
int near[1005],goal[1005];
int  floyd()
{
    int res=inf;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            if(mp[i][k]!=inf)
            for(int j=1;j<=n;j++)
            {
                if(mp[i][j]>mp[i][k]+mp[k][j])
                    mp[i][j]=mp[i][k]+mp[k][j];
                if(near[i]&&goal[j])
                    res=min(res,mp[i][j]);
            }
    return res;
}
int main()
{
    while(~scanf("%d %d %d",&t,&s,&d))
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                mp[i][j]=inf;
        int a,b,c;
        int big=-inf;
        for(int i=1;i<=t;i++)
            {
                scanf("%d %d %d",&a,&b,&c);
                mp[a][b]=mp[b][a]=min(mp[a][b],c);
                if(big<max(a,b)) big=max(a,b);
            }
        n=big;
        memset(near,0,sizeof near);
        memset(goal,0,sizeof goal);
        for(int i=1;i<=n;i++)
            mp[i][i]=0;
        for(int i=1;i<=s;i++)
        {
            int yp;
            scanf("%d",&yp);
            near[yp]=1;
        }
        for(int i=1;i<=d;i++)
        {
            int yp;
            scanf("%d",&yp);
            goal[yp]=1;
        }
    ans=floyd();
    printf("%d\n",ans);
    }
    return 0;
}

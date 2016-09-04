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
#define mod 1000000007
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e18
#define lowbit(x) x&-x
using namespace std;

//详解 ： http://www.cnblogs.com/scau20110726/archive/2013/02/27/2935256.html
//状态压缩dp +位运算
int dp[3][105][105]; //滚动数组
int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m)){
    char mapp[15];
    int state[80];
    int tot=0;  //一共可以状态数
    for(int mask=0;mask<(1<<m);mask++)
    {
        int flag=1;//初始认为状态可以
        for(int i=0;i<m;i++) //对于mask的每一位
            if(mask&(1<<i))
                if(mask&(1<<(i+1))||(mask&(1<<(i+2))))//有冲突
                    flag=0;      //不可以
        if(flag) state[tot++]=mask;
    }
    memset(dp,0,sizeof dp);
    int cur=0;
    int ans=0;
    for(int l=0;l<n;l++)
    {
        scanf("%s",mapp);  //读入一行地图
        int d=0; //d 表示当前行状态
        for(int i=0;i<m;i++)
        {
            int x=0;
            if(mapp[i]=='H')
             x=1;
            d<<=1;
            d|=x;
        }
        memset(dp[cur^1],0,sizeof(dp[cur^1]));
        for(int i=0;i<tot;i++)  //i表示当前行
            if(!(state[i]&d))// state[i]&d==0 表示合法
            for(int j=0;j<tot;j++)
            if(!(state[i]&state[j]))
            for(int k=0;k<tot;k++)
                if(!(state[i]&state[k]))
                if(!(state[j]&state[k]))
        {
            dp[cur^1][k][i]=max(dp[cur^1][k][i],dp[cur][j][k]+   __builtin_popcount((state[i])));
            ans=max(ans,dp[cur^1][k][i]);
        }
        cur^=1;
    }
    cout<<ans<<endl;
    }

    return 0;
}

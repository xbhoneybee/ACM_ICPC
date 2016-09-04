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

//轮廓线dp 详见大白书p384或：http://blog.csdn.net/u014800748/article/details/49387129
int n,m,cur;
const int maxn=11;
long long d[2][1<<maxn];//d[i][j]表示当前阶段为一点,状态为j时的种数，使用滚动数组
void update (int old,int news) //原来状态为old 转移状态为news   
{
    if(news&(1<<m))         d[cur][news^(1<<m)]+=d[1-cur][old];
    //news的从右向左(含第0位)第m位为1  将news的第m位变成0
{
}
int main()
{
    while(scanf("%d %d",&n,&m)==2)
    {
        if(n<m) swap(n,m);  //去m为较小的固定，降低时间复杂度
        memset(d,0,sizeof d);
        cur=0;
        d[0][(1<<m)-1]=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
        {
            cur^=1;
            memset(d[cur],0,sizeof d[cur]);
            for(int k=0;k<(1<<m);k++){
                update(k,k<<1);//不放
            if(i&&!(k&(1<<(m-1))) update(k,(k<<1)^(1<<m)^1);//新状态 m位变0 第0位变1
            if(j&&!(k&1)) update(k,(k<<1)^3);//第0 和1 位变1
            }
        }
        printf("%lld\n",d[cur][(1<<m)-1]);//  I64d  wa
    }
    return 0;
}

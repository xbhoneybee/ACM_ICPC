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

int n;
int a[30];
int b[30];
int dp[22][22][22][22];
int dfs(int la,int ra,int lb,int rb,int sum )//这个sum用的很巧妙
{               
    int tmp=0;//表示当前的人选择取到最大值
    if(ra<la&&rb<lb) return 0;
    if(dp[la][ra][lb][rb]) return dp[la][ra][lb][rb];
    if(la<=ra)
    {       //只需要考虑四种不同的取法并从中取得最优的方案，sum-(Alice下一个状态中Bob拿的值最小)中取最大
        tmp=max(tmp,sum-dfs(la+1,ra,lb,rb,sum-a[la]));
        tmp=max(tmp,sum-dfs(la,ra-1,lb,rb,sum-a[ra]));
    }
    if(lb<=rb)
    {
        tmp=max(tmp,sum-dfs(la,ra,lb+1,rb,sum-b[lb]));
        tmp=max(tmp,sum-dfs(la,ra,lb,rb-1,sum-b[rb]));
    }
    dp[la][ra][lb][rb]=tmp;
    return tmp;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int sum=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            {
                cin>>a[i];
                sum+=a[i];
            }
        for(int i=1;i<=n;i++)
            {
                cin>>b[i];
                sum+=b[i];
            }
        int ans=0;
        ans=dfs(1,n,1,n,sum);
        cout<<ans<<endl;
        memset(dp,0,sizeof dp);
    }
    return 0;
}

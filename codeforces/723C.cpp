#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<cstdlib>
#include <sstream>
#include <deque>
#include<list>
#include<time.h>
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
//codeforces 10.3
//C
int a[3000];
int vis[3000];
int main()
{
    int n,m;
    int change=0;
    cin>>n>>m;
    int maxtime=(int)(n/m);
    int beyongcost=n-m*maxtime;
    for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]<=m)
                vis[a[i]]++;
        }
    int mm,nn;
    mm=1;nn=1;
    int perfect=0;
    while(1){
    for(;mm<=m;mm++)
       {
        if(vis[mm]<maxtime)
            break;
        if(mm==m)
            perfect=1;
       }
    if(perfect)break;
    for(;nn<=n&&vis[mm]<maxtime;nn++)
    {
        if(a[nn]>m)
        {
            a[nn]=mm;
            vis[mm]++;
            change++;
        }else if(a[nn]<=m&&vis[a[nn]]>(n-n/m*m+maxtime))
        {
            vis[a[nn]]--;
            a[nn]=mm;
            vis[mm]++;
            change++;
        }
        else if(vis[a[nn]]>maxtime&&vis[a[nn]]<=(n-n/m*m+maxtime))
        {
            beyongcost--;
        }
        if(beyongcost<0)
        {
            if(a[nn]<=m&&vis[a[nn]]>maxtime)
            {
                vis[a[nn]]--;
                a[nn]=mm;
                vis[mm]++;
                change++;
            }
        }
    }
    mm++;
    if(mm==m+1)
      break;
    }
    cout<<maxtime<<" "<<change<<endl;
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
        cout<<endl;
    return 0;
}

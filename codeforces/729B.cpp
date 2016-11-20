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
#define inf 1000000009
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

//B
int mp[1005][1005];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&mp[i][j]);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int pre=-1;
        for(int j=0;j<m;j++)
    {
        if(mp[i][j]==1)
        {
            if(pre!=-1)
            ans+=(j-pre-1)*2;
            else ans+=j;
            pre=j;
        }
    }
    if(pre!=-1)
    ans+=m-1-pre;
    }
    for(int j=0;j<m;j++)
    {
        int pre=-1;
        for(int i=0;i<n;i++)
        {
            if(mp[i][j]==1)
            {
            if(pre!=-1)
            ans+=(i-pre-1)*2;
            else ans+=i;
            pre=i;
            }
        }
    if(pre!=-1)
    ans+=n-1-pre;
    }
    cout<<ans<<endl;
    return 0;
}

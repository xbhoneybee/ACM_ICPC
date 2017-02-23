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
#define ll long long
#define LL long long
#define inf 1000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;
//分析知 :只能 no 到最左 或最右
int a[2000006];
int vis[2000006];
int main()
{
    int n,ax;
    cin>>n>>ax;
    ax+=1000000;
    for(int i=0;i<n;i++)
        {
            cin>>a[i];
            a[i]+=1000000;
        }
    sort(a,a+n);
    int ans=1e9;
    if(ax<a[0])
    {
        ans=a[n-2]-ax;
    }else if(ax>a[n-1])
    {
        ans=ax-a[1];
    }else {
    ans=min(ans,a[n-2]-a[0]+abs(a[n-2]-ax));
    ans=min(ans,a[n-2]-a[0]+ax-a[0]);
    ans=min(ans,a[n-1]-a[1]+a[n-1]-ax);
    ans=min(ans,a[n-1]-a[1]+abs(ax-a[1]));
    }
    if(n==1)
        ans=0;
    cout<<ans<<endl;
    return 0;
}
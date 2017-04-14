#include <bits/stdc++.h>
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
#define lowbit(x) x&-x

using namespace std;

int a[105];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans=100000000;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=0&&a[i]<=k)
            {
                ans=min(ans,abs(m-i)*10);
            }
    }
    cout<<ans<<endl;
    return 0;
}

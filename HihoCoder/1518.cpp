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
#define lowbit(x) x&-x

using namespace std;

int a[100005];
bool lon[100005];
int main()
{
    iosfalse
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(lon[i]==true)
            continue;
        lon[i]==true;
        int cnt=1,tmp=a[i];
        lon[tmp]=true;
        while(a[tmp]!=a[i])
            {
                cnt++;
                tmp=a[tmp];
                lon[tmp]=true;
            }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}

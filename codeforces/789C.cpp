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
ll a[100005];
ll b[100005];
ll d[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    ll ans=-1e18;
    for(int i=0;i+1<n;i++)
        b[i]=abs(a[i]-a[i+1]);
    for(int t=0;t<2;t++)
    {
        if(t==0)
        {
            for(int i=1;i<n;i+=2)
                b[i]=-b[i];
            d[0]=b[0];
            ans=max(ans,d[0]);
            for(int i=1;i<n-1;i++)
                {
                    if(d[i-1]>0)
                        d[i]=d[i-1]+b[i];
                    else d[i]=b[i];
                    ans=max(ans,d[i]);
                }
        }else{
            for(int i=0;i+1<n;i++)
                b[i]=-b[i];
            d[1]=b[1];
            ans=max(ans,d[1]);
            for(int i=2;i<n-1;i++)
                {
                    if(d[i-1]>0)
                        d[i]=d[i-1]+b[i];
                    else d[i]=b[i];
                    ans=max(ans,d[i]);
                }
        }
    }
    cout<<ans<<endl;
    return 0;
}

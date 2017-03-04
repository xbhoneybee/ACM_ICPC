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
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x

using namespace std;
ll f(ll x)
{
    ll ans=0;
    while(x>0)
    {
        int yu=x%10;
        x/=10;
        ans+=yu*yu;
    }
    return ans;
}
int main()
{
    ll n;
    while(cin>>n)
    {
        int ok=0;
        for(int i=0;i<1e6;i++)
        {
            n=f(n);
            if(n==1)
                {
                    ok=1;break;
                }
        }
        if(ok==1)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

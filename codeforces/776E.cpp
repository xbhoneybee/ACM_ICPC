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
#define inf 1000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

const int  mmd=1000000007;
ll oula(ll n)
{
    ll replaced=n;
    vector<ll> v;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
            v.push_back(i);
        while(n%i==0)
            n/=i;
    }
    if(n!=1) v.push_back(n);
    ll ans=replaced;
    ll number=v.size();
    for(ll i=0;i<number;i++)
        ans=ans/v[i]*(v[i]-1);
    return ans;
}
///打表可知 g(x)=x;f(n)是欧拉函数;且当n为奇数f(2*n)=f(n),暴力
int main()
{
    long long n,k;
    cin>>n>>k;
    long long ans,tmp=n;
    for(int i=0;i<(k+1)/2;i++)
    {
        tmp=oula(tmp);
        if(tmp==1)
            break;
    }
    ans=tmp;
    cout<<(ans%mmd)<<endl;
    return 0;
}

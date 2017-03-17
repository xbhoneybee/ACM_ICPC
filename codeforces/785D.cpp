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
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

//cfD 
const long long mmd=1e9+7;
long long f[200005];
ll PowerMod(ll a, ll b, ll c)
{
    ll ans = 1;
    a = a % c;
    while(b>0)
    {
    if(b % 2 == 1)
    ans = (ans * a) % c;
    b = b/2;
    a = (a * a) % c;
    }
    return ans;
}
long long Combination(long long n,long long m,long long mod)
{
    if(m==0) return 1;
    if(m>n) return 0;
    long long ans;
    return ans=f[n]*PowerMod(f[m],mod-2,mod)%mmd*PowerMod(f[n-m],mod-2,mod)%mod;
}
void fact(long long n)
{
    f[0]=1;
    for(int i=1;i<=n;i++)
        f[i]=f[i-1]*i%mmd;
}
int lk[200005];
int rk[200005];
int main()
{
    string str;
    cin>>str;
    int lef=0,rig=0;
    long long ans=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(')
            lef++;
        lk[i]=lef;
    }
    for(int i=str.size()-1;i>=0;i--)
    {
        if(str[i]==')')
            rig++;
        rk[i]=rig;
    }
    fact(str.size()+10);
    for(int i=0;i<str.size();i++)
    {
        if(str[i]!='('||rk[i]==0)
            continue;
        ans=(ans+Combination(lk[i]+rk[i]-1,lk[i],mmd))%mmd;
    }
    cout<<ans<<endl;
    return 0;
}


///理解求解过程，左边l个物品右边r个物品，要从l+r个物品中取l-1 件 有多少种取法？

#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>1
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


const int mmd= 1000007;// md这不是个质数29 * 34483 用加法求C
int C[550][550];
ll force(ll n,ll m,ll k)
{
    if(n*m>k)
    return C[n*m][min(k,n*m-k)];
    else if(n*m==k)
    return 1;
    else return 0;
}
ll solve(ll n,ll m,ll k)//容斥原理
{
    ll ret=0;
    ret=(ret+force(n,m,k))%mmd;
    ret=(ret-force(n-1,m,k)*2)%mmd;
    ret=(ret+mmd)%mmd;
    ret=(ret-force(n,m-1,k)*2)%mmd;
    ret=(ret+mmd)%mmd;
    ret=(ret+force(n-1,m-1,k)*4)%mmd;
    ret=(ret+force(n-2,m,k))%mmd;
    ret=(ret+force(n,m-2,k))%mmd;
    ret=(ret-force(n-2,m-1,k)*2)%mmd;
    ret=(ret+mmd)%mmd;
    ret=(ret-force(n-1,m-2,k)*2)%mmd;
    ret=(ret+mmd)%mmd;
    ret=(ret+force(n-2,m-2,k))%mmd;
    ret=(ret+mmd)%mmd;
    return ret;
}
int main()
{
    for(int i=1;i<520;i++)
    {
        C[i][1]=i;C[i][0]=1;C[i][i]=1;
    }
    for(int i=3;i<520;i++)
        for(int j=2;j<i;j++)
    {
        C[i][j]=(C[i-1][j-1]+C[i-1][j])%mmd;
    }
    ll  n,m,k;
    int t,it=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        int ans;
        if(n*m==k)
            ans=1;
        else if(n*m<k)
            ans=0;
        else {
            if(k==1)
                ans=0;
            else if(k==2)
                ans=2;
            else ans=solve(n,m,k);
        }
        cout<<"Case "<<it++<<": ";
        cout<<ans<<endl;
    }
    return 0;
}

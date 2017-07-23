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


const long long mmd=1000000007;
long long D[10005];
long long A[10005]={1,1,2};
long long pow_mod(long long a,long long n)
{
    long long ans=1;
    while(n)
    {
        if(n&1) ans=ans*a%mmd;
        a=a*a%mmd;
        n>>=1;
    }
    return ans;
}
long long Con(long long a,long long b)
{
    if(!b) return 1;
    long long ans=A[a];
    ans=ans*pow_mod(A[a-b],mmd-2)%mmd;
    ans=ans*pow_mod(A[b],mmd-2)%mmd;
    return ans;
}
int main()
{
    iosfalse
    D[2]=1;
    for(long long i=3;i<=10000;i++)
    {
       D[i]=(i-1)*(D[i-2]+D[i-1])%mmd;
       A[i]=(A[i-1]*i)%mmd;
    }
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        long long ans=A[n];
        for(int i=1;i<=k;i++)
        {
            ans=(mmd+ans-Con(n,k-i)*D[n-(k-i)]%mmd)%mmd;
        }
        cout<<ans<<endl;
    }
    return 0;
}

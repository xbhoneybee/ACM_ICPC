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

//uva 10294

int gcd(int x,int y)
{
    if(y==0)
        return x;
    return gcd(y,x%y);
}
long long f[100];
int main()
{
    int n,t;
    while(scanf("%d %d",&n,&t)!=EOF)
    {
        memset(f,0,sizeof f);
        f[0]=1;
        for(int i=1;i<=n;i++)
            f[i]=f[i-1]*t;
        long long ans1=0,ans2=0;
        if(n&1)
        {
            for(int i=1;i<=n;i++)
                ans2+=f[gcd(i,n)];
            ans1=ans2;
            ans2/=n;
            ans1+=f[(n+1)/2]*n;
            ans1/=(2*n);
        }else{
            for(int i=1;i<=n;i++)
                ans2+=f[gcd(i,n)];
            ans1=ans2;
            ans2/=n;
            ans1+=n/2*f[n/2];
            ans1+=n/2*f[(n-2)/2+2];
            ans1/=(2*n);
        }
        cout<<ans2<<" "<<ans1<<endl;
    }
    return 0;
}

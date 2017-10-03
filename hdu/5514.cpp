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

using namespace std;

long long gcd(long long x ,long long y)
{
if(!y)
return x;
else return gcd(y , x%y);
}
long long n,m;
long long S(long long t)
{
    return m/t*(m/t-1)/2*t;
}
long long a[10004];
int cnt[10004];
int num[10004];
//设cnt[i]为从格子fac[i]开始应该走的次数(只有0,1)两个值，num[i]为从格子fac[i]开始的到当前为止实际走的次数
int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d %I64d",&n,&m);
        memset(cnt,0,sizeof cnt);
        memset(num,0,sizeof num);
        vector<long long>fac;
        for(long long i=1;i*i<=m;i++)
        {
            if(m%i==0)
            {
                fac.push_back(i);
                if(i*i!=m)
                fac.push_back(m/i);
            }
        }
        sort(fac.begin(),fac.end());
        for(int i=0;i<n;i++)
            {
                scanf("%I64d",&a[i]);
                a[i]=gcd(a[i],m);
                for(int j=0;j<fac.size();j++)
                {
                    if(fac[j]%a[i]==0)
                    {
                        cnt[j]=1;
                    }
                }
            }
        long long ans=0;
        for(int i=0;i<fac.size();i++)
        {
            if(num[i]! =cnt[i])
            {
                ans+=(cnt[i]-num[i])*S(fac[i]);
                for(int j=i+1;j<=fac.size();j++)
                    if(fac[j]%fac[i]==0)
                        num[j]+=(cnt[i]-num[i]);
            }
        }
        printf("Case #%d: %I64d\n",cas++,ans);
    }
    return 0;
}

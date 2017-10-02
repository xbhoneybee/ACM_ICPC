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
long long lowbit(long long x)//计算lowbit
{
    return x&(-x);
}
long long cal(long long c,long long n)
{
    long long sum=0;
    for(int i=0;(1LL<<i)<=n;i++)
    {
        sum+=(c/(1LL<<i)-c/(1LL<<(i+1)))*(1LL<<i);
    }
    return sum;
}
long long query(long  long x,long long n)
{
    long long ans=0;
    while(x<=n)
    {
        ans++;
        x+=lowbit(x);
    }
    return ans;
}
int main()
{
    iosfalse
    long long n,q;
    
    while(cin>>n>>q)
    {
        long long L,R,x;
        for(int i=0;i<q;i++)
        {
            int cmd;
            cin>>cmd;
            if(cmd==1)
            {
                cin>>L>>R;
                cout<<cal(R,n)-cal(L-1,n)<<endl;
            }else {
                cin>>x;
                long long cnt=1;
                cnt=query(x,n);
                cout<<cnt<<endl;
            }
        }
    }
    return 0;
}

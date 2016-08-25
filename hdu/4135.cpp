#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string.h>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#define inf 1000000000000000000
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
using namespace std;


LL Solve(LL n,LL r)
{
    vector<LL> p;
    for(LL i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            p.push_back(i);
            while(n%i==0) n/=i;
        }
    }
    if(n>1)
        p.push_back(n);
    LL ans=0;
    for(LL msk=1; msk<(1<<p.size()); msk++)
    {
        LL multi=1,bits=0;
        for(LL i=0; i<p.size(); i++)
        {
            if(msk&(1<<i))  //判断第几个因子目前被用到
            {
                ++bits;//判断有几位组成
                multi*=p[i];
            }
        }
        LL cur=r/multi;
        if(bits&1) ans+=cur;//奇数加
        else       ans-=cur;//偶数减
    }
    return r-ans;
}
int main()
{
    int t;
    cin>>t;
    for(int it=1;it<=t;it++)
    {
        ll a,b,n;
        cin>>a>>b>>n;
        ll ans=Solve(n,b)-Solve(n,a-1);
        //cout<<Solve(n,b)<<' '<<Solve(n,a-1)<<endl;
        cout<<"Case #"<<it<<": "<<ans<<endl;
    }
    return 0;
}
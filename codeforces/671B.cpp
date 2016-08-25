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
#include <sstream>
#define inf 10000000000
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

//D  2分查找
//首先得明确一点，初始时硬币数比平均数少的人最终会增加k个硬币，比平均数多的会减少k个硬币，
//所以根据这个先用二分求出最终最少的硬币数，然后最用二分求出最终最多的硬币数，然后相减就行了
ll c[500005];
int main()
{
    iosfalse
    ll n,k;
    cin>>n>>k;
    ll sum=0;
    ll ave;
    for(int i=0;i<n;i++)
        {cin>>c[i];sum+=c[i];}
    sort(c,c+n);
    if(c[n-1]==c[0])
    {
        cout<<0<<endl;
        return 0;
    }
    if(c[n-1]-c[0]==1)
    {
        cout<<1<<endl;
        return 0;
    }
    ave=sum/n;
    ll big,small;

    ll l=c[0]-1,r=ave;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        ll cost1=0;
        for(int i=0;c[i]<mid;i++)
        cost1+=(mid-c[i]);
        if(cost1<=k)
            small=mid,l=mid+1;
        else r=mid-1;
    }
    l=(sum+n-1)/n,r=inf;//wa点    一定从比平均数多的开始找  因为若从0开始 可能偷的硬币比给的多
    //比如这组数据10 20

    //6 4 7 10 4 5 5 3 7 10  big=5 small=7  偷多了，这时要还回去，不如直接从sum+n-1  /n开始找
    while(l<r)
    {
        ll mid=(l+r)>>1;
        ll cost2=0;
        for(int i=n-1;c[i]>mid&&i>=0;i--)
        cost2+=(c[i]-mid);
        if(cost2<=k)
            big=mid,r=mid;
        else l=mid+1;
    }
    cout<<big-small<<endl;
    return 0;
}


#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<stdlib.h>
#include <sstream>
#include <deque> //双端队列
#define mod 1000000007
#define ll long long
#define LL long long
#define inf 10000000000000
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e18
#define lowbit(x) x&-x
using namespace std;

long long A(long long n,long long m)
{
    if(m>n) return 0;
    long long ans=1;
    for(long long i=n;i>n-m;i--)
        ans=(ans*i);
    return ans;
}
long long Combination(long long n,long long m)
{
    if(m>n) return 0;
    long long ans=1;
    if(m>n-m) m=n-m;
    for(long long i=n;i>n-m;i--)
        ans=(ans*i);
    for(long long i=2;i<=m;i++)
    {
        ans/=i;
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    int it=0;
    while(t--)
    {
        it++;
        int n,k;
        cin>>n>>k;
        if(k>n)
        {
          cout<<"Case "<<it<<": 0"<<endl;  continue;
        }
        ll ans=Combination(n,k);
        ans*=A(n,k);
        cout<<"Case "<<it<<": "<<ans<<endl;
    }
    return 0;
}

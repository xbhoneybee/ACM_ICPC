#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<cstdlib>
#include <sstream>
#include <deque>
#include<list>
#include<time.h>
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;

int exgcd(int a , int b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    int d=exgcd(b,a%b,x,y);
    int tem=x;
    x=y;
    y=tem-a/b*y;
    return d;
}
vector<long long>line_mod_equation(long long a,long long b,long long n)
{
    long long x,y;
    long long d=exgcd(a,n,x,y);///use exgcd
    vector<long long>ans;
    ans.clear();
    if(b%d==0){
        x%=n;x+=n;x%=n;
        ans.push_back(x*(b/d)%(n/d));
        for(long long i=1;i<d;i++)
            ans.push_back((ans[0]+i*n/d)%n);
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long b;
        long long mod = 9973;
        long long ans;
        vector<ll> vec;
        cin>>n>>b;
        vec=line_mod_equation(b,1,mod);
        ans=(vec[0]*n%mod);
        cout<<ans<<endl;
    }
    return 0;
}

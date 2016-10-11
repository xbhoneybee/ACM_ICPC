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
///读题是个大问题！！！
int exgcd(int a , int b,int &x,int &y)
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
///CRT(中国剩余定理)
//O(NlgM) M和每个mi同阶 x=ai(mod mi)  即x%mi=ai
int CRT(int a[],int m[],int n)
{
    int M=1;
    for(int i=0;i<n;i++) M*=m[i];
    int ret=0;
    for(int i=0;i<n;i++)
    {
        int x,y;
        int tm=M/m[i];
        exgcd(tm,m[i],x,y);
        ret=(ret+tm*x*a[i])%M;
    }
    return (ret+M)%M;
}
int main()
{
    int t;
    int it=0;
    int p,d,i,e;
    while(cin>>p>>e>>i>>d)
    {
        it++;
        if(p==-1&&d==-1) break;
        int a[4],m[4];
        a[0]=p%23;a[1]=e%28;a[2]=i%33;
        m[0]=23;m[1]=28;m[2]=33;
        int crt=CRT(a,m,3);
        int ans= crt-d;
        ans=(ans+21252)%21252;
        if(ans==0) ans=21252;
        cout<<"Case "<<it<<": the next triple peak occurs in "<<ans<<" days."<<endl;
    }
    return 0;
}

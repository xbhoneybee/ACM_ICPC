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
using namespace std;

int main()
{
    ll x0,y0,z0;
    ll x1,y1,z1;
    ll x2,y2,z2;
    cin>>x0>>y0>>z0;
    cin>>x1>>y1>>z1;
    cin>>x2>>y2>>z2;
    int x,y,z;
    int min=inf;
    for(int i=x1;i<=x2;i++)
    {
        if(abs(i-x0)<min)
            min=abs(i-x0);
    }
    x=min;
    min=inf;
    for(int i=y1;i<=y2;i++)
    {
        if(abs(i-y0)<min)
            min=abs(i-y0);
    }
    y=min;
    min=inf;
    for(int i=z1;i<=z2;i++)
    {
        if(abs(i-z0)<min)
            min=abs(i-z0);
    }
    z=min;
    cout<<(z)*(z)+(y)*(y)+(x)*(x)<<endl;
    return 0;
}
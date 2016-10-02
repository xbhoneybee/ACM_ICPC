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
    LL x,y,z;
    LL ans=0;
    while(cin>>x>>y>>z)
    {ans=x+2*y+3*z;
    if(z==0)
    {
        if(x>0) cout<<ans<<endl;
        else cout<<y<<endl;
    }
    else {
        if(x>=2)
        cout<<ans<<endl;
        else if((x==1&&y>=1))
        cout<<ans<<endl;
        else if(x==1&&y==0)
        cout<<2*z+1<<endl;
        else if(x==0&&y==1)
        cout<<2*z+1<<endl;
        else if(x==0&&y==0)
        cout<<z<<endl;
        else if(x==0&&y>=2)
        {
            int k=y-4;//???不明所以为什么＋y-4;但是打表猜出来的
            cout<<3*(z+1)-1+y+k<<endl;
        }
    }
    }
    return 0;
}
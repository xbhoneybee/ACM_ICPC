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
#include <deque>
#include<list>
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

//cf 9.17

int main()
{
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        if(i==1) cout<<2<<endl;
        else
        cout<<((i+1)*(i+1)-1)*i+1<<endl;
    }
    return 0;
}
//数论题，我居然退出来了，不过耗时太长，分不高。

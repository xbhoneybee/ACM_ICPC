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

//codeforces 10.3
//A
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int minx=inf;
    for(int i=0;i<=100;i++)
    {
    minx=min(minx,abs(a-i)+abs(b-i)+abs(c-i));
    }
   cout<<minx<<endl;
    return 0;
}

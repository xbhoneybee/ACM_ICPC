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
#include<ctime>
#define ll long long
#define LL long long
#define inf 10000.00
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int ok=240-k;
    int ans=sqrt(2*ok/5)-1;
    while((1+ans)*ans/2*5<ok)
        ans++;
    if((1+ans)*ans/2*5>ok)
        ans--;
    if(ans>n)
        ans=n;
    if(ans<0)// point
        ans=0;
    cout<<ans<<endl;
    return 0;
}

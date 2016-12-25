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
#define inf 10000.00
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int iseven=0;
    if(k%2==0)
        iseven=1;
    int a,b;
    a=k/(2*m)+1;
    if(k%(2*m)==0)
        a--;
    if(k%(2*m)==0)
        b=m;
    else b=k%(2*m)/2;
    if(iseven==0)
        b++;
    cout<<a<<" "<<b<<" ";
    if(iseven==1)
        cout<<"R"<<endl;
    else cout<<"L"<<endl;
    return 0;
}

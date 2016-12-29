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
    int n;
    while(cin>>n){
    int x=sqrt(2.0*n)-1;
    while((1+x)*x/2<n)
        x++;
    if((1+x)*x/2>n)
        x--;
    cout<<x<<endl;
    for(int i=1;i<x;i++)
    {
        cout<<i<<" ";
    }
    cout<<n-(x)*(x-1)/2<<endl;
    }
    return 0;
}

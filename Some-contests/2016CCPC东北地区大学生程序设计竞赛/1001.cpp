#include <iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#include<cstring>
#include<set>
#include<queue>
#include<cctype>
#include<map>
#include<stack>
#include<cstdlib>
#include<sstream>
#include<deque>
#include<list>
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int it=1;it<=t;it++)
    {
        long long n;
        cin>>n;
        cout<<"Case #"<<it<<": "<<(1+n)*n/2-1<<endl;
    }
    return 0;
}
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
        ll a,b;
        cin>>a>>b;
        cout<<"Case #"<<it<<":"<<endl;
        if(a!=b)
        {
            cout<<2<<endl;
            cout<<a<<" "<<b<<endl;
            cout<<b<<" "<<a<<endl;
        }
        else{
        cout<<1<<endl;
        cout<<a<<" "<<b<<endl;
        }
    }
    return 0;
}
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
#include <deque> //双端队列
#define mod 1000000007
#define ll long long
#define LL long long
#define inf 10000000000000
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e18
#define lowbit(x) x&-x
using namespace std;

int main()
{
    int t;
    cin>>t;
    ll s;
    int it=0;
    while(t--)
    {
        it++;
        cin>>s;
        ll i=floor(sqrt(s)+0.5);
        if(i*i<s) i++;
        if(i&1)
        {
            ll a=i*i-s;
            if(a<i)
            cout<<"Case "<<it<<": "<<a+1<<" "<<i<<endl;
            else
            cout<<"Case "<<it<<": "<<i<<" "<<s-(i-1)*(i-1)<<endl;
        }
        else{
            ll a=s-(i-1)*(i-1);
            if(a<=i)
            cout<<"Case "<<it<<": "<<a<<" "<<i<<endl;
            else
            cout<<"Case "<<it<<": "<<i<<" "<<i*i-s+1<<endl;
        }
    }
    return 0;
}

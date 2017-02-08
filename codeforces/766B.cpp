#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<vector>
#include<map>
#include<sstream>
#define ll long long
#define LL long long
#define inf 100000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;


int main()
{
    int n;
    cin>>n;
    ll a[100005]={0};
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int ok=0;
    for(int i=0;i<n-2;i++)
    {
        if(a[i]+a[i+1]>a[i+2])
        {
            ok=1;break;
        }
    }
    if(ok==1)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

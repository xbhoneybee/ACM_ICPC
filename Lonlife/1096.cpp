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
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x

using namespace std;

const long long inf =1e18;
int main()
{
    ll a,b,m;
    while(cin>>a>>b>>m)
    {
    vector <long long> div;
    for(int i=1;i<=sqrt(m)+0.5;i++)
        {
            if(m%i==0)
            {
            div.push_back(i);
            if(m/i!=i)
            div.push_back(m/i);
            }
        }
    sort(div.begin(),div.end());
    int ans;
    ll cost=inf;
    for(int i=0;i<div.size();i++)
    {
        ll tcost=m/div[i]*(a+b*div[i]*div[i]);
        if(tcost<cost)
        {
            ans=div[i];
            cost=tcost;
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}

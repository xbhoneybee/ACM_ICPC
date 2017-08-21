//#include <bits/stdc++.h>
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
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);

using namespace std;

const long long mmd=1e9+7;
long long PowerMod(long long a, long long  b, long long c)
{
    long long ans = 1;
    a = a % c;
    while(b>0)
    {
    if(b % 2 == 1)
    ans = (ans * a) % c;
    b = b/2;
    a = (a * a) % c;
    }
    return ans;
}
int main()
{
    int T,id=1;
    scanf("%d",&T );
    while(T--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        vector<int>rotated;
        for(int i=1;i<=m;i++)
            rotated.push_back(__gcd(i,m));
        if(m>2)
        {
            if(m&1)
            {
            for(int i=1;i<=m;i++)
            rotated.push_back(m/2+1);
            }
            else {
            for(int i=1;i<=m/2;i++)
            {
            rotated.push_back(m/2);
            rotated.push_back(m/2+1);
            }
            
            }
        }
        long long ans=0;
        for(int i=0;i<rotated.size();i++)
            ans=(ans+PowerMod(n,rotated[i],mmd))%mmd;
        ans=(ans*PowerMod(rotated.size(),mmd-2,mmd))%mmd;
        cout<<"Case #"<<id++<<": "<<ans<<endl;

    }
    return 0;
}

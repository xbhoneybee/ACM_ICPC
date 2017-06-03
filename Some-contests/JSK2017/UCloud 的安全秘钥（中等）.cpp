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
#define lowbit(x) x&-x

using namespace std;

//jsk603
//C

int n,m;
int s[50004];
int t[50004];
long long Hash[50004];
int main()
{
    iosfalse
    cin>>n;
    for(int i=0;i<=n;i++)
        Hash[i]=rand()*rand()*rand();
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    cin>>m;
    for(int it=0;it<m;it++)
    {
        int k;
        cin>>k;
        long long hsgoal=0,hsstore=0;
        for(int i=0;i<k;i++)
        {
            cin>>t[i];
            if(k<=n)
            hsgoal+=Hash[t[i]];
        }
        if(k>n)
        {
            cout<<0<<endl;
            continue;
        }
        int L=0,R=k,ans=0;
        for(int i=L;i<R;i++)
        {
            hsstore+=Hash[s[i]];
        }
        while(L<n&&R<=n)
        {
            if(hsgoal==hsstore)
                ans++;
            hsstore-=Hash[s[L]];
            hsstore+=Hash[s[R]];
            L++;R++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

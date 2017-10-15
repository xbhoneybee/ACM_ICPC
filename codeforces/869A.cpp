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
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);

using namespace std;

//A

int x[2005];
int y[2005];
int main()
{
    iosfalse
    int n;
    cin>>n;
    set<int>st;
    for(int i=0;i<n;i++)
        {cin>>x[i];st.insert(x[i]);}
    for(int i=0;i<n;i++)
        {cin>>y[i];st.insert(y[i]);}
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int tmp=x[i]^y[j];
            if(st.count(tmp))
                ans++;
        }
    }
    //cout<<ans<<endl;
    if(ans&1)
        cout<<"Koyomi"<<endl;
    else cout<<"Karen"<<endl;
    return 0;
}

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

int main()
{
    int n;
    cin>>n;
    int ans=0;
    set<int>st;
    for(int i=0;i<2*n;i++)//2*n sb
    {
        int a;
        cin>>a;
        if(st.empty())
            st.insert(a);
        else if(st.count(a))
            st.erase(a);
        else st.insert(a);
        ans=max(ans,(int)st.size());
    }
    cout<<ans<<endl;
    return 0;
}


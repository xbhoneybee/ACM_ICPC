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
    //freopen("output.txt","w",stdout);
    string a,b;
    cin>>a>>b;
    if(a.size()==b.size())
    {
        if(a==b)
            cout<<-1<<endl;
        else cout<<a.size()<<endl;
    }
    else {
        int longest=max(a.size(),b.size());
        cout<<longest<<endl;
    }
    return 0;
}

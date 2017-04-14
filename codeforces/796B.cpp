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
#define lowbit(x) x&-x

using namespace std;

int main()
{
    iosfalse
    int n,m,k;
    cin>>n>>m>>k;
    set<int>drop;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        drop.insert(x);
    }
    int goal=1;
    bool ct=false;
    if(drop.count(1))
        ct=true;
    for(int i=0;i<k;i++)
    {
        int u,v;
        cin>>u>>v;
        if(ct)
            continue;
        if(u==goal||v==goal)
        {
            if(drop.count(u))
               {
                   goal=u;
                   ct=true;
               }
            else if(drop.count(v)) {
                goal=v;
                ct=true;
            }else{
            goal= goal==u?v:u;
            }
        }
    }
    cout<<goal<<endl;
    return 0;
}

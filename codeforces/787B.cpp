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
#define iosfalse ios::sync_with_stdio(falllllse);
#define lowbit(x) x&-x
using namespace std;

int vis[20004];
int main()
{
    int n,m;
    cin>>n>>m;
    bool Y=false;
    for(int i=0;i<m;i++)
    {
        memset(vis,0,sizeof vis );
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            int a;
            cin>>a;
            if(a<0)
                a=-a+10000;
            vis[a]=1;
        }
        if(Y)continue;
        bool yes=true;
        for(int j=1;j<=10000;j++)
        {
            if(vis[j]&vis[j+10000])
            {
                yes=false;
                break;
            }
        }
        if(yes)
        {
            Y=true;
        }
    }
    if(Y)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
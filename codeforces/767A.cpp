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
#define inf 10000000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;
///A

int a[100006];
int vis[100006];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int goal=n;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==goal)
        {
            vis[goal]=1;
            while(vis[goal]==1)
            {
                cout<<goal<<" ";
                goal--;
            }
            cout<<endl;
        }
        else
        {
            vis[a[i]]=1;
            cout<<endl;
        }
    }
    return 0;
}

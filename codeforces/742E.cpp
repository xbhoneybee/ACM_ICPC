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
#define ll long long
#define LL long long
#define inf 10000000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;


int girl[100005],boy[100005];
int meal[200005],vis[200005];
vector<int>mp[200005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
       {
        scanf("%d%d",&boy[i],&girl[i]);
        mp[boy[i]].push_back(girl[i]);
        mp[girl[i]].push_back(boy[i]);
       }
    for(int i=1;i<=n;i++)
        {
           mp[2*i-1].push_back(2*i);
           mp[2*i].push_back(2*i-1);
        }
    for(int i=1;i<=2*n;i++)
    {
        if(vis[i]==1)
            continue;
        int color=1;
        vis[i]=1;
        meal[i]=color;
        int u=i,v=mp[i][0];
        while(i!=v)
        {
            vis[v]=1;
            color= color==1?2:1;
            meal[v]=color;
            if(mp[v][0]==u)
            {
                u=v;
                v=mp[v][1];
            }else{
                u=v;
                v=mp[v][0];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d %d\n",meal[boy[i]],meal[girl[i]]);
    }
    return 0;
}

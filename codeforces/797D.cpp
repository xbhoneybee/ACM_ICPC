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


////cf ed19 D 找规律
//左边儿子的范围总是小于当前祖先的val，右边儿子的范围总是大于祖先的val

const int maxn=100005;
int l[maxn];
int r[maxn];
int v[maxn];
int n;
int cnt=0;
bool vis[maxn];
map<int,int>mp;
void dfs(int rt,int bb,int ss)
{
    if(v[rt]<=bb&&v[rt]>=ss)
        {
            cnt-=mp[v[rt]];//注意只要有一个v[rt]能被找到，其他不同位置都可以找到
            mp[v[rt]]=0;
        }
    if(l[rt]!=-1)
    {
        dfs(l[rt],min(bb,v[rt]),ss);
    }
    if(r[rt]!=-1)
    {
        dfs(r[rt],bb,max(ss,v[rt]));
    }
}
int main()
{
    iosfalse
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>l[i]>>r[i];
        mp[v[i]]++;
        if(l[i]>0)vis[l[i]]=true;
        if(r[i]>0)vis[r[i]]=true;
    }
    int root;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false)
        {
            root=i;break;
        }
    }
    cnt=n;
    dfs(root,1e9+5,-10);
    cout<<cnt<<endl;
    return 0;
}

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

struct Tree{
int lson,rson;
int l_val,r_val,l_len,r_len;
Tree(){lson=-1;rson=-1;l_val=0;r_val=0;l_len=0;r_len=0;}
}tree[100005];
int idt;
void build(int dist)
{
    tree[idt]=Tree();
    int wl, dl, wr, dr;
    scanf("%d %d %d %d",&wl,&dl,&wr,&dr);
    int cur=idt;
    if(wl!=0)
    {
        tree[cur].l_val=wl;tree[cur].l_len=-dl+dist;
    }
    else {
        tree[cur].l_len=-dl+dist;
        tree[cur].lson=++idt;
        build(tree[cur].l_len);
    }
    if(wr!=0)
    {
        tree[cur].r_val=wr;tree[cur].r_len=dr+dist;
    }else{
        tree[cur].r_len=dr+dist;
        tree[cur].rson=++idt;
        build(tree[cur].r_len);
    }
}
int dfs(int root)
{
    int tmp=0;
    if(tree[root].lson==-1)
    {
        tmp+=(tree[root].l_len)*tree[root].l_val;
    }else{
        tmp+=dfs(tree[root].lson);
    }
    if(tree[root].rson==-1)
    {
        tmp+=(tree[root].r_len)*tree[root].r_val;
    }else {
        tmp+=dfs(tree[root].rson);
    }
    return tmp;
}
void solve()
{
    int ans;
    ans+=dfs(0);
    if(ans==0)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
void init()
{
    idt=0;
}
int main()
{
    //freopen("output.txt","w",stdout);
    int tase;
    scanf("%d",&tase);
    while(tase--)
    {
        build(0);
        solve();
        if(tase)
            cout<<endl;
        init();
    }
    return 0;
}

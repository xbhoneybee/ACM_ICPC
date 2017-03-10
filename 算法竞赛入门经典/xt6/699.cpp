#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>1
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
int val,pos;
Tree(){lson=-1;rson=-1;val=0;pos=0;}
}tree[100005];
int number[200005];
int idt;
bool build()
{
    int val;
    cin>>val;
    if(val==-1&&idt==0)
        return true;
    tree[idt]=Tree();
    int cur=idt;
    if(val!=-1)
    {
        tree[cur].val=val;
        tree[cur].lson=++idt;
        build();
        tree[cur].rson=++idt;
        build();
    }
    return false;
}
void dfs(int root,int pos)
{
    if(tree[root].val==0)
        return ;
    if(tree[root].lson!=-1)
    {
        dfs(tree[root].lson,pos-1);
    }
    if(tree[root].rson!=-1)
    {
        dfs(tree[root].rson,pos+1);
    }
    number[pos]+=tree[root].val;
}
void solve(int it)
{
    dfs(0,100000);
    bool first=true;
    cout<<"Case "<<it<<":"<<endl;
    for(int i=0;i<200000;i++)
        if(number[i])
            {
                if(first)
                    {cout<<number[i];first=false;}
                else
                cout<<" "<<number[i];
            }
    cout<<endl;
}
void init()
{
    idt=0;
    memset(number,0,sizeof number);
}
int main()
{
    //freopen("output.txt","w",stdout);
    int it=1;
    while(true)
    {
        bool out;
        out=build();
        if(out)
            break;
        solve(it);
        cout<<endl;
        it++;
        init();
    }
    return 0;
}

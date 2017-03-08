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
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;


struct Tree{
int lson,rson;
int val,sum;
Tree(){lson=-1;rson=-1;val=-1;sum=0;}
}tree[10004];
int id;
int n=0;
int in[10004];
int post[10004];
int ans,ms=1e9;
void build_tree(int posts,int ins,int len)
{
    int cur=id;
    tree[cur]=Tree();
    tree[cur].val=post[posts+len-1];
    int i;
    for( i=ins;i<ins+len;i++)
        if(in[i]==post[posts+len-1])
        break;
    if(i>ins)
    {
        tree[cur].lson=++id;
        build_tree(posts,ins,i-ins);
    }
    if(i+1<ins+len)
    {
        tree[cur].rson=++id;
        build_tree(i-ins+posts,i+1,len+ins-i-1);
    }
}
void dfs(int root,int f)
{
    tree[root].sum=tree[root].val+f;
    if(tree[root].lson!=-1)
        dfs(tree[root].lson,tree[root].sum);
    if(tree[root].rson!=-1)
        dfs(tree[root].rson,tree[root].sum);
    if(tree[root].lson==-1&&tree[root].rson==-1)
    {
        if(tree[root].sum<ms)
            {
                ans=tree[root].val;
                ms=tree[root].sum;
            }
        else if(tree[root].sum==ms)
            ans=min(tree[root].val,ans);
    }
}
void init()
{
    n=0;
    id=0;
    ans=0;
    ms=1e9;
    tree[0]=Tree();
}
int main()
{
    //freopen("output.txt","w",stdout);
    string str;
    while(getline(cin,str))
    {
        stringstream stream(str);
        int x;
        while(stream>>x)
            in[n++]=x;
        for(int i=0;i<n;i++)
            cin>>post[i];
        getline(cin,str);
        build_tree(0,0,n);
        dfs(0,0);
        printf("%d\n",ans);
        init();
    }
    return 0;
}

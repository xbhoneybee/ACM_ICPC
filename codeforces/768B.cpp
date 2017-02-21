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

//观察一下，将整个过程写出来，会发现形成一棵满二叉树，每一层要么全是0，要么全是1。
//输出的顺序是其中序遍历。
//每一层的序号形成等差数列，就计算一下就可以出来每一层覆盖到的区间的左右端点。

long long value[60];
int find_one(long long x)
{
    for(int i=0;i<60;i++)
    {
        if((x-value[i])%value[i+1]==0)
            return i;
    }
}
int main()
{
    long long n,l,r;
    cin>>n>>l>>r;
    vector<int>vec;
    if(n==0)
        vec.push_back(n);
    while(n)
    {
        vec.push_back(n%2);
        n/=2;
    }
    reverse(vec.begin(),vec.end());
    memset(value,-1,sizeof value);
    long long base=1;
    for(int i=0;i<60;i++)
    {
        value[i]=base;
        base=base<<1l;
    }
    int ans=0;
    for(long long i=l;i<=r;i++)
    ans+=vec[find_one(i)];
    cout<<ans<<endl;
    return 0;
}

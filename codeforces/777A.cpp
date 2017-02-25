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
#define inf 1000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

int a0[7]={0,1,2,2,1,0,0};
int a1[7]={0,0,0,1,2,2,1};
int a2[7]={0,2,1,0,0,1,2};
int main()
{
    long long n;
    int x;
    cin>>n>>x;
    n%=6;
    if(n==0)
        cout<<x<<endl;
    else if(x==a0[n])
    {
        cout<<0<<endl;
    }else if(x==a1[n])
    {
        cout<<1<<endl;
    }else{
        cout<<2<<endl;
    }
    return 0;
}

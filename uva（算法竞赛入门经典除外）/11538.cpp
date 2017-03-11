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



//UVA 11538 容斥原理

long long AA[1000006]={1,1,2};

int main()
{
    //freopen("output.txt","w",stdout);
    for(int i=3;i<=1000000;i++)
    {
        AA[i]=AA[i-1]*i/(i-2);
    }
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0)
            break;
        long long ans=0;
        ans+=n*AA[m]+m*AA[n];
        if(n<m)
            swap(n,m);
        long long ans1=0;
        for(int i=2;i<=m;i++)
        {
            ans1+=AA[i]*2;
        }
        ans1+=(n-m-1)*AA[m];
        ans1*=2;
        ans+=ans1;
        cout<<ans<<endl;
    }
    return 0;
}

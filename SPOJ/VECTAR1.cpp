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

int mp[1001][1001];
long long NJC[1000006]={1};
int number[1030];///xor result couldn't more than 1024
const long long mmd=1e9+7;
int main()
{
    for(int i=1;i<=1000;i++)
        for(int j=0;j<=1000;j++)
            mp[i][j]=i^j;
    for(int i=1;i<=1000000;i++)
        NJC[i]=((i*NJC[i-1])%mmd+mmd)%mmd;
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int n,m;
        long long ans=1;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                number[mp[i][j]]++;
            }
        for(int i=0;i<=1024;i++)
        {
            if(number[i]==0)
                continue;
            long long x=number[i];
            ans=(NJC[x]*ans)%mmd;
        }
        cout<<ans<<endl;
        memset(number,0,sizeof number);
    }
    return 0;
}

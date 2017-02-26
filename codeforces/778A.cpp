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
#include<set>1
#include<vector>
#include<map>
#include<sstream>
#define ll long lo`ng
#define LL long long
#define inf 1000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

int aa[200005];
int del[200005];
char str_a[200005];
char str_b[200005];
int n,m;
bool query(int x)
{
    memset(del,0,sizeof del);
    for(int i=0;i<x;i++)
        del[aa[i]]=1;
    int cnt=0;
    for(int i=0;i<n&&cnt<m;i++)
    {
        if(del[i]==1)
            continue;
        if(str_a[i]==str_b[cnt])
            cnt++;
    }
    if(cnt>=m)
        return true;
    return false;
}
int main()
{
    scanf("%s%s",str_a,str_b);
    n=strlen(str_a);
    m=strlen(str_b);
    for(int i=0;i<n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            aa[i]=tmp-1;
        }
    int l=0,r=n-m+1;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(query(mid)==true)
            l=mid+1;
        else r=mid;
    }
    cout<<l-1<<endl;
    return 0;
}

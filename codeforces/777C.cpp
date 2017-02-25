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

int n,m;
map<int,int>vec;
bool query(int L,int R)
{
    if(vec[L]>=R)
        return true;
    else return false;
}
int mp[100005];
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&mp[(i-1)*m+j]);
    for(int i=1;i<=n;i++)
        vec[i]=i;
    for(int j=0;j<m;j++ )
    {
        int pre=1,ed=1;
        for(int i=1;i<n;i++)
        {
            if(mp[(i-1)*m+j]<=mp[i*m+j])
                ed++;
            else {
                if(pre!=ed)
                {
                    if(ed>vec[pre])
                    vec[pre]=ed;
                }
                pre=i+1;ed=i+1;
            }
        }
        if(pre!=ed)
        {
            if(ed>vec[pre])
            vec[pre]=ed;
        }
    }
    for(int i=2;i<=n;i++)
    {
        vec[i]=max(vec[i-1],vec[i]);
    }
    int k;
    scanf("%d",&k);

    while(k--)
    {
    int l,r;
    scanf("%d %d",&l,&r);
    if(l==r)
        printf("Yes\n");
    else{
        bool ans=query(l,r);
        if(ans==true)
            printf("Yes\n");
        else printf("No\n");
    }
    }
    return 0;
}

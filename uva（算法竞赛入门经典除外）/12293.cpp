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


int SG[100];
int vis[100];

void find_rule()
{
    SG[1]=0;
    for(int i=2;i<=80;i++)
    {
        memset(vis,0,sizeof vis);
        for(int j=(i+1)/2;j<i;j++)
        {
            vis[SG[j]]=1;
        }
        for(int j=0;;j++)
        {
            if(vis[j]==0)
            {
                SG[i]=j;
                break;
            }
        }
        cout<<i<<" "<<SG[i]<<endl;
    }
}
int main()
{
    set<long long>st;
    long long base=1;
    for(int i=1;i<35;i++)
    {
        base*=2;
        if(base<1e9)
        st.insert(base-1);
        else break;
    }
    int n;
    //find_rule();
    while(cin>>n)
    {
        if(n==0)
            break;
        if(st.count(n))
            cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }
    return 0;
}

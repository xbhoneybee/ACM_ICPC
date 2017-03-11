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

int force(int n)
{
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=j+1;k<=n;k++)
    {
        if(i+j>k)
            ans++;
    }
    return ans;
}
long long Ans[1000006]={0,0,0,0};
int main()
{
    for(int i=4;i<=1000000;i++)
        {
            long long ned=i/2-1;
            Ans[i]=Ans[i-1];
            if(i&1)
            Ans[i]+=(1+ned)*ned;
            else Ans[i]+=(1+ned)*ned-ned;
        }
    int n;
    while(cin>>n)
    {
        if(n<3)
            break;
        cout<<Ans[n]<<endl;
    }
    return 0;
}

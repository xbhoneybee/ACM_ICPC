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

int gcd(int x , int y) //当1方为0 返回另一方
{
if(!y)
return x;
else return gcd(y , x%y);
}
int lcm(int x,int y) //最小公倍数
{
    return x/gcd(x,y)*y;
}
int main()
{
    int n;
    int next[105]={0};
    int len[105]={0};
    int vis[105]={0};
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>next[i];
    }
    int isok=1;
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof vis);
        int st=i,tlen=0;
        while(vis[st]==0)
        {
            vis[st]=1;
            tlen++;
            st=next[st];
        }
        if(st==i)
        {
            if(tlen&1)
                len[i]=tlen;
            else len[i]=tlen/2;
        }else {
        isok=0;
        break;
        }
    }
    if(isok==0)
        cout<<-1<<endl;
    else {
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            ans=lcm(ans,len[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}

//#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#define ll long long
#define LL long long
#define inf 1000000000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;



int mod(int &x)
{
    if(x>0)
    {
        int ret=x%(-2);
        x/=(-2);
        return ret;
    }
    else
    {
        int ret=x%(-2);
        if(ret==-1)
        {
            ret=1;
            x/=(-2);
            x++;
            return ret;
        }
        else
        {
            x/=(-2);
            return ret;
        }
    }
}
void tobin(int x)
{
    if(x==0)
      {
        cout<<0<<endl;
        return ;
      }
    string ans="";
    while(x!=0)
    {
        if(mod(x)==1)
            ans+='1';
        else ans+='0';
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}
int main()
{
    int n;
    cin>>n;
    tobin(n);
    return 0;
}

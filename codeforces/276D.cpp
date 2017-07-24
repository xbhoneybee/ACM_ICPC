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
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x

using namespace std;

string tobin(long long num)
{
    string str;
    while(num>0)
    {
        char ch=num%2+'0';
        str+=ch;
        num/=2;
    }
    reverse(str.begin(),str.end());
    return str;
}
int main()
{
    long long l,r;
    cin>>l>>r;
    if(l==r)
    {
        cout<<0<<endl;
        return 0;
    }
    string strl=tobin(l);
    string strr=tobin(r);
    if(strl.size()==strr.size())
    {
        for(int i=0;i<strl.size();i++)
        {
            if(strl[i]!=strr[i])
            {
                cout<<(1ll<<(strl.size()-i))-1<<endl;
                break;
            }
        }
    }else {
        cout<<(1ll<<strr.size())-1<<endl;
    }
    return 0;
}

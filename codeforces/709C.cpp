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

int main()
{
    string s;
    cin>>s;
    int len=s.size();
    int st=len,ed=len;
    for(int i=0;i<len;i++)
        {
            if(s[i]!='a')
            {
                st=i;
                break;
            }
        }
    for(int i=st+1;i<len;i++)
    {
        if(s[i]=='a')
        {
            ed=i;
            break;
        }
    }
    if(st==len&&ed==len)
    {
        s[len-1]='z';
    }
    for(int i=st;i<ed;i++)
    {
        s[i]=(char)(s[i]-1);
    }
    cout<<s<<endl;
    return 0;
}

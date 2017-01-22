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



int main()
{
    //freopen("output.txt","w",stdout);
    string s1,s2;
    while(cin>>s1>>s2)
    {
        int ans=0;
        for(int i=0;i<s1.size();i++)
            for(int j=0;j<s2.size();j++)
        {
            ans+=((s1[i]-'0')*(s2[j]-'0'));
        }
        cout<<ans<<endl;
    }
    return 0;
}

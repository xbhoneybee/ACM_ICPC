#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<cstdlib>
#include <sstream>
#include <deque>
#include<list>
#include<time.h>
#define ll long long
#define LL long long
#define inf 10000.00
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

int main()
{
    string s,t;
    cin>>s>>t;
    int ans=0;
    int correct[256]={0};
    vector<pair<char,char> >vec;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==t[i])
            correct[s[i]]=1;
        vec.push_back(make_pair(s[i],t[i]));
    }
    map<char,char>mp;
    int app[260]={0};
    for(int i=0;i<s.size();i++)
    {
        pair<char,char> p=vec[i];
        if(p.first==p.second)
            {
            continue;
            }
        else {
            if(correct[p.first]==1||correct[p.second]==1)
            {
                ans=-1;
                break;
            }
            if(mp.count(p.first)==0&&mp.count(p.second)==0)
            {
                mp[p.first]=p.second;
                mp[p.second]=p.first;
            }
            else if((mp.count(p.first)&&mp[p.first]!=p.second)||(mp.count(p.second)&&mp[p.second]!=p.first))
            {
                ans=-1;
                break;
            }
        }
    }
    if(ans==-1)
        cout<<-1<<endl;
    else{
        cout<<mp.size()/2<<endl;
        for(int i=0;i<26;i++)
        {
            if(mp.count((char)(i+'a'))==1&&i+'a'<mp[(char)i+'a'])
                cout<<(char)(i+'a')<<" "<<mp[(char)(i+'a')]<<endl;
        }
    }
    return 0;
}

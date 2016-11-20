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
#define inf 1000000009
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

int main()
{
    string s;
    cin>>s;
    int len=s.size();
    int flag=0;
    for(int i=0;i<=len;i++)
        for(int al=0;al<26;al++)
        {
            char a='a';
            a=char(a+al);
            string ss=s.substr(0,i)+a+s.substr(i,len-i);
            //cout<<ss<<endl;
            for(int j=0;j<(len+1)/2;j++)
            {
                if(ss.at(j)!=ss.at(len-j))
                    break;
                if(j==(len+1)/2-1)
                {
                    cout<<ss<<endl;
                    return 0;
                }
            }
        }
    cout<<"NA"<<endl;
    return 0;
}

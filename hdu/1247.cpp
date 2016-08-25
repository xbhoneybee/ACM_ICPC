#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string.h>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include <sstream>
#define inf 10000000000
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

int main()
{
    string s;
    vector<string> vec;
    set<string> st;
    while(!cin.eof())
    {
        cin>>s;
        st.insert(s);
    }
    set<string>::iterator ip;
    for(ip=st.begin();ip!=st.end();ip++)
    {
        string ss=*ip;
        int len=ss.size();
        for(int i=1;i<len-1;i++)
        {
            string suba,subb;
            suba=ss.substr(0,i);
            subb=ss.substr(i,len-i);
            if(st.count(suba)==1&&st.count(subb)==1)
            {
                vec.push_back(ss);
                break;
            }
        }
    }
    sort(vec.begin(),vec.end());
    vector<string>::iterator id;
    for(id=vec.begin();id!=vec.end();id++)
        cout<<*id<<endl;
    return 0;
}

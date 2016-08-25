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
#define inf 100000000
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

//B

int main()
{
    string s;
    cin>>s;
    ll ans=1;
    vector<ll> vec;
    ll m=1;
    int len=s.size();
    for(int i=1;i<len;i++)
    {
        if(s[i]-'0'+s[i-1]-'0'==9)
        {
            m++;
            if(i==len-1&&m!=1)
                if(m&1)
                vec.push_back(m/2+1);
        }
        else
        {   if(m!=1)
            {
                if((m&1))
                {
                vec.push_back(m/2+1);
                }
                m=1;
            }
        }
    }
    ll cot=vec.size();
    for(int i=0;i<cot;i++)
        ans*=vec[i];
    cout<<ans<<endl;
    return 0;
}
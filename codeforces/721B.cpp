#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<stdlib.h>
#include <sstream>
#include <deque>
#include<list>
#include<time.h>
#define ll long long
#define LL long long
#define inf 1e18
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;
//codeforeces
//B
int cmp(string a,string b)
{
    if(a.length()!=b.length())
        return a.length()<b.length();
    else return a<b;
}
int main()
{
    vector<string>vec;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        vec.push_back(s);
    }
    string ans;
    cin>>ans;
    int len=ans.length();
    sort(vec.begin(),vec.end(),cmp);
    int time=0,hask=0;
    int mint=0,maxt=0;
    int flag1=0;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i].length()<len)
        {
            hask++;time++;
            if(hask==k)
            {
                time+=5;
                hask=0;
            }
        }
        else if(vec[i].length()==len)
        {
            hask++;time++;
           if(!flag1) {
                mint=time;flag1=1;
           }
           if(i==n-1||vec[i+1].size()>len)
           {
               maxt=time;
               break;
           }
            if(hask==k)
            {
                time+=5;
                hask=0;
            }

        }
    }
    cout<<mint<<" "<<maxt<<endl;
    return 0;
}

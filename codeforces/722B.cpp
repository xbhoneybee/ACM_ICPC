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
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

//B
int p[105];
int main()
{
    int n;
    cin>>n;
    vector<string>s;
    string tmp;
    for(int i=0;i<n;i++)
        cin>>p[i];
    getline(cin,tmp);
    for(int i=0;i<n;i++)
       {
        getline(cin,tmp);
        s.push_back(tmp);
       }
    for(int i=0;i<n;i++)
    {
        int len=s[i].size();
        int tans=0;
        for(int j=0;j<len;j++)
        {
            if(s[i][j]=='a'||s[i][j]=='e'||s[i][j]=='i'||s[i][j]=='o'||s[i][j]=='u'||s[i][j]=='y')
                tans++;
        }
        if(tans!=p[i])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}

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
    int n;
    string s;
    cin>>n>>s;
    char pre=s[0],now;
    int ans=1;
    for(int i=0;i+1<s.size();i++)
    {
        now=s[i];
        if(now=='U'&&i+1<n&&s[i+1]=='D')
        ans++;
        else if(now=='D'&&i+1<n&&s[i+1]=='U')
        ans++;
        else if(now=='R'&&i+1<n&&s[i+1]=='L')
        ans++;
        else if(now=='L'&&i+1<n&&s[i+1]=='R')
        ans++;
    }
    for(int i=0;i+1<s.size();i++)
    {
        now=s[i];
        if(i&&s[i-1]!=s[i])pre=s[i-1];
        if(i+1<n&&pre=='U'&&s[i+1]=='D'&&(now=='L'||now=='R'))
        ans++,i++;
        else if(i+1<n&&pre=='D'&&s[i+1]=='U'&&(now=='L'||now=='R'))
        ans++,i++;
        else if(i+1<n&&pre=='R'&&s[i+1]=='L'&&(now=='U'||now=='D'))
        ans++,i++;
        else if(i+1<n&&pre=='L'&&s[i+1]=='R'&&(now=='U'||now=='D'))
        ans++,i++;
    }
    cout<<ans<<endl;
    return 0;
}

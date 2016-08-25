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
    int n;
    string s;
    cin>>n>>s;
    int appear[26]={0};
    int ans=0;
    int len=s.size();
    int needchange=0;
    for(int i=0;i<len;i++)
    {
        if(appear[s[i]-'a']==0)
            appear[s[i]-'a']++;
        else needchange++;
    }
    for(int i=0;i<26;i++)
    {
        if(appear[i]!=0) ans++;
    }
    if(needchange<=26-ans)
        printf("%d\n",needchange);
    else printf("-1\n");

    return 0;
}
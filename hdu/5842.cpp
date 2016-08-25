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
#define inf 1000000000000000000
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
using namespace std;


int main()
{
    int t;
    char s[100005];
    scanf("%d",&t);
    for(int it=1;it<=t;it++)
    {
        int len=0;
        int alpha[30]={0};
        scanf("%s",s+1);
        int n=strlen(s+1);
        for(int i=1;i<=n;i++)
        alpha[s[i]-'a']++;
        for(int i=0;i<26;i++)
            if(alpha[i]!=0) len++;

        printf("Case #%d: %d\n",it,len);
    }
    return 0;
}
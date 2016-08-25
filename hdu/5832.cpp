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



//模拟除法取模 可一位一位加
char longnumber[10000007];
int main()
{
    int cases=1;
    while(~scanf("%s",longnumber))
    {
        printf("Case #%d: ",cases++);
        int n=strlen(longnumber);
        int num=0;
        for(int i=0;i<n;i++)
        {
            num=(num*10+longnumber[i]-'0')%10001;
        }
        if(num) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
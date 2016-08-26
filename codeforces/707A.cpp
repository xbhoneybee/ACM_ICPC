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
#define mod 1000000007
#define ll long long
#define LL long long
#define inf 100000000
#define iosfalse ios::sync_with_stdio(false);
using namespace std;
//wa 输入  没看到空格QAQ  m也要改一下
char s[105][105];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    getchar();
    int flag=1;
    for(int i=0;i<n;i++)
       gets(s[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<2*m+1;j+=2)
    {
        if(s[i][j]=='C'||s[i][j]=='M'||s[i][j]=='Y')
        {
            flag=0;break;
        }
    }
    if(flag)
       printf("#Black&White\n");
    else printf("#Color\n");
    return 0;
}

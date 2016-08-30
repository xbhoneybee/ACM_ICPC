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
#include<deque> //双端队列
#define mod 1000000007
#define ll long long
#define LL long long
#define inf 10000000000000
#define iosfalse ios::sync_with_stdio(false);
using namespace std;


char s[1005][7];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    int flag=0;
    int d1=0,d2=0;
    int di=0;
    for(int i=0;i<n;i++)
    {
        if(s[i][0]=='O'&&s[i][1]=='O')
            {
                flag=1;
                d1=0;d2=1;
                di=i;
                break;
            }
        if(s[i][3]=='O'&&s[i][4]=='O')
        {
                flag=1;
                d1=3;d2=4;
                di=i;
                break;
        }
    }
    if(flag)
    {
        printf("YES\n");
        for(int i=0;i<n;i++)
        {
         if(i!=di)
                printf("%s\n",s[i]);
         else {
            for(int j=0;j<5;j++)
              if(j!=d1&&j!=d2)  printf("%c",s[i][j]);
              else printf("+");
            printf("\n");
         }
        }
    }
    else printf("NO\n");
    return 0;
}

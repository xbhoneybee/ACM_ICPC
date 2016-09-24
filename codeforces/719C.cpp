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
#define inf 1e5
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

//codeforces 9.23

//C

char s[200005];
int main()
{
    int t,n,point;
    scanf("%d %d",&n,&t);
    scanf("%s",s);
    for(point =0;point<n;point++)
    {
        if(s[point]=='.')
            break;
    }
    int five;
    for( five=point+1;five<n;five++)
    {
        if(s[five]>'4')
           {five++;break;}
    }
    if(five==n&&five==point+2)
    {
        five--;
        if(s[five]>'4')
        {
           int pre=five-=2;
           while(s[pre]=='9')
           {
            s[pre]='0';
            pre--;
           }
           if(pre!=-1)
           s[pre]++;
           else printf("1");
            for(int i=0;i<=five;i++)
                printf("%c",s[i]);
            printf("\n");
        }
        else{
            if(s[five]=='0') five-=2;
            for(int i=0;i<=five;i++)
                printf("%c",s[i]);
            printf("\n");
        }
        return 0;
    }
    five--;
    while(five>point)
    {

        if(s[five]>'4'&&t)
        {

            five--;t--;
            s[five]++;
        }
        else break;
    }
    if(five==point)
    {
        five--;
        int pre=five;
         while(s[pre]=='9')
           {
            s[pre]='0';
            pre--;
           }
        if(pre!=-1)
           s[pre]++;
           else printf("1");
    }
    for(int i=0;i<=five;i++)
        printf("%c",s[i]);
            printf("\n");
    return 0;
}

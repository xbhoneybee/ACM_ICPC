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


int a[100005];
int c1,c2;
int main()
{
    int n,money;
    int flag=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&money);
        a[i]=money/25;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==1)   c1++;
        if(a[i]==2)
        {
            if(c1>0)
            {
                c1--;c2++;
            }else {
            flag=0;break;
            }
        }
        if(a[i]==4)
        {
            if(c1>=1&&c2>=1){c1--;c2--;}
            else if(c1>=3){c1-=3;}
            else {flag=0;break;}
        }
    }
    if(flag==1)
        printf("YES\n");
    else printf("NO\n");

    return 0;
}
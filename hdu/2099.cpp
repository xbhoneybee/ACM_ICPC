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
#define mod 1000000007
#define iosfalse ios::sync_with_stdio(false);
using namespace std;
const int MAXN=1024;

int main()
{
    int a,b;
    while(~scanf("%d %d",&a,&b)&&a)
    {
        int top=(a+1)*100/b;
        int floor=(a)*100/b;
        for(int i=floor;i<=top;i++)
        {
            if(b*i>=a*100&&b*i<(1+a)*100) //waµã
            {
                printf("%02d",b*i%100);
                if(i<(top*b==(a+1)*100?top-1:top))//waµã
                printf(" ");
                else printf("\n");
            }
        }
    }
    return 0;
}

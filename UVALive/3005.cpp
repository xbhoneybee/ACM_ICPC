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
#define inf 1000000000
#define ll long long
#define mod 1000000007//  这里不要写成100000000+7 define是替换！！！
#define iosfalse ios::sync_with_stdio(false);
using namespace std;
const int MAXN=1025;



int main()
{
    char lace[40];
    while(~scanf("%s",lace)&&lace[0]!='E')
    {
        int ansmax=-inf,ansmin=inf;
        int n=strlen (lace);
        for(int i=0;i<n;i++)//左到右 B1W0
            {   int tem=0,k=0;
                 for(int j=0;j<n;j++)
                {
                    if(lace[(i+j)%n]=='B')
                        tem+=(1<<k);
                    k++;
                }
                if(tem>ansmax) ansmax=tem;
                if(tem<ansmin) ansmin=tem;
        }
        for(int i=0;i<n;i++)//左到右 B0W1
            {   int tem=0,k=0;
                 for(int j=0;j<n;j++)
                {
                    if(lace[(i+j)%n]=='W')
                        tem+=(1<<k);
                    k++;
                }
                if(tem>ansmax) ansmax=tem;
                if(tem<ansmin) ansmin=tem;
        }
        for(int i=0;i<n;i++)//右到左 B1W0
            {   int tem=0,k=0;
                 for(int j=0;j<n;j++)
                {
                    if(lace[(i-j+n)%n]=='B')
                        tem+=(1<<k);
                    k++;
                }
                if(tem>ansmax) ansmax=tem;
                if(tem<ansmin) ansmin=tem;
        }
        for(int i=0;i<n;i++)//右到左 B0W1
            {   int tem=0,k=0;
                 for(int j=0;j<n;j++)
                {
                    if(lace[(i-j+n)%n]=='W')
                        tem+=(1<<k);
                    k++;
                }
                if(tem>ansmax) ansmax=tem;
                if(tem<ansmin) ansmin=tem;
        }
        cout<<ansmin<<' '<<ansmax<<endl;
    }
    return 0;
}
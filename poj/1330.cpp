#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <math.h>
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


int a[10005];//存i的祖先
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[y]=x;
        }
        int son1,son2;
         int h1=0,h2=0;
        scanf("%d %d",&son1,&son2);
            int j=son1;
            while(a[j]!=0)
            {
                h1++;
                j=a[j];
            }
            j=son2;
            while(a[j]!=0)
            {
                h2++;
                j=a[j];
            }
        while(h1!=h2)
        {
            if(h1>h2)
            {
                son1=a[son1];
                h1--;

            }
            else {
                    son2=a[son2];
                    h2--;
                }
        }
        while(son1!=son2)
        {
            son1=a[son1];
            son2=a[son2];
        }
        printf("%d\n",son1);
        memset(a,0,sizeof  a);
    }
    return 0;
}
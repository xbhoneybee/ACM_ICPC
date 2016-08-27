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
#define inf 10000000000000
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

//换换脑子 判断每个立方块n^3复杂度 tle 那么数每条边的每个立方块n^2复杂度
int xoy[1002][1002];
int yoz[1002][1002];
int zox[1002][1002];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,ans=0;
        scanf("%d %d",&n,&m);
        getchar();
        int tm=m;
        while(tm--)
        {
            char axi1,axi2;
            int num1,num2;
            scanf("%c=%d,%c=%d",&axi1,&num1,&axi2,&num2);
            getchar();
            if((axi1=='X'&&axi2=='Y')||(axi1=='Y'&&axi2=='X'))
            {
                if((axi1=='Y'&&axi2=='X'))
                    swap(num1,num2);

                for(int i=1;i<=n;i++)
                {
                    if(yoz[num2][i]==0&&zox[i][num1]==0&&xoy[num1][num2]==0)
                        ans++;
                }
                xoy[num1][num2]=1;
            }else if((axi1=='Y'&&axi2=='Z')||(axi1=='Z'&&axi2=='Y'))
            {
                if((axi1=='Z'&&axi2=='Y'))
                    swap(num1,num2);

                for(int i=1;i<=n;i++)
                {
                    if(xoy[i][num1]==0&&zox[num2][i]==0&&yoz[num1][num2]==0)
                        ans++;
                }
                yoz[num1][num2]=1;
            }else
            {
                if((axi1=='X'&&axi2=='Z'))
                    swap(num1,num2);

                for(int i=1;i<=n;i++)
                {
                    if(xoy[num2][i]==0&&yoz[i][num1]==0&&zox[num1][num2]==0)
                        ans++;
                }
                zox[num1][num2]=1;
            }

        }
        printf("%d\n",ans);
    memset(xoy,0,sizeof xoy);
    memset(yoz,0,sizeof yoz);
    memset(zox,0,sizeof zox);
    }
    return 0;
}

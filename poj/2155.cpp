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

//E 二维树状数组 
//解法详见浅谈信息学竞赛中的浅谈信息学竞赛中的"0" 和"1"有详细证明

int c[MAXN][MAXN];
int lowbit(int x)
 {
  return x&(-x);
 }
void add(int x,int y,int det)
 {
  int i,j;
  for(i=x;i<=MAXN;i+=lowbit(i))
   for(j=y;j<=MAXN;j+=lowbit(j))
    c[i][j]+=det;
 }
int getsum(int x,int y)
 {
  int i,j,sum=0;
  for(i=x;i>0;i-=lowbit(i))
   for(j=y;j>0;j-=lowbit(j))
    sum+=c[i][j];
  return sum;
 }
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=1;i<=q;i++)
        {
            char s[10];
            scanf("%s",s);
            if(s[0]=='C')
            {
                int x1,y1,x2,y2;
                scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                add(x1,y1,1);
                add(x2+1,y1,1);
                add(x1,y2+1,1);
                add(x2+1,y2+1,1);
            }
            else {
                int x1,y1;
                scanf("%d %d",&x1,&y1);
                if(getsum(x1,y1)%2==1)
                    printf("1\n");
                else printf("0\n");
            }
        }
        memset(c,0,sizeof c);
        printf("\n");
    }
    return 0;
}
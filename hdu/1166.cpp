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

int c[50025];
int lowbit(int x)//计算lowbit
{
     return x&(-x);
}
 void add(int i,int val)//将第i个元素增加val注意i不可为零
 {
     while(i<=50025)//n为所开数组上界
     {
         c[i]+=val;
         i+=lowbit(i);
     }
 }
 int sum(int i)//求前i项和
 {
     int s=0;
     while(i>0)
     {
         s+=c[i];
         i-=lowbit(i);
     }
     return s;
 }
int main()
{
    int t;
    scanf("%d",&t);
    for(int it=1;it<=t;it++)
    {
        int n;
      scanf("%d",&n);
      for(int i=1;i<=n;i++)
      {
        int tem;
        scanf("%d",&tem);
        add(i,tem);
      }
      char s[20];
      int x,nu;
      printf("Case %d:\n",it);
      while(scanf("%s",s)&&s[0]!='E')
      {
        scanf("%d %d",&x,&nu);
        if(s[0]=='Q')
            printf("%d\n",sum(nu)-sum(x-1));
        else if(s[0]=='A')
            add(x,nu);
        else add(x,-nu);
      }
      memset(c,0,sizeof c);
    }
    return 0;
}
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
const int MAXN=32005;

//因为以y增序给出star 所以判断前i-1个star中有多少个star的x小于第i个的x
//假设存在数组a[i]表示下标为i的位置上有多少个星星
//c为其对应树状数组

int c[MAXN],level[MAXN],n;
int lowbit(int x)//计算lowbit
{
     return x&(-x);
}
void update(int i,int val)//将第i个元素增加val注意i不可为零
 {
     while(i<=MAXN)//n为数组上界
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
    int n,x,y;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        ++x;//树状数组从1开始
        level[sum(x)]++;//计算坐标x左边一共有的星星数，存入level
        update(x,1);//在x处增加一个star
    }
    for(int i=0;i<n;i++)
        printf("%d\n",level[i]);
    return 0;
}
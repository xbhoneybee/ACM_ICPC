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

//思路特殊  反向思考 复杂度O nlogn
//因为q最多是3e6，所以要统计一下序列中哪些数出现过,出现过多少次,然后用一个二重循环
//i,j 遍历1->3e6当i*j>3e6 时 break ,这样可以统计出,乘积为i*j的数对个数，
//再做一个累加，就可以的到乘积小于等于i*j的有多少个
//具体看代码 思路很独特

int a[3000006];
ll sum[3000006];
int main()
{
    int n,p,maxa=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        a[x]++;
        maxa=max(maxa,x);
    }
    for(int i=0;i<=maxa;i++)
        for(int j=0;j<=maxa;j++)
    {
        {
            if(i*j>3000000) break;
            else
            {
                if(i==j) sum[i*j]+=a[i]*(a[j]-1);
                else sum[i*j]+=a[i]*a[j];
            }
        }
    }
    for(int i=1;i<=3000000;i++)
        sum[i]+=sum[i-1];
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&p);
        printf("%I64d\n",(long long)n*(n-1)-sum[p-1]);
    }
    return 0;
}

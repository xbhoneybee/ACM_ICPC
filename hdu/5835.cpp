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

//题目数据有bug 可以用sum/2 水过，所以我这题不确定一定正确
int main()
{
    int t;
    int a[15]={0};
    scanf("%d",&t);
    for(int it=1;it<=t;it++)
    {
        printf("Case #%d: ",it);
        int n;
        int sum=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
                sum+=a[i];
            }
    if(n==1) {
        if(a[0]>=2) printf("1\n");
        else printf("0\n");
        continue;
    }
        sort(a,a+n);
    int cost=0;
    int i=0,j=n-1;
    for(;i<j;)
    {
        if(cost+a[i]*2<=sum/2)
        {
            cost+=a[i]*2;
            if(a[j]>=a[i])
            a[j]-=a[i];
            else{
                a[j-1]-=(a[i]-a[j]);
                a[j]=0;j--;
            }
            i++;
        }else
        {
            cost=sum/2;
            break;
        }
    }
    if(cost<sum/2) cost++;
    printf("%d\n",cost);
    }
    return 0;
}

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

// 数学题  不等式求最小值

ll a[100005];
int main()
{
    int n;
    scanf("%d",&n);
    ll sum=0,maxa=-inf;
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        sum+=a[i];
        maxa=max(maxa,a[i]);
    }
    ll ans=maxa;
    ll tem=ceil((double )sum/(n-1));
    ans=max(tem,ans);
    printf("%I64d\n",ans);
    return 0;
}
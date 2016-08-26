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
#define inf 100000000
#define iosfalse ios::sync_with_stdio(false);
using namespace std;
//搜索勾股数性质
int main()
{
    ll n;
    scanf("%I64d",&n);
    if(n%2==0&&n>2)
        printf("%I64d %I64d\n",n/2*n/2-1,n/2*n/2+1);
    else{
        if(n==1)
            printf("-1\n");
        else  if(n!=2)
        {
            printf("%I64d %I64d\n",n*n/2,n*n/2+1);
        }
        else printf("-1\n");
    }
    return 0;
}

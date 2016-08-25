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

int main()
{
    int t;
    int n;
    ll sum=1;
    scanf("%d",&t);
    while(t--){

        scanf("%d",&n);
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
                {
                    sum+=i;
                    if(i*i!=n)
                    sum+=(n/i);
                }
        }
        printf("%I64d\n",sum);
        sum=1;
    }
    return 0;
}
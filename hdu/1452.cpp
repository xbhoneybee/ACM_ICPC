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
#define mod 29
#define iosfalse ios::sync_with_stdio(false);
using namespace std;
const int MAXN=1025;

int PowerMod(int a, int b, int c)
{
    int ans = 1;
    a = a % c;
    while(b>0)
    {
    if(b % 2 == 1)
    ans = (ans * a) % c;
    b = b/2;
    a = (a * a) % c;
    }
    return ans;
}
int main()
{
    int x;
    while(~scanf("%d",&x)&&x)
    {
        int ans=(PowerMod(2,2*x+1,mod)-1)%mod;
        ans=ans*(PowerMod(3,x+1,mod)-1)%mod;
        ans=ans*PowerMod(2,27,mod)%mod;
        ans=ans*(PowerMod(167,x+1,mod)-1)%mod;
        ans=ans*PowerMod(166,27,29)%mod;
        printf("%d\n",ans%mod);
    }
    return 0;
}

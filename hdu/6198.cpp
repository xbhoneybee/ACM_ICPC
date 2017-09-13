//#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<vector>
#include<map>
#include<sstream>
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);

using namespace std;


/**
队友直接发现规律是2*n+3项-1 太快了
*/
const long long mmd=998244353;
void myMultiply(long long (&f1)[4], long long (&f2)[4])
{
    long long res[4];
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
        {
            int idx = 2 * i + j;
            res[idx] = 0;
            for(int k = 0; k < 2; ++k)
                res[idx] = (res[idx]+(f1[2*i+k] * f2[2*k+j])%mmd)%mmd;
        }
    for(int i = 0; i < 4; ++i)
        f1[i] = res[i];
}
int main()
{
    long long n;
    while(scanf("%I64d", &n) != EOF)
    {
        n=2*n+3;
        long long f[4] = {1, 1, 1, 0};
        if(n < 0) printf("-1\n");
        else if(n == 0) printf("0\n");
        else if(n == 1) printf("1\n");
        else
        {
            long long res[4] = {1, 0, 0, 1};
            n = n - 1;
            while(n > 0)
            {
                if(n & 1)
                {
                    myMultiply(res, f);
                }
                myMultiply(f, f);
                n >>= 1;
            }
            printf("%I64d\n", (res[0]+mmd)%mmd-1);
        }
    }
    return 0;
}


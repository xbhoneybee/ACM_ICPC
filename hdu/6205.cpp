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

#define FI(n) FastIO::read(n)

namespace FastIO {
    const int SIZE = 1 << 16;
    char buf[SIZE], obuf[SIZE], str[60];
    int bi = SIZE, bn = SIZE, opt;
    int read(char *s) {
        while (bn) {
            for (; bi < bn && buf[bi] <= ' '; bi++);
            if (bi < bn) break;
            bn = fread(buf, 1, SIZE, stdin);
            bi = 0;
        }
        int sn = 0;
        while (bn) {
            for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
            if (bi < bn) break;
            bn = fread(buf, 1, SIZE, stdin);
            bi = 0;
        }
        s[sn] = 0;
        return sn;
    }
    bool read(int& x) {
        int n = read(str), bf;

        if (!n) return 0;
        int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
        for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
        if (bf < 0) x = -x;
        return 1;
    }
};
int n;
const int maxn=1000006;
int a[maxn],p[maxn],c[maxn*2];
int main()
{
    while(FI(n))
    {
        for(int i=1;i<=n;i++)
        {
            FI(a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            FI(p[i]);
            c[i]=a[i]-p[i];
        }
        for(int i=n+1;i<=2*n;i++)
        {
            c[i]=c[i-n];
        }
        int L=1,R=1;
        long long sum=0;
        int st=1,maxl=0;
        while(L<=R&&L<=n)
        {
            while(sum>=0&&R-L+1<=n)
            {
                sum+=c[R];
                R++;
            }
            if(R-L>maxl)
            {
                maxl=R-L;
                st=L;
                if(maxl==n)
                    break;
            }
            sum-=c[L++];
        }
        printf("%d\n",st-1);
    }
    return 0;
}

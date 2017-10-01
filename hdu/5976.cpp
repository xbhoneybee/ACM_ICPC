#include <bits/stdc++.h>
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
#define iosfalse ios::snync_with_stdio(false);

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
const long long mmd=1e9+7;
long long PowerMod(long long a, long long  b, long long c)
{
    long long ans = 1;
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
long long prex[100005]={0,1};
int main()
{
    for(int i=2;i<50000;i++)
    {
        prex[i]=(prex[i-1]*i)%mmd;
    }
    int T;
    FI(T);
    while(T--)
    {
        int xx;
        long long x;
        FI(xx);
        x=xx;
        long long k=(sqrt(2*x));
        while((k+2)*(k-1)/2<=x)
        {
            k++;
        }
        k--;
        if(x==1)
            printf("1\n");
        else if(k==2)
            printf("%d\n",x);
        else {

        int exd=x-(2+k)*(k-1)/2;

        k++;
        int divd=k-exd;

        if(divd!=1)
        {
            printf("%I64d\n",prex[k]*PowerMod(divd,mmd-2,mmd)%mmd);
        }else {
            divd++;
            printf("%I64d\n",prex[k-1]*PowerMod(divd,mmd-2,mmd)%mmd*(k+1)%mmd);
        }
        }
    }
    return 0;
}

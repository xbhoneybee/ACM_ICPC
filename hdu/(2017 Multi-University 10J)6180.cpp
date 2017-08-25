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


inline char nc() {
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int _read() {
    char ch = nc(); int sum = 0;
    while (!(ch >= '0'&&ch <= '9'))ch = nc();
    while (ch >= '0'&&ch <= '9')sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}
const int maxn=100005;
struct P
{
    int s,e;
    friend  bool operator < (const P &t1, const P &t2)
    {
        if(t1.s!=t2.s)
            return t1.s<t2.s;
        return t1.e<t2.e;
    }
}p[maxn];
int machinest[maxn];
int main()
{
    int T;
    T=_read();
    while(T--)
    {
        int n;
        n=_read();
        for(int i=0;i<n;i++)
        {
            p[i].s=_read();
            p[i].e=_read();
        }
        sort(p,p+n);
        multiset<int>st;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.insert(p[i].e);
                machinest[cnt++]=p[i].s;
                continue;
            }
            auto pos= st.lower_bound(p[i].s+1);//set 内部lower_bound O log N 
            if(pos==st.begin())
            {
                st.insert(p[i].e);
                machinest[cnt++]=p[i].s;
            }else{
                pos--;
                st.erase(pos);
                st.insert(p[i].e);
            }
        }
        int icnt=0;
        long long sum=0;
        for(auto ip=st.begin();ip!=st.end();ip++,icnt++)
        {
            sum+=(*ip)-machinest[icnt];
        }
        printf("%d %I64d\n",cnt,sum);
    }
    return 0;
}

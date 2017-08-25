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
vector<int>son[maxn];
int pipei;
bool dfs(int rt)
{
    bool ret=false;//是否有子节点没匹配
    for(int i=0;i<son[rt].size();i++)
    {
        if(dfs(son[rt][i]))
        {
            ret=true;
        }
    }
    if(ret)
    {
        pipei++;
        return false;//当前节点新增匹配
    }
    return true;//当前节点未匹配
}
int main() {
	int t;
	t=_read();
	while (t--) {
		int n, k;
		n=_read();
		k=_read();
		for(int i=1;i<=n;i++)
            son[i].clear();
        pipei=0;
		for (int i = 2; i <= n; i++) {
			int s=_read();
			son[s].push_back(i);
		}
		dfs(1);
        if(2*pipei>k)
        {
            printf("%d\n",(k+1)/2);
        }else {
            printf("%d\n",k-pipei);
        }

	}
	return 0;
}

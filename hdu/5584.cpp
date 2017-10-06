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
#define iosfalse ios::sync_with_stdio(false);

using namespace std;


//L  数学 gcd不变
 
long long gcd(long long a, long long b) { return (b) ? gcd(b, a%b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b)*b; }
long long ans = 0;
void baoli(long long x, long long y, long long cd)
{
	if (x == y)
		return;
	if (y < x)
		swap(x, y);
	if (cd*y / (cd + x) + lcm(cd*y / (cd + x), x) == y)
	{
		ans++;
		baoli(x, cd*y / (cd + x), cd);
	}

}
int main()
{
	int T, cas = 1;
	scanf("%d", &T);
	while (T--)
	{
		long long x, y;
		scanf("%I64d %I64d", &x, &y);
		ans = 1;
		baoli(x, y, gcd(x, y));
		printf("Case #%d: %I64d\n", cas++, ans);
	}
	return 0;
}

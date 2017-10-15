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


//C

const int  maxn =5005;
const long long MOD= 998244353;
const long long mod = 998244353;
long long C[maxn][maxn];
//预处理组合数
void createCCC() {
	C[0][0] = 1;
	for (int i = 1; i < maxn; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
	}
}
long long AAA[maxn];
//预处理阶乘
void createAAA() {
	AAA[0] = 1;
	for (int i = 1; i < maxn; i++) {
		AAA[i] = AAA[i - 1] * i;
		AAA[i] = AAA[i] % MOD;
	}
}
long long solve(long long a, long long b) {
	if (a > b) swap(a, b);
	long long res = 0;
	for (int i = 0; i <= a; i++) {
		res += C[a][i] * C[b][i] % MOD*AAA[i] % MOD;
		res %= MOD;
	}
	return res;
}
int main() {
	iosfalse
	createCCC();
	createAAA();
	long long a, b, c;
    cin >> a >> b >> c;
	long long res = 1;
	res *= solve(a, b);
	res %= mod;
	res *= solve(b, c);
	res %= mod;
	res *= solve(a, c);
	res %= mod;
	cout << (res+mod)%mod << endl;
	return 0;
}

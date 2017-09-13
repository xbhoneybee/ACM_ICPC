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
签到题，读完题后有点晕，队友告诉我大概题意，xjb猜一下ac
*/

int main()
{
    long long m,k;
    while(scanf("%I64d %I64d",&m,&k)!=EOF)
    {
        printf("%I64d\n",k*(m-k+1));
    }
    return 0;
}

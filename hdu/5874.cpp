#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<stdlib.h>
#include <sstream>
#include <deque>
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

//1007 转化：n个点的图, 要求有尽量多的边, 并且不存在三元环. 这个边数就是m的下界.
//则构造一个完全二分图 ，使得边数尽可能相等这个完全二分图就是答案 如果多一条边就构成3元环
//我和队友讨论这题，他差不多想出来求得无3元环的图但我们没想到边数公式，
//也不知道完全二分图这种东西，最后队友被我不断带偏我们就gg了
//还是太菜了
int main()
{
    long long n,m;
    while(~scanf("%I64d %I64d",&n,&m))
    if( n/2 *(n-n/2) > m)
        cout<<"F"<<endl;
    else cout<<"T"<<endl;
    return 0;
}

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
#include<list>
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n>2)
        {
        if((n-1)%2==0)
            cout<<"Balanced"<<endl;
        else
            cout<<"Bad"<<endl;
        }
        if(n==2)
            cout<<"Bad"<<endl;
    }
    return 0;
}
//n个shape 与其他形成n-1 种关系，win or lose  需要相等 所以模2==0，比赛原代码，未优化。

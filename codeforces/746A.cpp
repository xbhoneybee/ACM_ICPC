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
#define ll long long
#define LL long long
#define inf 1000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

int main()
{
    int a,b,c,i;
    cin>>a>>b>>c;
    for( i=1;;i++)
    {
        if(a<i||b<2*i||c<4*i)
            break;
    }
    cout<<7*(i-1)<<endl;
    return 0;
}

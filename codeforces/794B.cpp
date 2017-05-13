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
#define lowbit(x) x&-x

using namespace std;


//B

int n,h;
const double PI=acos(-1.0);
int main()
{
    cin>>n>>h;
    for(int i=1;i<n;i++)
    {
        printf("%.12f ",pow(i*1.0/(n*1.0),1.0/2.0)*h);
    }
    printf("\n");
    return 0;
}

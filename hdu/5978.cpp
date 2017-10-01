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



//H

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        n++;
        if(n&1)
        {
            printf("1\n");
        }else printf("0\n");
    }
    return 0;
}

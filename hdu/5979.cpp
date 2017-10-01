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

//I

const double PI=acos(-1.0);
int main()
{
    int n,d;
    while(scanf("%d %d",&n,&d)!=EOF)
    {
        double ans=0;
        for(int i=0;i<n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            ans+=0.5*d*d*sin((tmp*1.)/180.*PI);
        }
        printf("%.3f\n",ans);
    }
    return 0;
}

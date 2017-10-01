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


//J

int deall(int x)
{
    int cc=0;
    for(int i=0;i<4;i++)
    {
        int a=x%(1<<8);
        x/=(1<<8);
        if(a==97)
           cc++;
    }
    return cc;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int tmp;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tmp);
            cnt+=(deall(tmp));
        }
        printf("%d\n",cnt);
    }
    return 0;
}

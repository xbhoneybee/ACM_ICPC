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

int main()
{
    //iosfalse cin cout TLE
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        ll a,b;
        scanf("%I64d %I64d",&a,&b);
        ll ab=a*b;
        ll K=(ll)pow(ab,1.0/3.0);
        while(K*K*K<ab)
            K++;
        if(K*K*K==ab&&a%K==0&&b%K==0)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

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

//uva 11021

double a[1005];
double f[1005];
int main()
{
    int t,it=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,m;
        scanf("%d %d %d",&n,&k,&m);
        for(int i=0;i<n;i++)
            scanf("%lf",&a[i]);
        double ans=1;
        f[0]=0;f[1]=a[0];
        for(int i=2;i<=m;i++)
        {
            double tmp=f[i-1];
            f[i]=a[0];
            for(int j=1;j<n;j++)
            {
                f[i]+=a[j]*tmp;
                tmp*=f[i-1];
            }
        }
        for(int i=0;i<k;i++)
            ans=ans*f[m];
        printf("Case #%d: %.7f\n",it++,ans);
    }

    return 0;
}

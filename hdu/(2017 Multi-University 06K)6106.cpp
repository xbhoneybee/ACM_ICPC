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

bool check(int a[])
{
    if((a[0]+a[6]>=a[3]+a[5])&&(a[1]+a[6]>=a[3]+a[4])&&(a[2]+a[6]>=a[4]+a[5])
        &&a[3]>=a[6]&&a[4]>=a[6]&&a[5]>=a[6])
        return true;
    return false;
}
int cnt(int a[])
{
    return a[0]+a[1]+a[2]-a[3]-a[4]-a[5]+a[6];
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int maxstudent=0;
        for(int i=0;i<n;i++)
        {
            int a[10];
            for(int j=0;j<7;j++)
                scanf("%d",&a[j]);
            if(check(a))//判断数据是否合法
            {
                maxstudent=max(maxstudent,cnt(a));
            }
        }
        printf("%d\n",maxstudent);
    }
    return 0;
}

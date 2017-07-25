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

int a[100005];
int minuss[100005];
int dp[100005];
int main()
{
    int n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<n;i++)
        {
            minuss[i]=a[i-1]-a[i];
        }
        //dp求最大子段和
        int maxlen=-1e8;
        for(int i=1;i<n;i++)
        {
            dp[i]=max(dp[i-1]+minuss[i],minuss[i]);
            maxlen=max(maxlen,dp[i]);
        }
        printf("%d\n",maxlen);
    }
    return 0;
}
//写完之后看别人题解发现自己好蠢
//只用遍历一遍保留当前最大值即可

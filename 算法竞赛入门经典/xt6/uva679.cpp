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
#define ll long long
#define LL long long
#define inf 100000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;


int main()
{
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int d,I;
        scanf("%d%d",&d,&I);
        int ans=1;
        for(int i=1;i<d;i++)
        {
            if(I&1)
            {
                ans=2*ans;
                I=(I+1)/2;
            }else {
                ans=2*ans+1;
                I/=2;
            }
        }
        printf("%d\n",ans);
    }
    scanf("%d",&t);
    return 0;
}

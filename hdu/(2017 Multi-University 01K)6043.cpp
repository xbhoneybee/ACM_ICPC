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
    int n,id=1;
    long long k;
    while(scanf("%d %I64d",&n,&k)!=EOF){
        long long ans=0;
        if(k<=n-1)
            ans=k;
        else {
            int rnd=k/(n-1);
            if(k%(n-1)!=0)
                rnd++;
            int pos=k%(n-1);
            if(pos==0) pos=n-1;
            if(pos==1){
                ans=(rnd%2==0)?n:n-1;
            }else ans=pos-1;
        }
        printf("Case #%d: %d\n",id++,ans);
    }
    return 0;
}

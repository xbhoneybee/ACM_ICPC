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
#define inf 10000000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;
///A ac

ll dpB[1000006],dpW[1000006];
const long long mmd=1e9+7;
int main()
{
    int T;
    scanf("%d",&T);
    for(int it=0;it<T;it++)
    {
        int a,b,n;
        scanf("%d %d %d",&a,&b,&n);
        memset(dpW,0,sizeof dpW);
        memset(dpB,0,sizeof dpB);
        dpW[0]=1;
        dpB[0]=1;
        dpW[1]=1;
        dpB[1]=1;
        if(a==1)dpW[1]=0;
        if(b==1)dpB[1]=0;
        for(int i=2;i<=n;i++)
        {
            if(i-a>=0)
                dpW[i]+=(dpW[i-1]+dpB[i-1]-dpB[i-a])%mmd;
            else dpW[i]+=dpW[i-1]+dpB[i-1];
            dpW[i]=(dpW[i]+mmd)%mmd;
            if(i-b+1>=0)
                dpB[i]=(dpB[i-1]+dpW[i-1]-dpW[i-b])%mmd;
            else dpB[i]+=dpB[i-1]+dpW[i-1];
            dpB[i]=(dpB[i]+mmd)%mmd;
        }
          cout<<((dpW[n]+dpB[n])%mmd)<<endl;
    }
    return 0;
}

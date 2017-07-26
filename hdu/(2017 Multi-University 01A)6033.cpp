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


int ans[100005];
int main()
{

    int id=1;
    int m;
    double s=2;
    int tmp=0;
    for(int i=2;i<=100000;i++)
        {
            s*=2;
            if(s>10)
            {
                s=s/10.;
                tmp++;
            }
            ans[i]=tmp;
        }
    while(scanf("%d",&m)!=EOF){
        printf("Case #%d: %d\n",id++,ans[m]);
    }
    return 0;
}

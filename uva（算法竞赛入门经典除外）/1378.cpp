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

//玄学SG函数
int a[30],sg[30],vis[150];
int main()
{
    int n,id=1;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        printf("Game %d: ",id++);
        if(n==1)
        {
            printf("-1 -1 -1\n");
            continue;
        }
        sg[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j;k<n;k++)
                {
                    vis[sg[j]^sg[k]]=1;
                }
            }
            for(int p=0;;p++)
            {
                if(vis[p]==0)
                {
                    sg[i]=p;
                    break;
                }
            }
            memset(vis,0,sizeof vis);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]&1)
                ans^=sg[i];
        }
        if(ans==0)
            printf("-1 -1 -1\n");
        else {
        for(int i=0;i<n-1;i++)
        {
            if(a[i]==0)
                continue;
            for(int j=i+1;j<n;j++)
            {
                for(int k=j;k<n;k++)
                {
                    if((ans^sg[j]^sg[k]^sg[i])==0)
                    {
                        printf("%d %d %d\n",i,j,k);
                        goto theme;
                    }
                }
            }
        }
        theme:
            ;
        }
    }
    return 0;
}

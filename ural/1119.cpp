/***      DP   ***/

#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>
#include<string.h>
#include<set>
#define inf 100000000.000

using namespace std;

 int n,m,k;
 bool flag[1010][1010];
 double f[1010][1010];
 int main()
 {
     cin>>n>>m>>k;
     memset(flag,false,sizeof(flag));
     for(int i=0;i<k;i++)
     {
         int x,y;
         cin>>x>>y;
         flag[x][y]=true;
     }
     for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            f[i][j]=inf;
        }
        f[0][0]=0.;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++){
            if(i) f[i][j]=min(f[i][j],f[i-1][j]+100);
            if(j) f[i][j]=min(f[i][j],f[i][j-1]+100);
            if(flag[i][j]) f[i][j]=min(f[i][j],f[i-1][j-1]+100.*sqrt(2));
            }
        printf("%.0f\n",f[n][m]);
     return 0;
 }
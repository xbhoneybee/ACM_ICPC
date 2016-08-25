/***      最大子矩阵     ***/

#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>
#include<string.h>
#include<set>
#define inf 100000000.000

using namespace std;

int main()
{
    int n;
    cin>>n;
    int rec[110][110];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            cin>>rec[i][j];
            if(j>=1)
            rec[i][j]+=rec[i][j-1];
        }
        int ans=-inf;
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
                for(int k=0,temp=0;k<n;k++){
                    if(i==0) temp+=rec[k][j];
                    else temp+=rec[k][j]-rec[k][i-1];
                    ans=max(ans,temp);
                    if(temp<0) temp=0;//不能少
                    }
    cout<<ans<<endl;
    return 0;
}
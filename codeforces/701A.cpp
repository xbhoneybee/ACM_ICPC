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
    int n,sum=0,average;
    int cardv[105]={0};
    bool cardu[105];
    int ans[105][5]={0};
    cin>>n;
    for(int i=1;i<=n;i++)
        {
            cin>>cardv[i];
            sum+=cardv[i];
        }
    average=sum*2/n;
    //cout<<average<<endl;
    memset(cardu,0,sizeof(cardu));
    int t=1;
    for(int i=1;i<=n/2;i++)
    {
        while(!ans[i][0]){
        if(!cardu[t]){
            ans[i][0]=t;
            cardu[t]=1;
            for(int j=1;j<=n;j++){
                if(!cardu[j]&&cardv[j]+cardv[t]==average){
                    ans[i][1]=j;
                    cardu[j]=1;
                    break;
                }
            }
        }
        t++;
    }

    }
    for(int i=1;i<=n/2;i++)
    {
        cout<<ans[i][0]<<' '<<ans[i][1]<<endl;
    }
    return 0;
}
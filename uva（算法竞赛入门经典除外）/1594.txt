#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>
#include<string.h>
#include<set>
#include<queue>
#include<cctype>
#include<map>
#define inf 1000000000.000
#define ll long long
#define mod 1000000007//  这里不要写成100000000+7 define是替换！！！
using namespace std;

int n;
int iszero(int x[])
{
    for(int i=1;i<=n;i++)
        if(x[i]!=0)
            return 0;
    return 1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[1005]={0};
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(iszero(a))
            {
                cout<<"ZERO"<<endl;continue;
            }

        int b[1005];
        int flag=1;
        for(int k=0;k<1002;k++)//1000次内一定出现结果
        {                      //若1000次内没有zero则一定loop，
            if(flag)
            {
                for(int i=1;i<=n-1;i++)
                {
                b[i]=abs(a[i]-a[i+1]);
                }
                b[n]=abs(a[1]-a[n]);
                if(iszero(b))
                {
                cout<<"ZERO"<<endl;break;
                }
                flag=0;
            }
            else{
                for(int i=1;i<=n-1;i++)
                {
                a[i]=abs(b[i]-b[i+1]);
                }
                a[n]=abs(b[1]-b[n]);
                if(iszero(a))
                {
                    cout<<"ZERO"<<endl;break;
                }
                flag=1;
            }
            if(k==1001)
                cout<<"LOOP"<<endl;
        }
    }

    return 0;
}

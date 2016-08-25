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
#define inf 1000000000
#define ll long long
#define mod 1000000007//  这里不要写成100000000+7 define是替换！！！
using namespace std;
#define iosfalse ios::sync_with_stdio(false);

//  模拟有问题  啊啊啊啊啊用数量算不要用占用行列数

int main()
{
    int n,m;
    cin>>n>>m;
    getchar();
    int wallnum=0;
    int x[1005]={0};
    int y[1005]={0};
    char ma[1005][1005];
    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
        {
            scanf("%c",&ma[i][j]);
            if(ma[i][j]=='*')
            {
                wallnum++;
                x[i]++;
                y[j]++;
            }
        }
        getchar();
        }
     if(wallnum==0)
        {
            cout<<"YES"<<endl;
            cout<<1<<' '<<1<<endl;
            return 0;
        }
     for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(ma[i][j]=='*')
                {if((wallnum-x[i]-y[j]+1)==0)
                {
                    cout<<"YES"<<endl;
                    cout<<i<<' '<<j<<endl;
                    return 0;
                }
                }
                else {
                    if((wallnum-x[i]-y[j])==0)
                {
                    cout<<"YES"<<endl;
                    cout<<i<<' '<<j<<endl;
                    return 0;
                }
                }
            }
    cout<<"NO"<<endl;
    return 0;
}

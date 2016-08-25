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


// 分组的背包问题

int main()
{
    int t;
    cin>>t;
    while (t--){
    int n,m;
    cin>>n>>m;
    int c[100]={0};
    int w[100][100]={0},v[100][100]={0};
    for(int i=0;i<n;i++)
    {
        scanf("%d",&c[i]);
        for(int j=0;j<c[i];j++)
        {
            scanf("%d %d",&w[i][j],&v[i][j]);
        }
    }
    int f[1005]={0};
    for(int i=0;i<n;i++)
        for(int j=m;j>=0;j--)
            for(int h=0;h<c[i];h++){
                if(j-w[i][h]>=0)
                f[j]=max(f[j],f[j-w[i][h]]+v[i][h]);
            }
    cout<<f[m]<<endl;

    }
    return 0;
}

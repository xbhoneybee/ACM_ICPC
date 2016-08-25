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

//  |运算 前缀和+后缀和降低时间复杂度
//a[i]*x x>2 则2进制长度增加,为使结果最大，将所有x*在一起，乘上2进制最长的数，多个最长不确定，
//枚举 前缀和后缀和使复杂度从O(n*n)->O(n)

ll a[200005];
ll prea[200005];
ll sufa[200005];
int main()
{
    int n,k,x;
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    prea[0]=0;//注意初始化为0 不是1！！！
    sufa[n+1]=0;//
    for(int i=1;i<=n;i++)
        {
            prea[i]=prea[i-1]|a[i];
        }
     for(int i=n;i>=1;i--)
        {
            sufa[i]=sufa[i+1]|a[i];
        }
    ll mul=x;
    for(int i=1;i<k;i++)
        mul*=x;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,(a[i]*mul)|prea[i-1]|sufa[i+1]);
    }
    cout<<ans<<endl;

    return 0;
}

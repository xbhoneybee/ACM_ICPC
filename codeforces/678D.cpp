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

//递归会爆栈，迭代会tle


// 等比数列求和+次方求膜+费马小定理+乘法逆元

ll PowerMod(ll a, ll b, ll c)
{
        ll ans = 1;
        a = a % c;
        while(b>0)
        {
            if(b % 2 == 1)
            ans = (ans * a) % c;
            b = b/2;
            a = (a * a) % c;
        }
    return ans;
}
int main()
{
    ll a,b,x,n;
    cin>>a>>b>>n>>x;
    if(a==1)   //divide
        cout<<(x+n%mod*b)%mod<<endl;
    else{
        //求b*(an-1)/(a-1)对mod取模 
        //a-1 的乘法逆元为（a-1)的mod-2次方==1/(a-1)  费马小定理
        ll ans1=(PowerMod(a,n,mod)*x)%mod;
        ll ans=PowerMod(a-1,mod-2,mod);//费马小定理+逆元
        ll ans2=(PowerMod(a,n,mod)-1)*(ans)%mod*b;
        ll ans3=(((ans1+ans2) %mod )+mod )% mod;
        cout<<ans3<<endl;
    }
    return 0;
}

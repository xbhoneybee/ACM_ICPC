#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string.h>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#define inf 1000000000000000000
#define ll long long
#define mod 1000000007
#define iosfalse ios::sync_with_stdio(false);
using namespace std;
const int MAXN=1024;

//题都看不懂 /(ㄒoㄒ)/~~
//异或后的  1 的个数是3的倍数(包括0)
//矩阵快速幂  
/* k==1时 认为都成立 k==2时将a[i]a[j]异或的结果存入矩阵c c是一个0,1矩阵，再让c=c*c
矩阵c[i][j]=c[i][1]*c[1][j]+c[i][2]*c[2][j]+...+c[i][n]*c[n][j]，我们得到的即为以
ai开头，aJ结尾的长度为3的序列个数！因为要求每两个异或的结果都是3 的倍数，只有不是0时 才说明都是3的倍数满足，可加
接下来用原01矩阵更新矩阵c，得到的又为开头元素为ai，结尾元素为aj的长度为4的序列个数！
依次乘k-1次即得到结果，这部分可以用矩阵快速幂进行优化。
最后把得到的矩阵中的每个元素的值加起来即为长度为k的满足条件的序列个数！
实质上就是floyd求长度为k的道路。
巧妙的利用矩阵乘法的性质解决问题！这很矩阵！*/

ll a[105];
int n;    //可以做模板了
struct Matrix
{
    int row,cal;
    ll m[105][105];
};
Matrix init(Matrix a,ll t)
{
    for(int i=0;i<a.row;i++)
        for(int j=0;j<a.cal;j++)
        a.m[i][j]=t;
    return a;
}
Matrix mul(Matrix a,Matrix b)
{
    Matrix ans;
    ans.row=a.row;ans.cal=b.cal;
    ans=init(ans,0);
    for(int i=0;i<a.row;i++)
        for(int j=0;j<b.cal;j++)
            for(int k=0;k<a.cal;k++)
                ans.m[i][j]=(ans.m[i][j]+a.m[k][i]*b.m[k][j])%mod;
            return ans;
}
Matrix quick_pow(ll k,Matrix A)
{
    Matrix I;
    I.row=n;I.cal=n;
    I=init(I,0);
    for(int i=0;i<n;i++)
        I.m[i][i]=1;
    while(k){
        if(k&1)
            I=mul(I,A);
        A=mul(A,A);
        k>>=1;
    }
        return I;
}
int count(ll a)
{
    int ans=0;
    while(a)
    {
        if(a&1)
            ans++;
        a>>=1;
    }
    return ans;
}
int main()
{
    ll k;
    scanf("%d %I64d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    Matrix A;
    A.row=n;A.cal=n;
    A=init(A,0);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(count(a[i]^a[j])%3==0)
                A.m[i][j]=1;
    ll ans=0;
    A=quick_pow(k-1,A);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            (ans+=A.m[i][j])%=mod;
    printf("%I64d\n",ans);
    return 0;
}

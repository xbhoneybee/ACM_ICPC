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

/** 令f[i]=(long long)sqrt(a[i]);
打表发现 f[i]/f[i-1]=6.372左右,xjb 猜
f[n]=4*f[n-1]+17*f[n-2]-12*f[n-3];  然后矩阵快速幂
*/
long long f[]={0,0,31,197,1255};
const long long mmd=1e9+7;
const int MAXN=3;
const int MAXM=3;
struct Matrix{
int n,m;
long long a[MAXN][MAXM];
void m_clear()
{
    n=0;m=0;
    memset(a,0,sizeof a);
}
Matrix operator * (const Matrix &b) const {
    Matrix tmp;
    tmp.m_clear();
    tmp.n=n;tmp.m=b.m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<m;k++)
                tmp.a[i][j]=(tmp.a[i][j]+(a[i][k]*b.a[k][j])%mmd)%mmd;
    return tmp;
}
void m_print()
{
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout<<a[i][j]<<' ';
            cout<<endl;
        }
}
};
Matrix m_pow(Matrix A,long long n)
{
    Matrix tmp;
    tmp.m_clear();
    tmp.n=A.n;tmp.m=A.n;
    for(int i=0;i<A.n;i++)
        tmp.a[i][i]=1;
    while(n>0)
    {
        if(n&1)
            tmp=tmp*A;
        A=A*A;
        n>>=1;
    }
    return tmp;
}
int main()
{
    int T;
    long long n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d",&n);
        if(n<=4)
        {
            printf("%I64d\n",f[n]);
            continue;
        }
        Matrix K;
        K.m_clear();
        K.n=K.m=3;
        K.a[0][0]=4;K.a[0][1]=17;K.a[0][2]=-12;
        K.a[1][0]=1;K.a[1][1]=0;K.a[1][2]=0;
        K.a[2][0]=0;K.a[2][1]=1;K.a[2][2]=0;
        K=m_pow(K,n-4);
       
        printf("%I64d\n",(mmd+(f[4]*K.a[0][0]%mmd+f[3]*K.a[0][1]%mmd+f[2]*K.a[0][2]%mmd)%mmd)%mmd);
    }
    return 0;
}

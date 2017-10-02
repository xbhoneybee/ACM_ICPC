#include <bits/stdc++.h>
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


long long PowerMod(long long a, long long  b, long long c)
{
    long long ans = 1;
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

const int MAXN=2;
long long mmd;
struct Matrix{
int n;
long long a[MAXN][MAXN];
void m_clear()
{
    n=0;
    memset(a,0,sizeof a);
}
Matrix  operator * (const Matrix &b) const {
    Matrix tmp;
    tmp.m_clear();
    tmp.n=n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                tmp.a[i][j]=(tmp.a[i][j]+a[i][k]*b.a[k][j]%mmd)%mmd;
    return tmp;
}
};
Matrix m_pow(Matrix A,long long n)
{
    Matrix tmp;
    tmp.m_clear();
    tmp.n=A.n;
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
int main(){
    ios::sync_with_stdio(false);
    int T,x;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>x>>mmd;
        long long newpow=PowerMod(2,x,mmd*mmd-1);
        Matrix A;
        A.n=2;
        A.a[0][0]=5;A.a[0][1]=2;
        A.a[1][0]=12;A.a[1][1]=5;
        A=m_pow(A,newpow);
        printf("Case #%d: %I64d\n",i,(((A.a[0][0]*5%mmd+A.a[1][0]*2%mmd)%mmd)*2-1+mmd)%mmd);
    }
    return 0;
}

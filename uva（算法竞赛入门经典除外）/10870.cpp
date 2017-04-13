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
#define lowbit(x) x&-x

using namespace std;
const int MAXN=20;
const int MAXM=20;
long long  mmd;
struct Matrix{
int n,m;
long long a[MAXN][MAXM];
void m_clear()
{
    n=0;m=0;
    memset(a,0,sizeof a);
}
Matrix operator + (const Matrix &b) const {
    Matrix tmp;
    tmp.m_clear();
    tmp.n=n;tmp.m=m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
                tmp.a[i][j]=a[i][j]+b.a[i][j];
    return tmp;
}
Matrix operator - (const Matrix &b) const {
    Matrix tmp;
    tmp.m_clear();
    tmp.n=n;tmp.m=m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
                tmp.a[i][j]=a[i][j]-b.a[i][j];
    return tmp;
}
Matrix operator * (const Matrix &b) const {
    Matrix tmp;
    tmp.m_clear();
    tmp.n=n;tmp.m=b.m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<m;k++)
                tmp.a[i][j]=(tmp.a[i][j]+a[i][k]*b.a[k][j]%mmd)%mmd;
    return tmp;
}
};
Matrix m_pow(Matrix A,int n)
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
int a[20],f[20];
int main()
{
    int d,n;
    while(cin>>d>>n>>mmd){
    if(d==0&&n==0&&mmd==0)
        break;
    Matrix A;
    A.m_clear();
    A.n=d;A.m=d;
    for(int i=0;i<d;i++)
        cin>>A.a[d-1][d-i-1];
    for(int i=0;i<d;i++)
        cin>>f[i];
    for(int i=0;i<d-1;i++)
        A.a[i][i+1]=1;
    A=m_pow(A,n-d);
    long long ans_fn=0;
    for(int i=0;i<d;i++)
        ans_fn=(ans_fn+A.a[d-1][i]*f[i]%mmd)%mmd;
    cout<<ans_fn<<endl;
    }
    return 0;
}

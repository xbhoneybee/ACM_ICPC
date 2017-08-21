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



const long long mmd=1e9+7;
const int MAXN=3;
const int MAXM=3;
struct Matrix{
int n,m;
unsigned long long a[MAXN][MAXM];
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
                tmp.a[i][j]=((tmp.a[i][j]+(a[i][k]*b.a[k][j])%mmd)%mmd+mmd)%mmd;
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
    long long n;
    cin>>n;
    if(n==0)
        cout<<1<<endl;
    else if(n==1)
        cout<<3<<endl;
    else if(n==2)
        cout<<10<<endl;
    else {
        Matrix mt;
        mt.a[0][0]=3;
        mt.a[0][1]=1;
        mt.a[1][0]=1;
        mt.a[1][1]=3;
        mt.m=mt.n=2;
        mt=m_pow(mt,n-2);
        long long ans=(mt.a[0][0]*10+mt.a[0][1]*6)%mmd;
        cout<<ans<<endl;
    }
    return 0;
}

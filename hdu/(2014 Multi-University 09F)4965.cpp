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


int N,K;
const int MAXN=10;
const int MAXM=10;
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
            {
                for(int k=0;k<m;k++)
                    tmp.a[i][j]+=a[i][k]*b.a[k][j];
                tmp.a[i][j]%=6;
            }
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
Matrix CC;
int A[1010][10],B[10][1010],C[1010][1010],D[1010][1010];
int main()
{
    while(cin>>N>>K)
    {
        if(N==0)
            break;
        memset(A,0,sizeof A);
        memset(B,0,sizeof B);
        for(int i=0;i<N;i++)
            for(int j=0;j<K;j++)
                cin>>A[i][j];
        for(int i=0;i<K;i++)
            for(int j=0;j<N;j++)
                cin>>B[i][j];
        CC.m_clear();
        CC.m=K;
        CC.n=K;
        for(int i=0;i<K;i++)
            for(int j=0;j<K;j++)
                for(int k=0;k<N;k++)
                    CC.a[i][j]+=B[i][k]*A[k][j];
        CC=m_pow(CC,N*N-1);
        memset(C,0,sizeof C);
        for(int i=0;i<N;i++)
            for(int j=0;j<K;j++)
                for(int k=0;k<K;k++)
                    C[i][j]+=A[i][k]*CC.a[k][j];
        memset(D,0,sizeof D);
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                for(int k=0;k<K;k++)
                    D[i][j]+=C[i][k]*B[k][j];
        long long ans=0;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
            {
                D[i][j]%=6;
                D[i][j]=(D[i][j]+6)%6;
                ans+=D[i][j];
            }
        cout<<ans<<endl;
    }
    return 0;
}

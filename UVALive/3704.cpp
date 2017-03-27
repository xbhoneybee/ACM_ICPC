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


//爆int
//循环矩阵每次下行等于上行右移一位，可以On空间保存On*n 计算乘法 a[i][j]=a[(j-i+n%n)];

int mmd;
const int MAXN=520;
struct Matrix{//循环矩阵
int n;
ll a[MAXN];
void m_clear()
{
    n=0;
    memset(a,0,sizeof a);
}
Matrix operator * (const Matrix &b) const {
    Matrix tmp;
    tmp.m_clear();
    tmp.n=n;
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                tmp.a[i]=(tmp.a[i]+a[j]*b.a[(j-i+n)%n]%mmd)%mmd;
        }
    return tmp;
}
}matrix;
Matrix m_pow(Matrix& A,int n)
{
    Matrix tmp;
    tmp.m_clear();
    tmp.n=A.n;
    tmp.a[0]=1;
    while(n>0)
    {
        if(n&1)
            tmp=tmp*A;
        A=A*A;
        n>>=1;
    }
    return tmp;
}
ll g[510],ans[510];
int main()
{
    int n,d,k;
    while(scanf("%d %d %d %d",&n,&mmd,&d,&k)!=EOF)
    {
        for(int i=0;i<n;i++)
            cin>>g[i];
        matrix.m_clear();
        matrix.n=n;
        for(int j=0;j<n;j++)
            {
                if(min(abs(0-j),n-j)<=d)
                    matrix.a[j]=1;
            }
        matrix=m_pow(matrix,k);
        for(int i=0;i<n;i++)
        {
            ans[i]=0;
            for(int j=0;j<n;j++)
            {
                ans[i]=(ans[i]+(matrix.a[(j-i+n)%n]*g[j])%mmd)%mmd;
            }
            cout<<(ans[i]);
            if(i+1<n)
                cout<<" ";
            else cout<<endl;
        }
    }
    return 0;
}

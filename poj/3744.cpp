#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<stdlib.h>
#include <sstream>
#include <deque>
#define mod 1000000007
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e18
#define lowbit(x) x&-x
using namespace std;
//陷阱把直线分成了若干段，每一段都是安全的，求出通过这一段的概率，乘上跨过陷阱的概率，再乘下一段的概率就行了。
//具体来说，对于某一段长度为nk的线段k，设a是线段k的开头，b是线段k的结尾，nk=b-a-1，
//问题的解可以看做Pn1*(1-p)*Pn2*(1-p)*....Pnn*(1-p)，因为最后一个陷阱要跳过去才安全。
int mine[20];
struct Matrix{
int n,m;
double a[5][5];
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
                tmp.a[i][j]+=a[i][k]*b.a[k][j];
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
Matrix m_pow(Matrix A,int n)
{
    Matrix tmp;
    tmp.m_clear();
    tmp.n=A.n;tmp.m=A.m;

    tmp.a[0][0]=1;tmp.a[1][1]=1;//wa点

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
    int n;
    double p;
    while(scanf("%d %lf",&n,&p)!=EOF)
    {
    for(int i=1;i<=n;i++)
        scanf("%d",mine+i);
    sort(mine+1,mine+n+1);
    Matrix ans,A;
    A.m_clear();
    A.m=2;A.n=2;
    A.a[0][0]=p;A.a[0][1]=1-p;
    A.a[1][0]=1;
   // A.m_print();///
    ans.m_clear();
    ans.n=2;ans.m=1;ans.a[0][0]=p;ans.a[1][0]=1;
    double aans=1;
    //ans.m_print();///
    for(int i=1;i<=n;i++)
    {
        int tim=mine[i]-mine[i-1]-1;
        if(tim==-1) continue;
        if(tim>2)
        {
            ans=m_pow(A,tim-2)*ans;
            aans*=ans.a[0][0]*(1-p);
        }
        else  if(tim==2)aans*=(ans.a[0][0]*(1-p));
        else if (tim==1)aans*=(ans.a[1][0]*(1-p));
        else aans=0;
        ans.m_clear();
        ans.n=2;ans.m=1;ans.a[0][0]=p;ans.a[1][0]=1;
    }
    printf("%.7f\n",aans);
    }
    return 0;
}

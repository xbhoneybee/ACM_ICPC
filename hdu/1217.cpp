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

//floyd 找accumulate正环
int n;
map<string,int>strtoint;
double kx[40][40];
bool floyd()
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(kx[i][j]<kx[i][k]*kx[k][j])
                    kx[i][j]=(kx[i][k]*kx[k][j]);
            }
    for(int i=0;i<n;i++)
    {
        if(kx[i][i]>1)
        return true;
    }
    return false;
}
int main()
{
    int id=1;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)// 少这句WA4....
            break;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                kx[i][j]=0;
        strtoint.clear();
        for(int i=0;i<n;i++)
        {
            string str;
            cin>>str;
            strtoint[str]=i;
            kx[i][i]=1;
        }
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            string a,b;
            double dk;
            cin>>a>>dk>>b;
            int inta,intb;
            inta=strtoint[a];
            intb=strtoint[b];
            kx[inta][intb]=dk;
        }
        string ch;
        if(floyd())
            ch="Yes";
        else ch="No";
        printf("Case %d: %s\n",id++,ch.c_str());
    }
    return 0;
}

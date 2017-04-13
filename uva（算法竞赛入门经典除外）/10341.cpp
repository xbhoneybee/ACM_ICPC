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
//有时候二分逼近时可以规定迭代一定次数(int 类型不超过32次)
int p,q,r,s,t,u;
double fun(double x)
{
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
const double eps=1e-14;
int main()
{
    while(cin>>p>>q>>r>>s>>t>>u)
    {
        if(fun(0)<-eps||fun(1)>eps)
            cout<<"No solution"<<endl;
        else{
            double l=0,r=1;
            //for(int i=0;i<100;i++)
            while(l<r-1e-8)
            {
                double mid=(l+r)/2;
                if(fun(mid)>0)
                    l=mid;
                else r=mid;
            }
            printf("%.4f\n",l);
        }
    }
    return 0;
}

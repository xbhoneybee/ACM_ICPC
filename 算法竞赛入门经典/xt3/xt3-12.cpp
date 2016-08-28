#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
//uva11809 数学题||模拟题  打表
//详细介绍http://blog.csdn.net/crazysillynerd/article/details/43339157
//learn from it
double A[11][33];//store    A
int B[11][33];//store B
int main()
{
    for(int i=0;i<=9;i++)
        for(int j=1;j<=30;j++)
        {
            double dm=1-pow(2,-i-1);
            long long e=pow(2,j)-1;
            double t=log10(dm)+e*log10(2.);
            int intt=t;
            B[i][j]=intt;
            A[i][j]=pow(10,t-intt);//AeB以科学计数法表示log10A 一定为小数部分(假设A>1)
        }
    string s;
    while(cin>>s&&s!="0e0")
    {
        int pos=find(s.begin(),s.end(),'e')-s.begin();
        string sa=s.substr(0,pos);
        string sb=s.substr(pos+1,s.size()-pos);
        double a;
        int b;
        sscanf(sa.c_str(),"%lf",&a);
        sscanf(sb.c_str(),"%d",&b);
        if(a<1){
            a=a*10;b--;
        }
        int needb=0;
        for(int i=0;i<=9;i++)
        {
         for(int j=1;j<=30;j++)
            {
                if(b==B[i][j]&&fabs(A[i][j]-a)<1e-4)
                {
                    cout<<i<<' '<<j<<endl;
                    needb=1;
                    break;
                }
            }
            if(needb) break;
        }
    }
    return 0;
}

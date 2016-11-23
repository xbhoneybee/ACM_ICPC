#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define inf 100000000
using namespace std;

//1905

//读题 circular segment 心情复杂...我还sb得积分,结果积分列式子有误差...
int main()
{
    double L,n,c;
    const double prec=1e-12;
    while(~scanf("%lf %lf %lf",&L,&n,&c))
    {
        if(L<0)
            break;
        if(L==0||c==0||n==0)
        {
            printf("0.000\n");//WA 如果不处理输入-0.000
            continue;
        }
        double newl=(1+n*c)*L/2;
        double h=L/2;
        double l=0;
        double m;
        while(h-l>prec)
        {
            m=(l+h)/2;
            //double a=-4*m/(L*L);
            //double b=4*m/L;//这是我的sb积分
            //double q=((a*L+b)*sqrt((a*L+b)*(a*L+b)+1)-b*sqrt(b*b+1)+log((a*L+b+sqrt((a*L+b)*(a*L+b)+1))/(b+sqrt(b*b+1))))/(4*a);
            double R=L*L/(8*m)+m/2;
            double q=R*acos((R-m)/R);
            if(abs(q-newl)<prec)
                break;
            if(q>newl)
                h=m;
            else l=m;
            //cout<<l<<" "<<h<<endl;
        }
        printf("%.3f\n",l);
    }
    return 0;
}

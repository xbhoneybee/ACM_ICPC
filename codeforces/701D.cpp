#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>
#include<string.h>
#include<set>
#define inf 100000000.000
using namespace std;
//数学题 参考http://blog.csdn.net/xtulollipop/article/details/52006945

int main()
{
    int  n,l,v1,v2,k;
    cin>>n>>l>>v1>>v2>>k;
    int m=n/k;
    if(n%k!=0) m++;
    double a= double (l)*(v1+v2)/(2.*(m-1)*v1+v1+v2);
    double anst=double (l-a)/v1+a/v2;
    printf("%.16f\n",anst);
    return 0;
}
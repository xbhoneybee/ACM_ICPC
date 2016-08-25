#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    double average=(a+b+c)/3.0;
    printf("%.3f\n",average);
    return 0;
}

//注意类型转换，/3.0 而不是3
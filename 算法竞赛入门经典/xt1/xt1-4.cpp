#include <iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  printf("%f %f\n",sin(n/180.0*acos(-1.0)),cos(n/180.0*acos(-1.0)));
    return 0;
}

//注意sin cos 计算函数都是以弧度制，所以要将n弧度制。
//注意n/180.0 而非180 .类型转换。
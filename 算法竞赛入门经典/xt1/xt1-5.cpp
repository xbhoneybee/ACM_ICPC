#include <iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  double sum=n*95;
  if(sum>=300)
    sum*=0.85;
  printf("%.2f\n",sum);
    return 0;
}
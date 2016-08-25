#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    if(n%4==0&&n%100!=0)
            printf("yes\n");
    else if(n%400==0)
            printf("yes\n");
    else    printf("no\n");
    return 0;
}
//关于闰年的定义 4 的倍数，若是100的倍数必须是400的倍数。
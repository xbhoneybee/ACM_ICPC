#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
    int a[3];
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    sort(a,a+3);
    if(a[0]+a[1]>a[2])
    {
        if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2])
             printf("yes\n");
        else printf("no\n");
    }
    else printf("not a triangle\n");
    return 0;
}
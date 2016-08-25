#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<time.h>
using namespace std;

int main()
{
    int i=100,daffodil[1000]={0},counter=0;
    for(;i<1000;i++)
    {
        int i1=i/100;
        int i2=i%100/10;
        int i3=i%10;
        if(i1*i1*i1+i2*i2*i2+i3*i3*i3==i)
        daffodil[counter++]=i;
    }
    for(int j=0;j<counter;j++)
        cout<<daffodil[j]<<' ';
        cout<<endl;

    //printf("Time used = %.8f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

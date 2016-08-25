#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<time.h>
using namespace std;

int main()
{
   int a,b,c;
   int flag=1;
   while(scanf("%d %d %d",&a,&b,&c)!=EOF)
   {
       int sum=10;
       for(;sum<=100;sum++)
       {
            if((sum-a)%3==0&&(sum-b)%5==0&&(sum-c)%7==0)
                break;
            if(sum==100)
                flag=0;
       }
       if(flag)
       printf("%d\n",sum);
       else printf("No answer\n");
   }

    //printf("Time used = %.8f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

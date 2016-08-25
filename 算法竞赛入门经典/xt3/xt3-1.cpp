#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<time.h>
#include<string.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
    char s[85];
    scanf("%s",s);
    int n=strlen(s),counter=0,score=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='O')
            counter++;
        else counter=0;
        score+=counter;
    }
    printf("%d\n",score);
    }
    //printf("Time used = %.8f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
//UVa1585
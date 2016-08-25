#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<time.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

int main()
{
    char s[15][15];
    int r,c,value[15][15]={0},number=1,t=1;
    while(scanf("%d",&r)){
        if(r==0) break;
        if(t>1) printf("\n");
        scanf("%d",&c);
        getchar();
        for(int i=0;i<r;i++)
            gets(s[i]);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
        {
            if(s[i][j]=='*')
                value[i][j]=0;
            else{
                if(i-1<0||j-1<0||s[i-1][j]=='*'||s[i][j-1]=='*')
                    value[i][j]=number++;
                else value[i][j]=0;
            }
        }
        printf("puzzle #%d:\nAcross\n",t++);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {
                if(value[i][j])
                {
                    if(j-1<0||s[i][j-1]=='*')
                    {
                        printf("%3d.",value[i][j]);//%3d Ò×PE
                        putchar(s[i][j]);
                        int k=j;
                        while (k+1<c&&s[i][k+1]!='*')
                            putchar(s[i][++k]);
                        printf("\n");
                    }
                }
            }
         printf("Down\n");

         for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {
                if(value[i][j])
                {
                    if(i-1<0||s[i-1][j]=='*')
                    {
                        printf("%3d.",value[i][j]);
                        putchar(s[i][j]);
                        int z=i;
                        while (z+1<r&&s[z+1][j]!='*')
                            putchar(s[++z][j]);
                        printf("\n");
                    }
                }
            }
    number=1;
    }
    //printf("Time used = %.8f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
//uva232
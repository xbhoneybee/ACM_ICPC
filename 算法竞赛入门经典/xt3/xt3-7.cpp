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
    int T;
    scanf("%d",&T);
    while(T--){
    char s[60][1005]={0};
    char answer[1005]={0};
    int m,n,dif=0;
    int counter[1005][4]={0};
    scanf("%d %d",&m,&n);
        //getchar(); //注意吃掉'\n'
        //getchar(); //注意吃掉'\n'  //吃两个？？？？
        for(int i=0;i<m;i++)
           scanf("%s",s[i]);  //gets(s[i]) wa
        for(int j=0;j<n;j++)
            for(int i=0;i<m;i++)
        {
            switch(s[i][j]){
            case 'A': counter[j][0]++;break;
            case 'C': counter[j][1]++;break;
            case 'G': counter[j][2]++;break;
            case 'T': counter[j][3]++;break;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(counter[i][0]>=counter[i][1]&&counter[i][0]>=counter[i][2]
               &&counter[i][0]>=counter[i][3])
            {
                answer[i]='A';
                dif+=(m-counter[i][0]);
            }
            else if(counter[i][1]>=counter[i][0]&&counter[i][1]>=counter[i][2]
               &&counter[i][1]>=counter[i][3])
               {
                   answer[i]='C';
                   dif+=(m-counter[i][1]);
               }
            else if(counter[i][2]>=counter[i][0]&&counter[i][2]>=counter[i][1]
               &&counter[i][2]>=counter[i][3])
               {
                   answer[i]='G';
                   dif+=(m-counter[i][2]);
               }
            else if(counter[i][3]>=counter[i][0]&&counter[i][3]>=counter[i][1]
               &&counter[i][3]>=counter[i][2])
               {
                   answer[i]='T';
                   dif+=(m-counter[i][3]);
               }
        }
        //answer[n]='\0'; 可以不加直接%s输出
        printf("%s\n%d\n",answer,dif);

    }
    //printf("Time used = %.8f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
//uva1368
//wa的不知所以;用scanf ac;注意c++11取消了gets 最好不用;
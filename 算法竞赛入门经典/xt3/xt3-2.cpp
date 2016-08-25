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
    char s[105];
    scanf("%s",s);
    int n=strlen(s),num=0;
    double score=0,ms=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]>'B'&&s[i]<='O')
        {
            if(s[i]=='C') ms=12.01;
            if(s[i]=='H') ms=1.008;
            if(s[i]=='O') ms=16;
            if(s[i]=='N') ms=14.01;
            if((s[i+1]>'B'&&s[i+1]<='O')||i==n-1)
                {
                    score+=ms;
                    continue;
                }
        }
        else{
            char snum[80];
            snum[0]=s[i];
            while(s[i+1]<='B'||s[i+1]>'O'||i==n-1)
            {
                if(i==n-1)
                    break;
                i++;
                int j=1;
                snum[j++]=s[i];
            }
            num=atoi(snum);//自动将char 数组转int，记！
            score=score+num*ms;
        }
    }
    printf("%.3f\n",score);
    }
    //printf("Time used = %.8f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
//uva1586
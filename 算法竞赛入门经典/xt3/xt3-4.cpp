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
    char s[105];
    scanf("%s",s);
    int n=strlen(s),ans=0;
    for(int i=0;i<n;i++)
    {
        if(n%(i+1)==0)
        {
            char sc[105]={0};   //初始化很重要。
            strncpy(sc,s,i+1);  //strncpy (a,b,n) 将b前n个复制到a;
            char scn[105]={0};
            strncpy(scn,s,i+1);
            int times=n/(i+1)-1;
            while(times--){
                strcat(scn,sc);
            }
            if(strcmp(scn,s)==0)
                {
                    ans=i+1;
                }
        }
        if(ans)
            break;
        if(i==n-1)
            ans=n-1;
    }
    printf("%d\n",ans);
    if(T>0)
        printf("\n");
    }
    //printf("Time used = %.8f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
//uva455

#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<time.h>
#include<string.h>
using namespace std;
//环状链s的表示发p是否比q字典序小
int lesses (const char *s,int p,int q){
    int n=strlen(s);
    for(int i=0;i<n;i++)
        if(s[(p+i)%n]!=s[(q+i)%n]) //环状链表示法，逐个比较
            return s[(p+i)%n]<s[(q+i)%n];//利用ASCII码
    return 0;//返回0与非0区别在之后if判断用到
}

int main()
{
    int T;
    char s[105];
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s);
        int ans=0;
        int n=strlen(s);
        for(int i=1;i<n;i++)
            if(lesses(s,i,ans)) ans=i;
        for(int i=0;i<n;i++)
            putchar(s[(i+ans)%n]);
	putchar('\n');
    }
    //printf("Time used = %.8f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
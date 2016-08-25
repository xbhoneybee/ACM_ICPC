#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<time.h>
using namespace std;

int main()
{
    int i=123;
    for(;i<=329;i++)
    {
        int a=i,b=i*2,c=i*3;
        int  num[10]={0};
        num[a/100]=1;
        num[a%100/10]=1;
        num[a%10]=1;
        num[b/100]=1;
        num[b%100/10]=1;
        num[b%10]=1;
        num[c/100]=1;
        num[c%100/10]=1;
        num[c%10]=1;
        int flag=0;
        for(int j=1;j<=9;j++)
        {
            if(num[j]==0)
                break;
            if(j==9) flag=1;
        }
        if(flag) cout<<a<<' '<<b<<' '<<c<<endl;
    }

    //printf("Time used = %.8f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

//考虑到全排列计算机难以实现，最小abc=123 最大ghi=987则最大abc=329；枚举每组数字是否9个数字全部出现。
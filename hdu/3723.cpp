#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<stdlib.h>
#include <sstream>
#define mod 1000000007
#define ll long long
#define LL long long
#define inf 100000000
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

//卡特兰数+组合数+大数
//对付卡特兰数用一个数组存一个卡特兰数每位存10
//对付mod 10^100 不对100位以后的计算
//结合卡特兰数和组合数 递推公式为a [k]=a[k-1]*(n-2*i+2)*(n-2*i+1)/((i+1)*i) 注意乘除要分开计算
int n;
int main()
{
    while(~scanf("%d",&n))
    {
        int num=n/2;
        int len=1;//length of answer
        int ans[10000]={0};
        int catelan[10000]={0};
        ans[1]=1;
        catelan[1]=1;
        for(int i=1;i<=num;i++)
        {
            for(int j=1;j<=len;j++)
                catelan[j]*=(n-2*i+2)*(n-2*i+1);
            for(int j=1;j<len;j++)//j<len
            {
                if(catelan[j]>9)
                    {
                        catelan[j+1]+=catelan[j]/10;
                        catelan[j]%=10;
                    }
            }
        while(catelan[len]>9)
            {
                   {
                    catelan[len+1]=catelan[len]/10;
                    catelan[len]%=10;
                   }
                len++;
            }
            for(int j=len;j>=1;j--)
            {
                if(catelan[j]/((i+1)*i)==0)
                    {
                        {
                        catelan[j-1]+=catelan[j]*10;
                        catelan[j]=0;
                        if(len==j)//==
                            len--;
                        }
                    }
                else {

                    catelan[j-1]+=catelan[j]%((i+1)*i)*10;
                    catelan[j]/=((i+1)*i);

                }
            }
        for(int j=1;j<=100;j++)
            {
            ans[j]+=catelan[j];
            if(ans[j]>9)
            {
             ans[j+1]+=ans[j]/10;
             ans[j]=ans[j]%10;
            }
            }
        }
        len=100;  //在nnum次操作后限定len范围 每次for一遍限定好像会导致计算结果出错
        while(ans[len]==0)
            len--;
        
        for(int  i=len;i>=1;i--)//倒着输出
        {
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}

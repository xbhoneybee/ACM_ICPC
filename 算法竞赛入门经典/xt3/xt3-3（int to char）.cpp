字符串转换成数字，用atoi，atol，atof，分别对应的是整型，long型，double型。
itoa

　　功 能:把一整数转换为字符串
 　　用 法:char *itoa(int value, char *string, int radix);
 　　详细解释:itoa是英文integer to array(将int整型数转化为一个字符串,并将值保存在数组string中)的缩写.
 　　参数：
 　　value: 待转化的整数。
 　　radix: 是基数的意思,即先将value转化为radix进制的数，范围介于2-36，比如10表示10进制，16表示16进制。
 　　* string: 保存转换后得到的字符串。
 　　返回值：
 　　char * : 指向生成的字符串， 同*string。

　　备注:该函数的头文件是"stdlib.h"
参考http://blog.sina.com.cn/s/blog_4ba5b45e0102durh.html

uva1225

wa
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
    int ans[10]={0};
    char s[1000005];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char sn[105];
        sprintf(sn,"%d",i);//这里产生的新字符数组内存字符串,带'\0'
                       //也可在win下使用itoa定义在<stdlib.h>不过是非标准c函数 
        strcat(s,sn);  //strcpy赋值，strcmp比较，strcat连接
    }
    int m=strlen(s);   //strlen求字符数组内非空元素个数，无'\0'可以用，有'\0'不计算在内。
    for(int j=0;j<m;j++)
    {
        switch(s[j]){
        case '0': ans[0]++;break;
        case '1': ans[1]++;break;
        case '2': ans[2]++;break;
        case '3': ans[3]++;break;
        case '4': ans[4]++;break;
        case '5': ans[5]++;break;
        case '6': ans[6]++;break;
        case '7': ans[7]++;break;
        case '8': ans[8]++;break;
        case '9': ans[9]++;break;
        }
    }
    for(int k=0;k<10;k++)
        {
            printf("%d",ans[k]);
            if(k<9) printf(" ");
        }
    printf("\n");
    memset(ans,0,sizeof(ans));
    memset(s,0,sizeof(s));
    }
    //printf("Time used = %.8f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
//一直wa点：未找到。



修改后：
ac
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
    int ans[10]={0};
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int j=i;
       while(j>0)          //利用求位数方法直接计算每个数字的个数
       {
           ans[j%10]++;
           j/=10;
       }
    }
    for(int k=0;k<10;k++)
        {
            printf("%d",ans[k]);
            if(k<9) printf(" ");
        }
    printf("\n");
    memset(ans,0,sizeof(ans));
    }
    //printf("Time used = %.8f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
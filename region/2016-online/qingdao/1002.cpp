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
#include <deque>
#include<list>
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

double a[1000005];
char s[10000000];//恶心数据 1e5居然越界
char ss[10000000];
int main()
{
    double sum=0;
    for(ll i=1;i<=1000000;i++)//根据级数结果pai^2/6 小数点取5位后要求1e6才能满足精度
    {
        sum+=1/(double)(i*i);
        a[i]=sum;
    }
    ll n;
    while(~scanf("%s",s))
    {
        int len=strlen(s);//未给明范围,字符串输入,坑点，这不是最坑，最坑字符串1e5装不下！！！
        int lenss=0;
        if(len<18)
            sscanf(s,"%I64d",&n);
        else{
            int flag=1;
            for(int i=0;i<len;i++)
            {

                if(s[i]=='0'&&flag) {continue;}
                else flag=0;
                if(s[i]>='0'&&s[i]<='9')
                    ss[lenss++]=s[i];
                if(lenss>6) break;//减少时间
            }
            if(lenss>6) n=1000000;
            else sscanf(ss,"%I64d",&n);
        }
        if(n<=1000000)
        printf("%.5f\n",a[n]);
        else
          printf("%.5f\n",a[1000000]);
    }
    return 0;
}

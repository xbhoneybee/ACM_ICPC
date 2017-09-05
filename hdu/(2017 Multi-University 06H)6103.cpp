//#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<vector>
#include<map>
#include<sstream>
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);

using namespace std;

/**
由于dis A,B的特殊计算方式，这里只能采取从2端向中间的尺取法减少时间复杂度
A在左边向右边取，B从右边向左边取
*/

int m,k,n;
char str[5005];
int countt(int lst,int rst)
{
    int ret=0;
    int dis=0;
    int len=0;
    while(lst+len<rst-len)
    {
        while(lst+len<rst-len&&dis<=m)
        {
            dis+=abs(str[lst+len]-str[rst-len]);
            len++;
        }
        if(dis<=m)
        ret=max(ret,len);
        else ret=max(ret,len-1);
        dis-=abs(str[lst]-str[rst]);
        lst++;
        rst--;
        len--;
    }
    return ret;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&m);
        scanf("%s",str);
        n=strlen(str);
        int maxv=0;
        maxv=max(maxv,countt(0,n-1));
        for(int i=1;i<n-1;i++)
        {
            maxv=max(maxv,countt(i,n-1));
            maxv=max(maxv,countt(0,n-1-i));
        }
        printf("%d\n",maxv);
    }
    return 0;
}

#include <bits/stdc++.h>
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
#define ll long long
#define LL long long
#define inf 100000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

//c
int main()
{
    char a[110005],b[110005];
    scanf("%s%s",a,b);
    int Left[110005]={0},Right[110005]={0};
    int length_a=strlen(a);
    int length_b=strlen(b);
    int L=-1,R=-1;//从左边输出到L，从右边输出到R
    for(int i = 0;i<length_a&&L+1<length_b;i++)
    {
        if(a[i]==b[L+1])
        {
            Left[++L]=i;
        }
    }
    for(int i=length_a-1;i>=0&&length_b-(R+2)>=0;i--)
    {
        if(a[i]==b[length_b-(R+2)])
        {
            Right[++R]=i;
        }
    }
    if(L==-1&&R==-1)
    {
        printf("-\n");
    }
    else if(L==-1) {
        for(;R>-1;R--)
            printf("%c",b[length_b-(R+1)]);
        printf("\n");
    }else if(R==-1)
    {
        for(int i=0;i<=L;i++)
            printf("%c",b[i]);
        printf("\n");
    }else {
        if(L==length_b-1||R==length_b-1)//WA21  21TIMES TAT
            printf("%s\n",b);
        else {
    int l=0,r=0,maxlen=0;
    int adda[110005]={0},copy_r[110005]={0};
    for(int cnt=R,i=0;cnt>=0;cnt--)
        copy_r[i++]=Right[cnt];
    for(int i=0;i<=L;i++)
    {
        int number=Left[i];
        int pos=upper_bound(copy_r,copy_r+R+1,number)-copy_r;
        adda[i]=R+1-pos;
    }
    for(int i=0;i<=L;i++)
    {
        if(i+1+adda[i]>maxlen)
        {
            maxlen=i+1+adda[i];
            l=i;r=adda[i];
        }
    }
    if(R+1>maxlen)
    {
        l=-1;r=R+1;maxlen=R+1;
    }
    for(int i=0;i<=l;i++)
        printf("%c",b[i]);
    for(int i=r;i>0&&length_b-i>l;i--)
        printf("%c",b[length_b-i]);
    printf("\n");
        }
    }

    return 0;
}

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

///CCPC 2017 online
//1004 
/**
KMP 
将两个字符串反转一下, 这样要比较的就是前缀了, 就用KMP找匹配了, 
如果匹配到长度为x后失配或者s2到达末尾, 那么就存在长度为1, 2, 3…x的子串匹配,
ans+=x(x+1)/2 
三种情况 
1. 完全匹配, ans += j*(j+1)/2; j为已经匹配的长度(也就是s2的长度), 
然后j根据next数组跳转的下一个位置继续匹配 
2. 失配配, 同上, ans += j*(j+1)/2 
3. 到了s1的末尾, 最后还有一节, 再根据next数组找到所有匹配的前缀 
注意, j*(j+1)会爆int, 一直wa在这里
*/
const int maxn=1000006;
const long long mmd=1e9+7;
long long answer = 0;
char str1[maxn],str2[maxn];
int Next[maxn];
void getNext(char b[],int m)
{
    int j,k;
    j=0;k=-1;
    Next[0]=-1;
    while(j<m)
    {
        if(k==-1||b[j]==b[k]) Next[++j]=++k;
        else k=Next[k];
    }
}
void  KMP_Index(char a[],char b[])
{
    long long i=0,j=0;
    answer=0;
    int n=strlen(a);
    int m=strlen(b);
    getNext(b,m);
    while(i<n)
    {
        if(j==-1||a[i]==b[j])
        {
            i++;j++;
        }else {
            answer+=j*(j+1)/2;
            answer%=mmd;
            j=Next[j];
        }
        if(j==m) {
        answer+=j*(j+1)/2;
        answer%=mmd;
        j=Next[j];
        }
    }
    while(j!=-1)
    {
        answer+=j*(j+1)/2;
        answer%=mmd;
        j=Next[j];
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s %s",str1,str2);
        int n=strlen(str2);
        int n1=strlen(str1);
        for(int i=0;i<n/2;i++)
            swap(str2[i],str2[n-1-i]);
        for(int i=0;i<n1/2;i++)
            swap(str1[i],str1[n1-1-i]);
        KMP_Index(str1,str2);
        printf("%I64d\n",answer);
    }
    return 0;
}

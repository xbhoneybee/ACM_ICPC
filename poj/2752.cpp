#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string.h>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#define inf 1000000000000000000
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

//C  灵活使用kmp next 数组

char s[400004];
int ans[400004];
int num=1;
int Next[400005];
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
int main()
{
    while(~scanf("%s",s))
    {
        int len=strlen(s);
        getNext(s,len);
        ans[0]=len;
        int k=len;
        while(Next[k]>0)
        {
            ans[num++]=Next[k];
            k=Next[k];
        }
        sort(ans,ans+num);
        for(int i=0;i<num;i++)
            printf("%d ",ans[i]);
        printf("\n");
        memset(Next,0,sizeof Next);
        num=1;

    }
    return 0;
}


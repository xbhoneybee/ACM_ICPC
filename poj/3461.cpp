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


int Next[100005];//优化求next数组方法
void getNext(char b[],int m)
{
    int j,k;
    j=0;k=-1;
    Next[0]=-1;
    while(j<m)
    {
        if(k==-1||b[j]==b[k])
        {
            j++;k++;
            if(b[j]!=b[k])
            Next[j]=k;
            else Next[j]=Next[k];
        }
        else k=Next[k];
    }
}


int KMP_Index(char a[],char b[],int n,int m)
{
    int kmpi=0,kmpj=0;
    int time=0;
    while(kmpi<n)
    {
        if(kmpj==-1||a[kmpi]==b[kmpj])
        {
            kmpi++;kmpj++;
        }else kmpj=Next[kmpj];

        if(kmpj==m)
        {
        time++;
        kmpj=Next[kmpj];//活用next数组   好好理解！！！
        }
    }
     return time;
}
char Word[10004];
char text[1000006];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",Word);
        scanf("%s",text);
        int cotw=strlen(Word);
        int cott=strlen(text);
        getNext(Word,cotw);
        printf("%d\n",KMP_Index(text,Word,cott,cotw));
    }
    return 0;
}
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
#define ll long long
#define LL long long
#define inf 1000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

struct Node {
int cnt,length;
int next[26];
Node()
{
    cnt=0,length=0;
    memset(next,-1,sizeof next);
}
void init(){
    cnt = 0,length=0;
    memset(next, -1, sizeof(next));
    }
};
Node T[300050];
int len=1;//T数组下标
void insert(char *tar)
{
    Node *p=&T[0];
    int mid,tmpl=0;
    while(*tar)
    {
        tmpl++;
        mid=*tar-'a';
        if(p->next[mid]==-1)
        {
            T[len].init();
            p->next[mid]=len;//找到下一位 数组下标
            len++;
        }
        p=&T[p->next[mid]];//利用数组
        p->length=tmpl;
        tar++;
    }
    p->cnt++;
}
char abcd[300005];
const int mmd=20071027;
int dp[300005],lens;
void search(int tar,int lim)
{
    Node *p=&T[0];
    int sq=abcd[tar]-'a';
    int abcdid=tar;
    if(T[0].next[sq]==0)
        return ;
    else p=&T[T[0].next[sq]];
    while(p->length<=lim&&p->length>0)
    {
        if(p->cnt>0)
            {
                dp[tar]=(dp[tar]+dp[tar+p->length])%mmd;
            }
        abcdid++;
        if(abcdid>=lens)
        break;
        sq=abcd[abcdid]-'a';
        p=&T[p->next[sq]];
    }
}
int main()
{
    int n,idt=1;
    while(scanf("%s",abcd)!=EOF)
    {
        len=1;
        T[0].init();
        scanf("%d",&n);
        lens=strlen(abcd);
        for(int i=0;i<n;i++)
        {
            char word[104];
            scanf("%s",word);
            insert(word);
        }
        memset(dp,0,sizeof dp);
        dp[lens]=1;
        for(int i=lens-1;i>=0;i--)
        {
            search(i,lens-i);
            dp[i]%=mmd;
        }
        printf("Case %d: %d\n",idt++,dp[0]);
    }
    return 0;
}

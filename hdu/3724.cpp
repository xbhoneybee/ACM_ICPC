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

struct N
{
    double aln;
    int id;
} nu[10];
int cmp(N a, N b)
{
return a.aln<b.aln;
}
char s[1005];
char pro[32];
int asc[10];
int twow[]={1,2,4,8,16,32,64,128};

int cnt_node;
struct TrieNode{
int cnt;
struct TrieNode  *next[26];
void init(){
    cnt = 0;
    memset(next, 0, sizeof(next));
    }
}trie[500000];
inline TrieNode * new_node(){
    trie[cnt_node].init();
    return &trie[cnt_node++];
}
void insert_trie(TrieNode  *root, char *str)
{
     for(char *p=str; *p; ++p){
        int ch=*p-'a';
        if(root->next[ch]==NULL)
            root->next[ch] = new_node();
        root = root->next[ch];
        ++root->cnt;
    }
}

int search_trie(TrieNode *root, char *str)
{
     for(char *p=str; *p; ++p){
        int ch=*p-'a';
        if(root->next[ch]==NULL)
            return 0;
        root=root->next[ch];
    }
    return root->cnt;
}



int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m))
    {
        cnt_node=0;
        TrieNode *root=new_node();
        ll ans=0;
        for(int i=0;i<n;i++)
            {
                scanf("%s",s);
                insert_trie(root,s);
            }
        while(m--)
        {
            int que;
            scanf("%d",&que);
            int totch=0;
            for(int i=0;i<que;i++)
            {
                int num=0;
                for(int j=0;j<8;j++)
                {
                    scanf("%lf",&nu[j].aln);
                    nu[j].id=j;
                }
                sort(nu,nu+8,cmp);
                int j;
                for( j=0;j<7;j++)
                {
                    if(nu[j+1].aln/nu[j].aln>1.5)
                        break;
                }

                for(int k=0;k<=j;k++)
                    asc[nu[k].id]=0;
                for(int k=j+1;k<8;k++)
                    asc[nu[k].id]=1;
                for(int tt=0;tt<8;tt++)
                    {
                        num+=asc[tt]*twow[7-tt];
                    }
                pro[totch++]=(char)num;
            }
            pro[totch]='\0';

            int tem=search_trie(root,pro);
            ans+=tem;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

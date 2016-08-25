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
#include <sstream>
#define inf 10000000000
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

//使用trie树结构。在trie树节点中加入两个域isword和cnt。
//isword分别表示从根节点到该节点是否是一个单词，cnt表示有多少个单词经过这个节点。
//先将所有单词保存在trie树中，然后一个一个地查找，当到达某个节点使用cnt==1 或者 isword==true，
//那么从根到该节点组成的字符串便是该单词的最短前缀。
struct Node {
int cnt;//cnt表示有多少个单词经过这个节点。
int next[26];  //子树
bool isword;   //根到此节点是否构成单词
Node() //c++默认构造函数
{
    cnt=0;
    isword=false;
    memset(next,-1,sizeof next);
}
};
Node T[30005];
char words[1005][25];
int len=1;//T数组下标
char pre[30];
int idx=0;
void insert(char *tar)
{
    Node *p=&T[0];
    int mid;
    while(*tar)
    {
        p->cnt++;
        mid=*tar-'a';
        if(p->next[mid]==-1)
        {
            p->next[mid]=len;//找到下一位 数组下标
            len++;
        }
        p=&T[p->next[mid]];//利用数组
        tar++;
    }
    p->cnt++;
    p->isword=true;
}
void search(char *tar)
{
    Node *p=&T[0];
    int id;
    idx=0;
    while(p->cnt>1&& *tar)
    {
        pre[idx++]=*tar;
        id=*tar-'a';
        p=&T[p->next[id]];
        tar++;
    }
    pre[idx]='\0';
}
int main()
{
    int i,j;
    i=0;len=1;
    while(~scanf("%s",&words[i]))
    {
        char temp[25];
        strcpy(temp,words[i]);
        insert(temp);
        i++;
    }
    for(j=0;j<i;++j)
    {
        char t[25];
        strcpy(t,words[j]);
        search(t);
        printf("%s %s\n",words[j],pre);
    }
    return 0;
}
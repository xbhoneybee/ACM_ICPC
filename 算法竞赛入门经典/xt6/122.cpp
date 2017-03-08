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
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;


struct Tree
{
    int val,lson,rson;
    bool addnum;
    Tree(){val=-1;lson=-1;rson=-1;addnum=false;}
}tree[3000];
int id,add;
void init()
{
    id=0;
    add=0;
    tree[0]=Tree();
}
int main()
{
    char str[3000];
    init();
    //freopen("output.txt","w",stdout);
    while(scanf("%s",str)!=EOF)
    {
        if(strcmp(str,"()")==0)
        {
            queue<int>que;
            que.push(0);
            while(!que.empty())
            {
                int seq=que.front();
                que.pop();
                if(tree[seq].addnum==false)
                    add=1;
                if(tree[seq].lson!=-1)
                {
                    que.push(tree[seq].lson);
                }
                if(tree[seq].rson!=-1)
                    que.push(tree[seq].rson);
            }

            if(add==0)
            que.push(0);
            else printf("not complete");
            while(!que.empty())
            {
                int seq=que.front();
                que.pop();
                if(seq==0)
                    printf("%d",tree[seq].val);
                else
                printf(" %d",tree[seq].val);
                if(tree[seq].lson!=-1)
                {
                    que.push(tree[seq].lson);
                }
                if(tree[seq].rson!=-1)
                    que.push(tree[seq].rson);
            }
            printf("\n");
            init();
            continue;
        }
        int len=strlen(str);
        char number[3000];
        int v;
        int i=1,cur=0;
        while(str[i]!=',') i++;
        strncpy(number,str+1,i-1);
        number[i-1]='\0';///important!
        sscanf(number,"%d",&v);
        for(++i;i<len-1;i++)
        {
            if(str[i]=='L')
            {
                if(tree[cur].lson==-1)
                {
                    tree[cur].lson=++id;
                    tree[id]=Tree();
                    cur=id;
                }else {
                    cur=tree[cur].lson;
                }
            }else{
                if(tree[cur].rson==-1)
                {
                    tree[cur].rson=++id;
                    tree[id]=Tree();
                    cur=id;
                }else {
                    cur=tree[cur].rson;
                }
            }
        }
        tree[cur].val=v;
        if(tree[cur].addnum==false)
        tree[cur].addnum=true;//注意给出重复也错
        else add=1;
    }
    return 0;
}

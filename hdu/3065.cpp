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
#define lowbit(x) x&-x

using namespace std;

 
char shortstr[1002][52];
char longstr[2000006];
struct Trie_ac
{
    int next[1010*50][128],fail[1010*50],end[1010*50];//end[i]=iw,表示end[i]结尾的单词编号
    int root,L;
    int newnode()
    {
        for(int i = 0;i < 128;i++)
            next[L][i] = -1;
        end[L++] = -1;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char s[],int id)
    {
        int len = strlen(s);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][s[i]] == -1)
                next[now][s[i]] = newnode();
            now=next[now][s[i]];
        }
        end[now]=id;
    }
    void build()//建立fail指针
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < 128;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0;i < 128;i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    int used[1010];//每次query 时判断字符串匹配次数
    void query(char buf[],int n)
    {
        int len = strlen(buf);
        int now = root;
        memset(used,0,sizeof(used));
        for(int i = 0;i < len;i++)
        {
            now = next[now][buf[i]];
            int temp = now;
            while(temp != root)
            {
                if(end[temp] != -1)
                {
                    used[end[temp]]++;
                }
                temp = fail[temp];
            }
        }
        for(int i = 1;i <= n;i++)
            if(used[i])
                printf("%s: %d\n",shortstr[i],used[i]);
    }
};
Trie_ac ac;
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        ac.init();
        for(int i = 1;i <= n;i++)
        {
            scanf("%s",shortstr[i]);
            ac.insert(shortstr[i],i);
        }
        ac.build();
        scanf("%s",longstr);
        ac.query(longstr,n);
    }
    return 0;
}

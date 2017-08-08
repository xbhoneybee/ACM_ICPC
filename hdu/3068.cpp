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


// Manacher 
char str[110005];
char new_str[220005];
int RL[220005];
int Manacher(char *s)
{
    int len=strlen(s);
    int maxlen=1;
    for (int i=1;i<=len;i++)
    {
        new_str[2*i-1]='#';new_str[2*i]=s[i-1];
    }
    len=len*2+1;
    new_str[len]='#';
    int pos=0,R=0;
    for (int i=1;i<=len;i++)
    {
        if (i<R)
            RL[i]=min(RL[2*pos-i],R-i);
        else RL[i]=1;
        while (1<=i-RL[i]&&i+RL[i]<=len&&new_str[i-RL[i]]==new_str[i+RL[i]])//尝试扩展，注意处理边界
            RL[i]++;
        if (i+RL[i]>R) //更新R,pos
        {
            pos=i;
            R=i+RL[i];
        }
       maxlen=max(maxlen,RL[i]-1);
    }
    return maxlen;
}
int main()
{
    while(scanf("%s",str)!=EOF)
    {
        printf("%d\n",Manacher(str));
    }
    return 0;
}

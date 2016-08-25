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


//B HASH
char s[16000007];
int appear[10000007];
int main()
{
    int n,c;
  while(~scanf("%d %d",&n,&c))
    {
    int ans=1;
    scanf("%s",s);
    int asc[256]={0};
    int len=strlen(s);
    int num=0;
    int ascval=0;
    for(int i=0;i<len;i++)
    {
        if(asc[s[i]]==0)
            asc[s[i]]=ascval++;
    }
    for(int i=0;i<n;i++)
    {
        num=num*c+asc[s[i]];
    }
    appear[num]=1;
    int nc=1;
    for(int i=1;i<n;i++) nc*=c;
    for(int i=n,j=0;i<len;i++)
    {
        num-=(asc[s[j]])*nc;
        j++;
        num=num*c+asc[s[i]];
        if(appear[num]==0)
        {
            appear[num]=1;
            ans++;
        }
    }
    printf("%d\n",ans);
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<cstdlib>
#include <sstream>
#include <deque>
#include<list>
#include<time.h>
#define ll long long
#define LL long long
#define inf 10000.00
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;

char num[110][110];
int main()
{
    int id=0;
    while(~scanf("%s",num[id++]))
    {
        if(strcmp(num[id-1],"0")==0)
            break;
    }
    int ans[111]={0};
    int len=strlen(num[0]);
    for(int i=0;i<111;i++)
    {
        if(i<len)
        ans[110-i]=num[0][len-i-1]-'0';
        else ans[110-i]=0;
    }
    for(int i=1;i<id-1;i++)
    {
        len=strlen(num[i]);
        for(int j=0;j<len;j++)
        {
            ans[110-j]+=num[i][len-j-1]-'0';
        }
        for(int j=110;j>=0;j--)
        {
            if(ans[j]>=10)
            {
                ans[j-1]+=ans[j]/10;
                ans[j]=ans[j]%10;
            }
        }
    }
    int flag=1;
    for(int i=0;i<111;i++)
      if(flag&&ans[i]==0) continue;
      else {
        flag=0;
        printf("%d",ans[i]);
      }
    printf("\n");
    return 0;
}

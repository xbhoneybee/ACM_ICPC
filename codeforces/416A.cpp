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
#define inf 1000000009
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;
int main()
{
   int n;
   scanf("%d",&n);
   int be=-inf,b=-inf,se=inf,s=inf;//need initial
   int x;
   for(int i=0;i<n;i++)
   {
       char a[3],res;
       scanf("%s %d %c",a,&x,&res);
       if(strcmp(a,">=")==0)
       {
           if(res=='Y')
            be=max(be,x);
           else s=min(s,x);
       }else if(strcmp(">",a)==0)
       {
           if(res=='Y')
            b=max(b,x);
           else se=min(se,x);
       }else if((strcmp("<=",a)==0))
       {
           if(res=='Y')
            se=min(se,x);
           else b=max(b,x);
       }else if((strcmp("<",a)==0))
       {
           if(res=='Y')
            s=min(s,x);
           else be=max(be,x);
       }
   }
   int bb,bflag,ss,sflag;
   if((be!=-inf||b!=-inf)&&(se!=inf||s!=inf)){
   if(be>b)
   {
       bb=be,bflag=1;
   }else if(be<=b)
   {
       bb=b,bflag=0;
   }
   if(se<s)
   {
       ss=se,sflag=1;
   }else {
    ss=s;sflag=0;
   }
   if(bb>ss)
    printf("Impossible\n");
   else if(bb<ss)
   {
        if(bflag==1)
            printf("%d\n",bb);
        else if(sflag==1)
             printf("%d\n",ss);
        else if(ss-bb>1)
           printf("%d\n",ss-1);
        else
            printf("Impossible\n");
   }else
   {
       if(bflag==1&&sflag==1)
        printf("%d\n",bb);
       else
         printf("Impossible\n");
   }
   }
   else if(be==-inf&&b==-inf)
   {
       if(se!=inf&&s!=inf)
       {
           if(se<s)
            printf("%d\n",se);
           else printf("%d\n",s-1);
       }
        else if(se!=inf)
            printf("%d\n",se);
        else printf("%d\n",s-1);
   }else
   {
       if(be>b)
        printf("%d\n",be);
       else
        printf("%d\n",b+1);
   }

    return 0;
}

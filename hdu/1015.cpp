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
#include <deque>
#include<list>
#include<time.h>
#define ll long long
#define LL long long
#define inf 1e18
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

//hdu1015
int cmp(char a,char b)
{
    return a>b;
}
int main()
{
    ll n;
    char alph[15];
    while(scanf("%I64d",&n))
    {
        cin>>alph;
        if(n==0&&strcmp(alph,"END")==0)
            break;
        int len=strlen(alph);
        sort(alph,alph+len,cmp);
        for(int i1=0;i1<len;i1++)
            for(int i2=0;i2<len;i2++)
                for(int i3=0;i3<len;i3++)
                    for(int i4=0;i4<len;i4++)
                        for(int i5=0;i5<len;i5++)
                        {
                            int v=(alph[i1]-'A'+1);
                            int w=(alph[i2]-'A'+1);
                            int x=(alph[i3]-'A'+1);
                            int y=(alph[i4]-'A'+1);
                            int z=(alph[i5]-'A'+1);
                            if(v-w*w+x*x*x-y*y*y*y+z*z*z*z*z==n&&
                               v!=w&&v!=x&&v!=y&&v!=z&&
                                   w!=x&&w!=y&&w!=z&&
                                   x!=y&&x!=z&&z!=y)
                               {
                                printf("%c%c%c%c%c\n",alph[i1],alph[i2],alph[i3],alph[i4],alph[i5]);
                                goto  there ;
                               }
                            if(i1==len-1&&i2==len-1&&i3==len-1&&i4==len-1&&i5==len-1)
                                printf("no solution\n");
                        }
    there : ;
    }
    return 0;
}

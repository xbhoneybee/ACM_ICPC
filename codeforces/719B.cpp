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
#define inf 1e5
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

//codeforces 9.23
//B

char a[100005];
int sum1[100005];
int sum2[100005];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",a);
    for(int i=0;i<n;i++)
        {
            if(i&1)
            {
                if(a[i]!='b')
                    sum1[i]=1;
            }
            else{
                if(a[i]!='r')
                    sum1[i]=-1;
            }
        }
    for(int i=0;i<n;i++)
        {
            if(i&1)
            {
                if(a[i]!='r')
                    sum2[i]=-1;
            }
            else{
                if(a[i]!='b')
                    sum2[i]=1;
            }
        }
    int add1=0,add2=0;
    for(int i=0;i<n;i++)
    {
        add1+=sum1[i];
        add2+=sum2[i];
    }
    for(int i=0;i<n;i++)
    {
        if(add1>=0&&sum1[i]==-1)
        add1+=1;
        if(add1<0&&sum1[i]==1)
        add1+=-1;
        if(add2>=0&&sum2[i]==-1)
        add2+=1;
        if(add2<0&&sum2[i]==1)
        add2+=-1;
    }
    add1=abs(add1);
    add2=abs(add2);
    int ans=min(add1,add2);
    printf("%d\n",ans);

    return 0;
}

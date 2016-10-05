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
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

struct P
{
    int x;
    int y;
};
char mp1[2005][2005],mp2[2005][2005],mp3[2005][2005];
int main()
{
    int n,m;
    char C;
    char first[100];
    while(~scanf("%d %d '%c'",&m,&n,&C))
    {
        if(n==0)
            break;
        gets(first);
        vector<P> st1,st2;
        memset(mp1,0,sizeof mp1);
        memset(mp2,0,sizeof mp2);
        memset(mp3,0,sizeof mp3);
        for(int i=0;i<m;i++)
            gets(mp1[i]);
        gets(first);
        for(int i=0;i<m;i++)
            gets(mp2[i]);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
        {
            P p;
            if(mp1[i][j]==C)
            {
                p.x=i;p.y=j;st1.push_back(p);
            }
            if(mp2[i][j]==C)
            {
                p.x=i;p.y=j;st2.push_back(p);
            }
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(mp1[i][j]!=C)
                    mp3[i][j]=mp1[i][j];
                else
                    mp3[i][j]=mp2[i][j];
            }
        vector<P>::iterator ip1,ip2;
        P det;
        ip1=st1.begin(),ip2=st2.begin()
        P p1,p2;
        p1=*ip1;p2=*ip2;
        det.x=p2.x-p1.x;
        det.y=p2.y-p1.y;
        for(ip2=st2.begin();ip2!=st2.end();ip2++)
        {
            P t,u;
            u=*ip2;
            t.x=u.x+det.x;
            t.y=u.y+det.y;
            mp3[t.x][t.y]=C;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%c",mp3[i][j]);
            }
            printf("\n");
        }
        gets(first);
    }
    return 0;
}

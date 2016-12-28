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
#include<ctime>
#define ll long long
#define LL long long
#define inf 10000.00
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

//poj2632
int mp[105][105];
char state[105];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int getdir(char c)
{
    if(c=='N')
        return 0;
    else if(c=='S')
        return 1;
    else if(c=='W')
        return 3;
    else return 2;
}
void changedir(char c,int s,int t)
{
    t=t%4;
    if(c=='L')
    {
        for(int i=0;i<t;i++)
            {
                switch(state[s])
                {
                case 'N':state[s]='W';break;
                case 'S':state[s]='E';break;
                case 'E':state[s]='N';break;
                case 'W':state[s]='S';break;
                }
            }
    }else {
       for(int i=0;i<t;i++)
            {
                switch(state[s])
                {
                case 'N':state[s]='E';break;
                case 'S':state[s]='W';break;
                case 'E':state[s]='S';break;
                case 'W':state[s]='N';break;
                }
            }
    }
}
int main()
{
    int K;
    scanf("%d",&K);
    while(K--)
    {
        int a,b;
        int output=0;
        scanf("%d %d",&a,&b);
        int n,m;
        scanf("%d %d",&n,&m);
        vector<pair<int,int> >vec;
        vec.push_back(make_pair(0,0));
        memset(mp,0,sizeof mp);
        memset(state,0,sizeof state);
        for(int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            mp[x][y]=i;
            vec.push_back(make_pair(x,y));
            scanf(" %c",&state[i]);
        }
        for(int i=0;i<m;i++)
        {
            char ord;
            int seq,number;
            scanf("%d %c %d",&seq,&ord,&number);
            if(output!=0)
                continue;
            if(ord=='L'||ord=='R')
            {
                changedir(ord,seq,number);
            }else if(ord=='F')
            {
                int dir=getdir(state[seq]);
                int x,y;
                x=vec[seq].first;
                y=vec[seq].second;
                mp[x][y]=0;
                for(int j=0;j<number;j++)
                {
                    x+=dx[dir];
                    y+=dy[dir];
                    if(x<=0||x>=a+1||y<=0||y>=b+1)
                    {
                        output=-1;
                        break;
                    }else if(mp[x][y]!=0)
                    {
                        output=mp[x][y];
                        break;
                    }
                }
                if(output==0)
                {
                    vec[seq]=make_pair(x,y);
                    mp[x][y]=seq;
                }
                else if(output==-1)
                {
                    printf("Robot %d crashes into the wall\n",seq);
                    continue;
                }else {
                    printf("Robot %d crashes into robot %d\n",seq,output);
                    continue;
                }
            }
        }
        if(output==0)
            printf("OK\n");
    }
    return 0;
}

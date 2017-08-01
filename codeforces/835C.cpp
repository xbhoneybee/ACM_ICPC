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
int n,q,c;
int numofstar[11][101][101];
int main()
{
    scanf("%d %d %d",&n,&q,&c);
    int x,y,s;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&x,&y,&s);
        numofstar[s][y][x]++;
    }
    for(y=1;y<=100;y++)
        for(x=1;x<=100;x++)
            for(s=0;s<=c;s++)
            {
                numofstar[s][y][x]=numofstar[s][y-1][x]+numofstar[s][y][x-1]-numofstar[s][y-1][x-1]+numofstar[s][y][x];
            }
    for(int iq=0;iq<q;iq++)
    {
        int lx,dy,rx,uy,t;
        scanf("%d %d %d %d %d",&t,&lx,&dy,&rx,&uy);
        int ans=0;
        for(s=0;s<=c;s++)
        {
            ans+=(s+t)%(c+1)*(numofstar[s][uy][rx]-numofstar[s][uy][lx-1]-numofstar[s][dy-1][rx]+numofstar[s][dy-1][lx-1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}

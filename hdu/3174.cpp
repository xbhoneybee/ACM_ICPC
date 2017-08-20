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

using namespace std;

const double PI=acos(-1.0);

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        double x=0,y=0;
        int ct=0;
        for(int i=0;i<n;i++)
        {
            char cmd[10];
            int dist;
            scanf("%s %d",cmd,&dist);
            if(cmd[0]=='f')
            {
                x=dist*cos(ct*PI/180.)+x;
                y=dist*sin(ct*PI/180.)+y;
            }else if(cmd[0]=='l'){
                ct=(ct+dist)%360;
            }else if(cmd[0]=='b')
            {
                x=-dist*cos(ct*PI/180.)+x;
                y=-dist*sin(ct*PI/180.)+y;
            }else ct=((ct-dist)%360+360)%360;
        }
        printf("%.0f\n",sqrt(x*x+y*y));
    }
    return 0;
}

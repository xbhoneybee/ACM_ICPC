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


// m$    sb精度问题 对于double 数能不存就不存，先算完乘法在除法
//最好用整数计算（LCM）
int mp[360][360];
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int xa,ya,xb,yb;
        cin>>xa>>ya>>xb>>yb;
        if(xa==xb)
        {
            for(int j=min(ya,yb);j<=max(ya,yb);j++)
                mp[xa][j]=i;
            continue;
        }
        if(ya==yb)
        {
            for(int j=min(xa,xb);j<=max(xa,xb);j++)
                mp[j][ya]=i;
            continue;
        }
        if(xa>xb)
        {
            swap(xa,xb);
            swap(ya,yb);
        }
        for(int xx=xa;xx<=xb;xx++)
        {
            double y=(ya-yb)*1.0*(xx-xa)/((xa-xb)*1.0)+ya;
            if(fabs(y-(int)(y))<1e-8)
                mp[xx][(int)y]=i;
        }
    }
    int q;
    cin>>q;
    for(int p=0;p<q;p++)
    {
        int x,y;
        cin>>x>>y;
        cout<<mp[x][y]<<endl;
    }
    return 0;
}

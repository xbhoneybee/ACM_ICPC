#include <bits/stdc++.h>
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
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x

using namespace std;
///G
int main()
{
    ll x0,y0,x1,y1,vx,vy,v;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld %lld %lld %lld %lld %lld",&x0,&y0,&x1,&y1,&vx,&vy,&v);
        ll coscta=vx*(x1-x0)+vy*(y1-y0);
        if(v*v>vx*vx+vy*vy)
            cout<<"YES"<<endl;
        else if(v*v==vx*vx+vy*vy)
        {
            if(coscta>0)
                cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }else {
        ll dx=x0-x1,dy=y0-y1;
        ll a=(vx*vx+vy*vy-v*v);
        ll b=2*(dx*vx+dy*vy);
        ll c=dx*dx+dy*dy;
        if(b*b-4*a*c>=0&&sqrt(b*b-4*a*c)>b)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        }
    }
    return 0;
}

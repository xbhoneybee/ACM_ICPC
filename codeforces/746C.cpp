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
#define ll long long
#define LL long long
#define inf 1000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

int len,st,ed;
int peo,car;
int ccpos,d;
int calcar(int goal)
{
    int needtime=0;
    if(d==1)
    {
        if(ccpos>goal)
        needtime+=(2*len-(ccpos-goal))*car;
        else needtime+=(goal-ccpos)*car;
    }else{
        needtime+=(ccpos+goal)*car;
    }
    return needtime;
}
int main()
{
    cin>>len>>st>>ed;
    cin>>car>>peo;
    cin>>ccpos>>d;
    int ans=inf;
    if(car>=peo)
    {
        ans=abs(st-ed)*peo;
        cout<<ans<<endl;

    }else{
    if(st>ed)
    {
        st=len-st;
        ed=len-ed;
        d= d==1?-1:1;
        ccpos= len-ccpos;
    }
    int cartime[1005];
    int peotime[1005];
    for(int i=st;i<ed;i++)
    {
        peotime[i]=(i-st)*peo;
        cartime[i]=calcar(i);
        while(cartime[i]<peotime[i])///只能人等车不能车等人
            cartime[i]+=2*len*car;
        ans=min(ans,(ed-i)*car+max(peotime[i],cartime[i]));
    }
    ans=min(ans,(ed-st)*peo);
    cout<<ans<<endl;
        }
    return 0;
}

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
#define ll long lo`ng
#define LL long long
#define inf 1000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;


int ashow[11];
int bshow[11];
int ashowans[11];
int bshowans[11];
int main()
{
    int n;
    cin>>n;
    string sa,sb;
    cin>>sa>>sb;
    for(int i=0;i<sa.size();i++)
        ashow[sa[i]-'0']++;
    for(int i=0;i<sb.size();i++)
        bshow[sb[i]-'0']++;
    int ans1=0,ans2=0;
    for(int i=0;i<=9;i++)
    {
        ashowans[i]=ashow[i];
        bshowans[i]=bshow[i];
    }
    ///
    for(int i=0;i<10;i++)
    {
        if(ashowans[i]<=bshowans[i])
        {
            bshowans[i]-=ashowans[i];
            ashowans[i]=0;
        }else {
            ashowans[i]-=bshowans[i];
            bshowans[i]=0;
        }
    }
    for(int ia=0;ia<=9;ia++)
        for(int ib=ia+1;ashowans[ia]!=0&&ib<=9;ib++)
    {
        if(bshowans[ib]!=0)
        {
            if(ashowans[ia]<=bshowans[ib])
            {
            bshowans[ib]-=ashowans[ia];
            ashowans[ia]=0;
            }else {
            ashowans[ia]-=bshowans[ib];
            bshowans[ib]=0;
            }
        }
    }
    for(int i=0;i<=9;i++)
        {
            ans1+=ashowans[i];
        }
    ///
    for(int i=0;i<=9;i++)
    {
        ashowans[i]=ashow[i];
        bshowans[i]=bshow[i];
    }
    for(int ib=1;ib<=9;ib++)
        for(int ia=0;bshowans[ib]!=0&&ia<ib;ia++)
    {
        if(ashowans[ia]<=bshowans[ib])
        {
            ans2+=ashowans[ia];
            bshowans[ib]-=ashowans[ia];
            ashowans[ia]=0;
        }else {
            ans2+=bshowans[ib];
            ashowans[ia]-=bshowans[ib];
            bshowans[ib]=0;
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}

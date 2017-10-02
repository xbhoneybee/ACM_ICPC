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
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);

using namespace std;


const int maxn=5e6+50;
long long t[maxn];
struct P
{
    long long val;
    int id;
};
int main()
{
    iosfalse
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        int n,a,b;
        scanf("%d %d %d",&n,&a,&b);
        P bigt,smt,cbigt,csmt,bigtt,smtt,cbigtt,csmtt;
        bigt.val=-1e9;bigtt.val=0;
        smt.val=1e9;smtt.val=1e18;
        cbigt.val=-1e9;cbigtt.val=0;
        csmt.val=1e9;csmtt.val=1e18;
        for(int i=0;i<n;i++)
        {
            scanf("%I64d",&t[i]);

            if(t[i]>cbigt.val)
            {
                cbigt.val=t[i];
                cbigt.id=i;
                if(cbigt.val>bigt.val)
                {
                    swap(cbigt,bigt);
                }
            }
            if(t[i]<csmt.val)
            {
                csmt.val=t[i];
                csmt.id=i;
                if(csmt.val<smt.val)
                {
                    swap(csmt,smt);
                }
            }
            if(t[i]*t[i]>=cbigtt.val)
            {
                cbigtt.val=t[i]*t[i];
                cbigtt.id=i;
                if(cbigtt.val>bigtt.val)
                {
                    swap(cbigtt,bigtt);
                }
            }
            if(t[i]*t[i]<=csmtt.val)
            {
                csmtt.val=t[i]*t[i];
                csmtt.id=i;
                if(csmtt.val<smtt.val)
                {
                    swap(csmtt,smtt);
                }
            }

        }
        long long ans;
        if(a>=0&&b>=0)
        {
            if(bigtt.id!=bigt.id)
            {
                ans=a*bigtt.val+b*bigt.val;
            }else {
                ans=max(a*bigtt.val+b*cbigt.val,a*cbigtt.val+b*bigt.val);
            }
            cout<<"Case #"<<cas++<<": "<<ans<<endl;
        }else if(a>=0)
        {
            if(bigtt.id!=smt.id)
            {
                ans=a*bigtt.val+b*smt.val;
            }else {
                ans=max(a*bigtt.val+b*csmt.val,a*cbigtt.val+b*smt.val);
            }
            cout<<"Case #"<<cas++<<": "<<ans<<endl;
        }else if(b>=0)
        {

            if(smtt.id!=bigt.id)
            {
                ans=a*smtt.val+b*bigt.val;
            }else {
                ans=max(a*smtt.val+b*cbigt.val,a*csmtt.val+b*bigt.val);
            }
            cout<<"Case #"<<cas++<<": "<<ans<<endl;
        }else {

        if(smtt.id!=smt.id)
            {
                ans=a*smtt.val+b*smt.val;
            }else {
                ans=max(a*csmtt.val+b*smt.val,a*smtt.val+b*csmt.val);
            }
        cout<<"Case #"<<cas++<<": "<<ans<<endl;
        }
    }
    return 0;
}

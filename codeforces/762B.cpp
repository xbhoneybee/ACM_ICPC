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
#define inf 100000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

//B 
int aval[300005],bval[300005];
int main ()
{
    int a,b,c;
    cin>>a>>b>>c;
    int m;
    cin>>m;
    int anum=0,bnum=0;
    for(int i=0;i<m;i++)
    {
        int val;
        string type;
        cin>>val>>type;
        if(type=="USB")
            aval[anum++]=val;
        else bval[bnum++]=val;
    }
    sort(aval,aval+anum);
    sort(bval,bval+bnum);
    ll ans=0,mon=0;
    if(a<=anum)
    {
        if(b<=bnum)
        {
            ans+=(a+b);
            for(int i=0;i<a;i++)
                mon+=aval[i];
            for(int i=0;i<b;i++)
                mon+=bval[i];
            int add=m-a-b,aseq=a,bseq=b;
            for(int id=0;id<min(add,c);id++)
            {
                if(aseq<anum&&bseq<bnum)
                {
                    if(aval[aseq]<bval[bseq])
                        mon+=aval[aseq++];
                    else mon+=bval[bseq++];
                }else if(aseq<anum)
                {
                    mon+=aval[aseq++];
                }else {
                    mon+=bval[bseq++];
                }
                ans++;
            }
        }
        else{
            ans+=(a+bnum);
            for(int i=0;i<a;i++)
                mon+=aval[i];
            for(int i=0;i<bnum;i++)
                mon+=bval[i];
            int add=anum-a,aseq=a;
            for(int id=0;id<min(add,c);id++)
            {
                mon+=aval[aseq++];
                ans++;
            }
        }
    }else
    {
        if(b<=bnum)
        {
            for(int i=0;i<anum;i++)
                mon+=aval[i];
            for(int i=0;i<b;i++)
                mon+=bval[i];
            ans+=anum+b;
            int add=bnum-b,bseq=b;
            for(int id=0;id<min(add,c);id++)
            {
                mon+=bval[bseq++];
                ans++;
            }
        }
        else {
            ans=anum+bnum;
            for(int i=0;i<anum;i++)
                mon+=aval[i];
            for(int i=0;i<bnum;i++)
                mon+=bval[i];
        }
    }
    cout<<ans<<" "<<mon<<endl;
    return 0;
}

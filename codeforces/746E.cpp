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
const int inf=1e9;
using namespace std;

///cf746E
int a[200005];
int ans[200005];
int main()
{
    int n,m;
    cin>>n>>m;
    long long useodd=1,useeven=2;
    int odd=0,even=0;
    set<int>ot,et,vis;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]&1)
            ot.insert(a[i]);
        else et.insert(a[i]);
    }
    odd=ot.size();
    even=et.size();
    if(ot.size()==n/2&&et.size()==n/2)
    {
        cout<<0<<endl;
        for(int i=0;i<n;i++)
            cout<<a[i]<<endl;
        return 0;
    }
    int chan=0,cur_o=0,cur_e=0,add_e=0,add_o=0;
    for(int i=0;i<n;i++)
    {
        if(vis.count(a[i]))
        {
            if(odd<n/2&&even<n/2)
            {
            if(add_e<n/2-even&&add_o<n/2-odd)
            {
                while(vis.count(useeven)||et.count(useeven))useeven+=2;
                while(vis.count(useodd)||ot.count(useodd)) useodd+=2;
                if(useeven<useodd){ans[i]=useeven;vis.insert(useeven);chan++;cur_e++;add_e++;}
                else {ans[i]=useodd;vis.insert(useodd);chan++;cur_o++;add_o++;}
            }
            else if(add_o<n/2-odd)
            {
                while(vis.count(useodd)||ot.count(useodd)) useodd+=2;
                ans[i]=useodd;vis.insert(useodd);chan++;cur_o++;add_o++;

            }else{
                while(vis.count(useeven)||et.count(useeven))useeven+=2;
                ans[i]=useeven;vis.insert(useeven);chan++;cur_e++;add_e++;
            }
            }else if(even<n/2)
            {
                while(vis.count(useeven)||et.count(useeven))useeven+=2;
                ans[i]=useeven;vis.insert(useeven);chan++;cur_e++;
            }else {
                while(vis.count(useodd)||ot.count(useodd)) useodd+=2;
                ans[i]=useodd;vis.insert(useodd);chan++;cur_o++;
            }
        }else{
        if(odd<n/2&&even<n/2)
        {
            ans[i]=a[i];
            vis.insert(a[i]);
            if(a[i]&1) {cur_o++;}
            else {cur_e++;}
        }else if(odd<n/2)
        {
            if(a[i]&1) {ans[i]=a[i];vis.insert(a[i]);cur_o++;}
            else if(cur_e>=n/2){cur_o++;while(vis.count(useodd)||ot.count(useodd)==1)useodd+=2;ans[i]=useodd;vis.insert(useodd);chan++;}
            else {cur_e++;ans[i]=a[i];vis.insert(a[i]);}
        }else
        {
            if(a[i]%2==0) {ans[i]=a[i];vis.insert(a[i]);cur_e++;}
            else if(cur_o>=n/2){cur_e++;while(vis.count(useeven)||et.count(useeven)==1)useeven+=2;ans[i]=useeven;vis.insert(useeven);chan++;}
            else{cur_o++;ans[i]=a[i];vis.insert(a[i]);}
        }
        }
    }
    if(m==1)
        useeven-=2;
    if(useeven<=m&&useodd<=m)
    {
        cout<<chan<<endl;
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }else cout<<-1<<endl;
    return 0;
}

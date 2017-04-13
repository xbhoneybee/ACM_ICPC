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
int main()
{
    ll b,q,l,m;
    set<ll>st;
    cin>>b>>q>>l>>m;
    for(int i=0;i<m;i++)
    {
        int t;
        cin>>t;
        st.insert(t);
    }
    if(llabs(b)>l)
    {
        cout<<0<<endl;
        return 0;
    }
    if(q==1)
    {
        if(st.count(b)==0&&llabs(b)<=l)
            cout<<"inf"<<endl;
        else
            cout<<0<<endl;
    }else if(q==-1)
    {
        if((st.count(b)&&st.count(-b))||(llabs(b)>l))
            cout<<0<<endl;
        else cout<<"inf"<<endl;
    }else if(q==0||b==0)
    {
        if(b==0)
        {
            if(st.count(b))
            cout<<0<<endl;
            else cout<<"inf"<<endl;
        }else {
            if(st.count(q)){
                if(st.count(b)||llabs(b)>l)
                 cout<<0<<endl;
                else cout<<1<<endl;
            }
            else if(llabs(b)<=l)
                cout<<"inf"<<endl;
            else cout<<0<<endl;
        }
    }
    else{
        if(llabs(b)<=l)
        st.insert(b);
        while(llabs(b*q)<=l)
        {
            b*=q;
            st.insert(b);
        }
        cout<<st.size()-m<<endl;
    }
    return 0;
}

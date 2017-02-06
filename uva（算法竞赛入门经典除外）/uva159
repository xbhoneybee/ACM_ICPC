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

//uva 159
int main()
{
    //freopen("output.txt","w",stdout);
    int flag=0;
    string s1a,s1b,s2a,s2b;
    while(cin>>s1a)
    {
        if(s1a=="#")
            break;
        else {
            if(flag)
                cout<<endl;
            else flag=1;
        }
        cin>>s1b>>s2a>>s2b;
        pair<int,int>p1,p2;
        p1=make_pair(-1,-1);
        p2=p1;
        for(int i=0;i<s1a.size();i++)
            for(int j=0;j<s1b.size();j++)
                if(s1a[i]==s1b[j])
        {
            p1=make_pair(i,j);
            goto th1;
        }
        th1:{}
        for(int i=0;i<s2a.size();i++)
            for(int j=0;j<s2b.size();j++)
                if(s2a[i]==s2b[j])
        {
            p2=make_pair(i,j);
            goto th2;
        }
        th2:{}
        if(p1.first==-1||p2.first==-1)
            cout<<"Unable to make two crosses"<<endl;
        else{
            int h=max(p1.second,p2.second);
            int ed=h+max(s1b.size()-p1.second,s2b.size()-p2.second);
            int down1=0,down2=0;
            for(int i=0;i<ed;i++)
            {
                if(i==h)
                    {
                        cout<<s1a<<"   "<<s2a<<endl;
                        down1++;down2++;
                    }
                else
                {
                cout<<string(p1.first,' ');
                if(i>=h-p1.second&&i<h+s1b.size()-p1.second)
                    {
                        cout<<s1b[down1++];
                        if(i>=h-p2.second&&i<h+s2b.size()-p2.second)
                        {
                        cout<<string(p2.first+s1a.size()-p1.first+2,' ');
                        cout<<s2b[down2++]<<endl;
                        }
                        else cout<<endl;
                    }
                else
                    {
                cout<<string(p2.first+s1a.size()-p1.first+3,' ');
                cout<<s2b[down2++]<<endl;
                    }
                }
            }
        }
    }
    return 0;
}

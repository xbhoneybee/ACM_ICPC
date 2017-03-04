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

string str;
bool isok(int a,int b,int c)
{
    if(str[a]!=str[b]&&str[b]!=str[c]&&str[a]!=str[c])
        return true;
    return false;
}
int main()
{
    int n;
    while(cin>>n)
    {
        cin>>str;
        bool imp=false;
        int maxe=0;
        vector<int>st[1001];
        for(int i=0;i<n-3;i++)
        {
            int a,b;
            cin>>a>>b;
            a--;b--;
            if(a>b)
                swap(a,b);
            st[a].push_back(b);
        }
        for(int i=0;i<n;i++)
        {
            sort(st[i].begin(),st[i].end());
        }
        for(int i=0;i<n;i++)
        {
            if(st[i].size()==0)
            continue;
            if(maxe==0)
                maxe=st[i][0];
            else if(i<maxe){
                if(st[i][st[i].size()-1]>maxe)
                {
                    imp=true;goto out;
                }
            }else{
                maxe=st[i][0];
            }
        }
        for(int i=0;i<n-1;i++)
            {
                for(int j=0;j<st[i].size();j++)
                {
                    if(st[i][j]>i)
                    st[st[i][j]].push_back(i);
                }
                st[i].push_back(i+1);
                sort(st[i].begin(),st[i].end());
            }
        st[n-1].push_back(0);
        sort(st[n-1].begin(),st[n-1].end());
        for(int i=0;i<n;i++)
        {
            int the=-1;
            for(int j=0;j<st[i].size();j++)
            {
                for(int k=0;k<st[i+1].size();k++)
                {
                    if(st[i][j]==st[i+1][k])
                    {
                    the=st[i][j];
                    goto th;
                    }
                }
            }
            th :
            if(the==-1)
                continue;
            bool tmp=isok(i,i+1,the);
            if(tmp==false)
            {
                imp=true;
                break;
            }
        }
    out :
    if(imp==true)
        cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    }
}

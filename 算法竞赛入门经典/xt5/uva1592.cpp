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
#define ll long long
#define LL long long
#define inf 1000000000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

//uva 1592
int main()
{
    //freopen("output.txt","w",stdout);
    int n,m;
    while(cin>>n>>m)
    {
        string dat[10001][11];
        string str;
        getline(cin,str);
        for(int i=0;i<n;i++)
        {
            getline(cin,str);
            int hori=0,pre=0,strlens=str.size();
            for(int j=0;j<strlens;j++)
            {
                if(str.at(j)==',')
                    {
                        dat[i][hori++]=str.substr(pre,j-pre);
                        pre=j+1;
                    }
            }
            dat[i][hori]=str.substr(pre,strlens-pre);
        }
        int r1=-1,r2=-1,c1=-1,c2=-1;
        for(int i=0;i<m;i++)
             for(int k=i+1;k<m;k++)
        {
            map<string,int>mp;
            for(int j=0;j<n;j++)
            {
                string ssr=dat[j][i]+","+dat[j][k];
                if(mp.count(ssr)==0)
                {
                    mp[ssr]=j;
                }else{
                    r2=j+1;r1=mp[ssr]+1;
                    c1=i+1;c2=k+1;
                    cout<<"NO"<<endl;
                    cout<<r1<<" "<<r2<<endl;
                    cout<<c1<<" "<<c2<<endl;
                    goto there;
                }
            }
        }
        cout<<"YES"<<endl;
        there:{}
    }
    return 0;
}
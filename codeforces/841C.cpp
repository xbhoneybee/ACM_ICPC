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

using namespace std;
int n;
int a[200005];
int b[200005];
int main()
{
    iosfalse
    cin>>n;
    vector<int>vec;
    for(int i=1;i<=n;i++)
        {
            int t;
            cin>>t;
            vec.push_back(t);
        }
    map<int,vector<int> >mp;
    for(int i=1;i<=n;i++)
        {
            cin>>b[i];
            mp[b[i]].push_back(i);
        }
    sort(vec.begin(),vec.end());
    map<int,vector<int> >::iterator ip;
    int  pos=n-1;
    for(ip=mp.begin();ip!=mp.end();ip++)
    {
        vector<int>v =(ip->second);
        for(int j=0;j<v.size();j++)
        {
            a[v[j]]=vec[pos];
            pos--;
        }
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}

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

//jsk603
//D
//分块预处理 或者 小数据打表存
//可以分析复杂度，发现主要是询问串长度较小时耗时较大
int n,m;
int s[50004];
int t[50004];
long long Hash[50004];
vector<long long>vec[15];
int main()
{
    iosfalse
    cin>>n;
    for(int i=0;i<=n;i++)
        Hash[i]=rand()*rand()*rand();
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(int len=1;len<10;len++)
    {
        int L=0,R=L+len;
        long long val=0;
        for(int j=L;j<R;j++)
            val+=Hash[s[j]];
        while(R<=n)
        {
            vec[len].push_back(val);
            val-=Hash[s[L]];
            val+=Hash[s[R]];
            L++;R++;
        }
        sort(vec[len].begin(),vec[len].end());
    }
    cin>>m;
    for(int it=0;it<m;it++)
    {
        int k;
        cin>>k;
        long long hsgoal=0,hsstore=0;
        for(int i=0;i<k;i++)
        {
            cin>>t[i];
            if(k<=n)
            hsgoal+=Hash[t[i]];
        }
        if(k>n)
        {
            cout<<0<<endl;
            continue;
        }
        if(k>9)
        {

        int L=0,R=k,ans=0;
        for(int i=L;i<R;i++)
        {
            hsstore+=Hash[s[i]];
        }
        while(L<n&&R<=n)
        {
            if(hsgoal==hsstore)
                ans++;
            hsstore-=Hash[s[L]];
            hsstore+=Hash[s[R]];
            L++;R++;
        }
        cout<<ans<<endl;

        }else {
            int ans= upper_bound(vec[k].begin(),vec[k].end(),hsgoal)-lower_bound(vec[k].begin(),vec[k].end(),hsgoal);
            cout<<ans<<endl;
        }
    }
    return 0;
}

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

///注意num1=0 或 1 a11 都是0 ,加3个特判处理

int main()
{
    long long a01,a10,a00,a11;
    cin>>a00>>a01>>a10>>a11;
    map<int,int>mp;
    for(int k=0,i=1;k<1e9;k+=i,i++)///找到所有满足条件的数
        mp[k]=i;
    if(a00==0&&a01==0&&a10==0&&a11==0)
        cout<<0<<endl;
    else if(a00==0&&a01==0&&a10==0)
    {
        if(mp.count(a11))
            cout<<string(mp[a11],'1');
        else cout<<"Impossible"<<endl;
    }else if(a01==0&&a10==0&&a11==0)
    {
        if(mp.count(a00))
            cout<<string(mp[a00],'0');
        else cout<<"Impossible"<<endl;
    }else{
        if(mp.count(a00)==0||mp.count(a11)==0||a01+a10!=mp[a00]*mp[a11])
            cout<<"Impossible"<<endl;
        else{
            int num1=mp[a11],num0=mp[a00];
            int left=num1-a01/num0,right=a01/num0,mid=a01%num0;
            string ans="";
            if(mid==0)
                ans=string(left,'1')+string(num0,'0')+string(right,'1');
            else ans=string(left-1,'1')+string(mid,'0')+'1'+string(num0-mid,'0')+string(right,'1');
            cout<<ans<<endl;
        }
    }
    return 0;
}

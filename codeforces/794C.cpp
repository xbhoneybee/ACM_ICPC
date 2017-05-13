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

//D
//C

char ans[300005];
int main()
{
    string a,b;
    cin>>a>>b;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    int cnta=0,cntb=0,cnt=0;
    int eda=a.size()/2,edb=a.size()/2-1,ed=a.size()-1;
    if(a.size()%2==0)
        eda--;
    for(int i=0;i<a.size();i++)
    {
        if(i&1)
        {
            if(a[cnta]<b[cntb])
            ans[cnt++]=b[cntb++];
            else{
                ans[ed--]=b[edb--];
            }
        }else{
            if(a[cnta]<b[cntb])
            ans[cnt++]=a[cnta++];
            else{
                ans[ed--]=a[eda--];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

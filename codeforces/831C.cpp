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

int n,k;
int a[2005],pre[2005],b[2005];
int main()
{
    iosfalse
    cin>>k>>n;
    multiset<int>stpre;
    for(int i=1;i<=k;i++)
        {
            cin>>a[i];
            pre[i]=pre[i-1]+a[i];
            stpre.insert(pre[i]);
        }
    for(int i=1;i<=n;i++)
        cin>>b[i];
    sort(b+1,b+1+n);
    sort(pre+1,pre+1+k);
    set<int>st;
    for(int ik=1;ik<=k;ik++)
    {
        int x=b[1]-pre[ik];
        if(n==1)
            st.insert(x);
        multiset<int>stpre1=stpre;
        for(int in=2;in<=n;in++)
        {
            if(stpre1.count(b[in]-x))
            {
                stpre1.erase(b[in]-x);
            }else break;
            if(in==n)
                st.insert(x);
        }
    }
    cout<<st.size()<<endl;
    return 0;
}

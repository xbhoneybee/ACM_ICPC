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
#define ll long lo`ng
#define LL long long
#define inf 1000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

struct Ri
{
int a,b,h;
}ri[100005];
int cmp(Ri a,Ri b)
{
    if(a.b!=b.b)
        return a.b>b.b;
    else if(a.a!=b.a)
        return a.a>b.a;
    return a.h>b.h; ///a.h<b.h wa24  why?
}
stack<Ri>st;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>ri[i].a>>ri[i].b>>ri[i].h;
    sort(ri,ri+n,cmp);
    long long  ans=0,sum=0;
    for(int i=0;i<n;i++)
    {
        while(1)
        {
            if(st.empty())
                break;
            if(ri[i].b>st.top().a)
                break;
            sum-=st.top().h;
            st.pop();
        }
        st.push(ri[i]);
        sum+=ri[i].h;
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}

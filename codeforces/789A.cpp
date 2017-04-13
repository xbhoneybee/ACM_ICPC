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
int a[100005];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=0)
            continue;
        ans+=a[i]/(2*k);
        a[i]%=(2*k);
        if(a[i]<=0)
            continue;
        if(a[i]>k)
            ;
        else if(i+1<n)
            a[i+1]-=k;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}

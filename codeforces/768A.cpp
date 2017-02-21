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
#define ll long long
#define LL long long
#define inf 10000000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[100005]={0};
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int ans=0;
      for(int i=1;i<n-1;i++)
    {
        if(a[i]>a[0]&&a[i]<a[n-1])
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}

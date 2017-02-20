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
    int a[105];
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        ans^=a[i];
    }
    if(ans==0)
        cout<<"Bob"<<endl;
    else cout<<"Alice"<<endl;
    return 0;
}

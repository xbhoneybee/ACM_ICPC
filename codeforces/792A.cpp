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

long long  a[200005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    long long mind=1e18;
    int num=0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i+1]-a[i]<mind)
        {
            mind=a[i+1]-a[i];
            num=1;
        }else if(a[i+1]-a[i]==mind)
            num++;
    }
    cout<<mind<<" "<<num<<endl;
    return 0;
}

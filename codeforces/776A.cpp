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
#define inf 1000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    int n;
    cin>>n;
    cout<<a<<" "<<b<<endl;
    for(int i=0;i<n;i++)
    {
        string ta,tb;
        cin>>ta>>tb;
        if(ta==a)
            a=tb;
        else b=tb;
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}

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
   int n,b,d,ans=0,add=0;
   cin>>n>>b>>d;
   for(int i=0;i<n;i++)
   {
       int atmp;
       cin>>atmp;
       if(atmp<=b)
       {
           add+=atmp;
           if(add>d)
           {
               ans++;
               add=0;
           }
       }
   }
   cout<<ans<<endl;
    return 0;
}
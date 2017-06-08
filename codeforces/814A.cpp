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
int a[400];
int b[400];
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<k;i++)
        cin>>b[i];
    if(k==1)
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
                a[i]=b[0];
        }
        bool inc=true;
        for(int i=0;i+1<n;i++)
        {
            if(a[i]>a[i+1])
            {
                inc=false;
                break;
            }
        }
        if(inc)
            cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    else cout<<"Yes"<<endl;
    return 0;
}

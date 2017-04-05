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


int a[200];
int del[200];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++)
        cin>>a[i];
    int cur=1;
    int num=n;
    for(int i=0;i<k;i++)
    {
        a[i]%=num;
        for(int j=0;j<a[i];)
        {
            cur=(cur+1)%(n+1);
            if(cur==0)cur=1;
            if(del[cur]==0)
                j++;
        }
        cout<<cur<<" ";
        del[cur]=1;
        cur=(cur+1)%(n+1);
        if(cur==0)cur=1;
        while(del[cur]==1)
        {
            cur=(cur+1)%(n+1);
            if(cur==0)cur=1;
        }
        num--;
    }
    cout<<endl;
    return 0;
}

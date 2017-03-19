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


//C
string name[70];
int ans[70];
int pd[70];
int main()
{
    for(int i=0;i<70;i++)
        {
            string n="A";
            n+=char(i/26/26+'a');
            n+=char(i/26+'a');
            n+=char(i%26+'a');
            name[i]=n;
        }
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n-k+1;i++)
    {
        string ppx;
        cin>>ppx;
        if(ppx=="NO")
            pd[i]=0;
        else pd[i]=1;
    }
    for(int i=0;i<n;i++)
        ans[i]=i;
    for(int i=0;i<n-k+1;i++)
        if(pd[i]==0)
            ans[i+k-1]=ans[i];
    for(int i=0;i<n;i++)
        cout<<name[ans[i]]<<" ";
    cout<<endl;
    return 0;
}

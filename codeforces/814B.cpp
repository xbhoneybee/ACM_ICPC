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


//B
int n;
int a[1005];
int b[1005];
int ans[1005];
bool vis[1005];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    int pos1=-1,pos2=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            if(pos1==-1)
                pos1=i;
            else pos2=i;
        }
        else ans[i]=a[i];
    }
    for(int i=0;i<n;i++)
        {
            vis[ans[i]]=true;
        }
    if(pos2==-1)
    {
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==false)
            {
                ans[pos1]=i;
                break;
            }
        }
    }
    else {
        int num1=-1,num2=-1;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==false)
            {
                if(num1==-1)
                    num1=i;
                else num2=i;
            }
        }
        ans[pos1]=num1;
        ans[pos2]=num2;
        int dif1=0,dif2=0;
        for(int i=0;i<n;i++)
        {
            if(ans[i]!=a[i])
                dif1++;
            if(ans[i]!=b[i])
                dif2++;
        }
        if(dif1>1||dif2>1)
        {
            ans[pos1]=num2;
            ans[pos2]=num1;
        }
    }
    for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    return 0;
}

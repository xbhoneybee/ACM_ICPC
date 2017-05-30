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
//codeforces 416div2

//二维的区间dp
int a[5005];
int d[5001]; //1-i max
int n;
bool dif[5001];
vector<int>vec[50005];
int main()
{
    iosfalse
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        vec[a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        d[i]=d[i-1];
        int ans=0;//j--i ^value
        int st=i;
        memset(dif,false,sizeof dif);
        for(int j=i;j>0;j--)
        {
            if(vec[a[j]][vec[a[j]].size()-1]>i)
                break;
            st=min(st,vec[a[j]][0]);
            if(dif[a[j]]==false)
            {
                dif[a[j]]=true;
                ans^=a[j];
            }
            if(j<=st)
            d[i]=max(d[i],d[j-1]+ans);
        }
    }
    cout<<d[n]<<endl;
    return 0;
}

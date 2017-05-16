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

//uva

int n,T;
int boss[100005];
vector<int> son[100005];
int dp(int f)
{
    if(son[f].size()==0)
        return 1;
    int k=son[f].size();
    int need=(k*T-1)/100+1;
    vector<int> d;
    for(int i=0;i<k;i++)
        d.push_back(dp(son[f][i]));
    sort(d.begin(),d.end());
    int ans=0;
    for(int i=0;i<need;i++)
        ans+=d[i];
    return ans;
}
int main()
{
    iosfalse
    while(cin>>n>>T)
    {
        if(n==0)
            break;
        for(int i=1;i<=n;i++)
            {
                cin>>boss[i];
                son[boss[i]].push_back(i);
            }
        cout<<dp(0)<<endl;
        for(int i=0;i<=n;i++)
            son[i].clear();
    }
    return 0;
}

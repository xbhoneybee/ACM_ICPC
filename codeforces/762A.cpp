#include <bits/stdc++.h>
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
#define inf 100000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

int main()
{
    //freopen("output.txt","w",stdout);
    long long m,k;
    cin>>m>>k;
    vector <long long> div;
    for(long long i=1;i<=sqrt(m)+0.5;i++)
    {
    if(m%i==0)
       {
        div.push_back(i);
        if(m/i!=i)
            div.push_back(m/i);
       }
    }
    sort(div.begin(),div.end());
    if(div.size()<k)
        cout<<-1<<endl;
    else cout<<div[k-1]<<endl;
    return 0;
}

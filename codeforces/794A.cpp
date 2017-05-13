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
//A
int a,b,c;
int mon[100005];
int main()
{
    cin>>a>>b>>c;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>mon[i];
    sort(mon+1,mon+1+n);
    int ans=lower_bound(mon+1,mon+1+n,c)-upper_bound(mon+1,mon+1+n,b);
    cout<<ans<<endl;
    return 0;
}

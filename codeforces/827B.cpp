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

//构造选一个点为中心，其他点绕他以k分支展开
void dis(int n,int k)
{
    int ans=(n-1)/k*2;
    if((n-1)%k!=0)
    {
        if((n-1)%k==1)
            ans++;
        else ans+=2;
    }
    cout<<ans<<endl;
    for(int i=1;i<n;i++)
    {
        if(i-k<=0)
            cout<<n<<" "<<i<<endl;
        else cout<<i<<" "<<i-k<<endl;
    }
}
int main()
{
    int n,k;
    cin>>n>>k;
    dis(n,k);
    return 0;
}

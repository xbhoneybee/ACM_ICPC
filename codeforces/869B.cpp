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
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);

using namespace std;


//B

int main()
{
    ll a,b;
    cin>>a>>b;
    //b--a+1;  ans=1; ans*=i;
    long long ans=1;
    for(ll st=a+1;st<=b;st++)
    {
        ans=ans*(st%10)%10;
        if(ans==0)
            break;
    }
    cout<<ans<<endl;
    return 0;
}

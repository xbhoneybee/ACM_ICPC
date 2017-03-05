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
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x

using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll L,F,D,st;
        cin>>L>>F>>D;
        if(F<=D&&D<=L||(F<=L&&L<=D))
        {
            if(__gcd(L,D)>=F)
                cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }else cout<<"NO"<<endl;
    }
    return 0;
}

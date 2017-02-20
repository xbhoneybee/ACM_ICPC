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
#define ll long long
#define LL long long
#define inf 10000000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int id=0;id<t;id++)
    {
        int n;
        long long a[105];
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ll tmp,ta=a[i];
            if(ta&1)
            {
                while(ta&1)
                {
                    ta/=2;
                }
                tmp=ta/2;
            }else {
                tmp=ta/2;
            }
            ans^=tmp;
        }
        if(ans==0)
            cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
/*
 *n%2==0 SG[n]=n/2;
 *n%2==1 SG[n]=SG[n/2];
 */

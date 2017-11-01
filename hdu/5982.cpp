#include<bits/stdc++.h>
#include <iostream>
#define iosfalse ios::sync_with_stdio(false);
using namespace std;


int main()
{
    iosfalse
    int T;
    cin>>T;
    while(T--)
    {
        int n,ans=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            ans+=a*b;
        }
        cout<<ans<<endl;
    }
    return 0;
}

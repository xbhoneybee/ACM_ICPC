#include<bits/stdc++.h>
using namespace std;
//CF3.9

//A

int main()
{
    int l,r,a;
    cin>>l>>r>>a;
    int ans=min(l,r)*2;
    if(a>max(l,r)-min(l,r)){
        ans=max(l,r)*2;
        ans+=(a-(max(l,r)-min(l,r)))/2*2;
    }else ans+=a*2;
    cout<<ans<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
//CF3.9

//B

vector<int>va,vb;
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        va.push_back(x);
    }
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        vb.push_back(x);
    }
    long long suma=0,sumb=0;
    int posa=0,posb=0,ans=0;
    while(posa<n|| posb<m)
    {
        if(suma==0&&posa<n)
            suma+=va[posa++];
        if(sumb==0&&posb<m)
            sumb+=vb[posb++];
        if(suma<sumb){
            suma+=va[posa++];
        }else if(suma>sumb){
            sumb+=vb[posb++];
        }else {
            ans++;
            suma=0;sumb=0;
        }
    }
    if(suma==sumb&&suma!=0)
    {
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}

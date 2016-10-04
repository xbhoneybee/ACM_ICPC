#include <iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#include<cstring>
#include<set>
#include<queue>
#include<cctype>
#include<map>
#include<stack>
#include<cstdlib>
#include<sstream>
#include<deque>
#include<list>
#define ll long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;
int vis[10004];
int main()
{
    int t;
    cin>>t;
    for(int it=1;it<=t;it++)
    {
        int n,k;
        cin>>n>>k;
        memset(vis,0,sizeof vis);
        if(n==1)
        {
            cout<<"Case #"<<it<<": "<<1<<endl;
            continue;
        }
        if(k%2==0){
        cout<<"Case #"<<it<<": ";
        cout<<k<<" "<<2*k;
        vis[k]=1;vis[2*k]=1;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
                cout<<" "<<i;
        }
        cout<<endl;
        }else{
         cout<<"Case #"<<it<<": ";
         cout<<2*k<<" "<<k;
        vis[k]=1;vis[2*k]=1;
        for(int i=k+1;i<=n;i++)
        {
            if(vis[i]==0)
                cout<<" "<<i;
        }
        for(int i=1;i<=k-1;i++)
        {
            if(vis[i]==0)
                cout<<" "<<i;
        }
        cout<<endl;
        }
    }
    return 0;
}

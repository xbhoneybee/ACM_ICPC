#include <bits/stdc++.h>
#include<sstream>
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);

using namespace std;

//B 大坑

int a[100005];
int premin[100005];
int sufmin[100005];
int main()
{
    int n,k;
    int mina=1e9+10,maxa=-1e9-10;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        a[i]=t;
        mina=min(mina,t);
        maxa=max(maxa,t);
    }
    if(k==1)
        cout<<mina<<endl;
    else if(k>=3)
        cout<<maxa<<endl;
    else {
        premin[0]=a[0];
        for(int i=1;i<n;i++)
        {
            premin[i]=min(premin[i-1],a[i]);
        }
        sufmin[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            sufmin[i]=min(sufmin[i+1],a[i]);
        }
        int ans=-1e9-10;
        for(int i=0;i<n-1;i++)
        {
            ans=max(ans,max(sufmin[i+1],premin[i]));
        }
        cout<<ans<<endl;
    }
    return 0;
}

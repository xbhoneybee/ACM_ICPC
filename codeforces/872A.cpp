#include <bits/stdc++.h>
#include<sstream>
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);

using namespace std;

//A

int n,m;
int a[100];
int b[100];
bool vis[100];
int main()
{
    memset(vis,false,sizeof vis);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        {
            cin>>a[i];
            vis[a[i]]=true;
        }
    int found=100;
    for(int i=0;i<m;i++)
        {
            cin>>b[i];
            if(vis[b[i]]==true)
                {
                    found=min(found,b[i]);
                }
        }
    if(found==100)
    {
    sort(a,a+n);
    sort(b,b+m);
    cout<<(min(a[0],b[0])*10+max(a[0],b[0]))<<endl;
    }else {
    cout<<found<<endl;
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <math.h>
#include <string.h>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#define inf 1000000000
#define ll long long
#define mod 1000000007//  这里不要写成100000000+7 define是替换！！！
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

//two points 写错了 看看别人的代码多简洁
int a[200005];
int main()
{
    iosfalse
    int t,n,m,k;
    ll ans=0;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        int num=0;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int i=1,j=0;
        while(j<n)
        {
            while(j<n&&num<k)
            {
                j++;
                if(a[j]>=m) num++;
            }
            if(j==n&&num<k) break;
            if(num==k) ans+=n-j+1;
            while(num==k)
            {
                if(a[i]>=m) num--;
                i++;
                if(num==k) ans+=n-j+1;
            }
        }
        cout<<ans<<endl;
        ans=0;
        memset(a,0,sizeof a);
    }
    return 0;
}
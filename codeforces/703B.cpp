#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<stdlib.h>
#include <sstream>
#include <deque>
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e18
#define lowbit(x) x&-x
using namespace std;

//简单的乘法分配率   我好菜啊！
int c[100005];
int id[100005];
int iscap[100005];
int main()
{
    int n,k;
    ll sum=0,ans=0,sumcap=0,minusans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        {
            cin>>c[i];
            sum+=c[i];
        }
        c[0]=c[n];
    for(int i=1;i<=k;i++)
        {
            cin>>id[i];
            iscap[id[i]]=1;
            sumcap+=c[id[i]];
        }
        if(id[k]==n) iscap[0]=1;
    for(int i=1;i<=k;i++)
    {
        ans+=c[id[i]]*(sum-c[id[i]]);
        minusans+=c[id[i]]*(sumcap-c[id[i]]);
    }
    ans-=(minusans/2);
    for(int i=0;i<=n;i++)
    {
        if(iscap[i-1]==0&&iscap[i]==0)
            ans+=c[i-1]*c[i];
    }
    cout<<ans<<endl;
    return 0;
}

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string.h>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include <sstream>
#define mod 1000000007
#define ll long long
#define LL long long
#define inf 100000000
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

//8.21  cf


int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m)&&n&&m)
    {   vector<int> vec[57];
        int nn=n*n;
        ll xxx[60]={0};
        int maxx=-inf,minn=inf;
        int t1,t2;
        for(int i=1;i<=nn;i++)
        {
            scanf("%d %d",&t1,&t2);
            vec[t1].push_back(t2);
            maxx=max(maxx,t2);
            minn=min(minn,t2);
        }
        //cout<<maxx<<' '<<minn<<endl;
        for(int i=1;i<=n;i++)
      {
            sort(vec[i].begin(),vec[i].end());
        //cout<<xxx[i]<<endl;
      }
        if(maxx+n>m+1) maxx=m-n+1;
        ll ans=inf,temp=0;
        for(int i=minn;i<=maxx;i++)
        {   temp=0;
            for(int j=1;j<=n;j++)
            {
               for(int k=0;k<n;k++)
               {
                   temp+=abs(vec[j][k]-(i+k));
               }
            }
            ans=min(ans,temp);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

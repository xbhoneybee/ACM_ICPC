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
#include <deque> //双端队列
#define mod 1000000007
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e18
#define lowbit(x) x&-x
using namespace std;

int w[2005],val[2005];
int f[2005];
int main()
{
    iosfalse
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>m>>n;
        for(int i=0;i<n*2;i+=2)
            {
                int a,b;
                cin>>w[i]>>a>>b;
                w[i+1]=w[i];val[i]=a+b;val[i+1]=a;
            }
        for(int i=0;i<=m;i++)
            f[i]=0;
        for(int i=0;i<2*n;i++)
        {
            if(i&1){
            for(int j=w[i];j<=m;j++)
                f[j]=max(f[j],f[j-w[i]]+val[i]);
            }
            else{
                for(int j=m;j>=w[i];j--)
                f[j]=max(f[j],f[j-w[i]]+val[i]);
            }
        }
        int ans=f[m];
        cout<<ans<<endl;
    }

    return 0;
}

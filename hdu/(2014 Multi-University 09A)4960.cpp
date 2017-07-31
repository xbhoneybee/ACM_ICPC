//#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<vector>
#include<map>
#include<sstream>
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x

using namespace std;

int n,w[5005],cost[5005];
int J[5005];
int dp[5005];
int main()
{
    iosfalse
    while(cin>>n)
    {
        if(n==0)
            break;
        for(int i=1;i<=n;i++)
            cin>>w[i];
        for(int i=1;i<=n;i++)
            {
                cin>>cost[i];
                dp[i]=1e9;
            }
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }else if(n==2)
        {
            if(w[2]==w[1])
                cout<<0<<endl;
            else cout<<cost[2]<<endl;
            continue;
        }
        int L=1,R=n;
        ll sumL=w[L],sumR=w[R];
        memset(J,0,sizeof J);
        while(L<R)
        {
            if(sumL==sumR)
            {
                J[L]=R;
                ++L;--R;
                sumL+=w[L];
                sumR+=w[R];
            }else if(sumL<sumR)
                sumL+=w[++L];
            else sumR+=w[--R];
        }
        J[0]=n+1;
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            if(J[i]==0)
                continue;
            for(int j=0;j<i;j++)
            {
                if(J[j]==0)
                    continue;
                dp[i]=min(dp[j]+cost[i-j]+cost[J[j]-J[i]],dp[i]);
            }
        }
        int ans=1e9;
        for(int i=0;i<=n;i++)
        {
            if(J[i]==0)
                continue;
            ans=min(ans,dp[i]+cost[J[i]-i-1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}

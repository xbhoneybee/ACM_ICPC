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

const  int INF =1e9;
int dp[255][60];
int T,n;
int t[60];
int M1,M2;
int d[60],e[60];
bool has_train[255][60][2];
int main()
{
    iosfalse
    int cas=1;
    while(cin>>n>>T)
    {
        if(n==0)
            break;
        for(int i=1;i<n;i++)
            cin>>t[i];
        cin>>M1;
        for(int i=1;i<=M1;i++)
            cin>>d[i];
        cin>>M2;
        for(int i=1;i<=M2;i++)
            cin>>e[i];
        memset(has_train,false,sizeof has_train);
        memset(dp,0,sizeof dp);
        for(int i=1;i<=M1;i++)
        {
            int tmp=d[i];
            int cnt=1;
            while(tmp<=T&&cnt<=n){
            has_train[tmp][cnt][0]=true;
            tmp+=t[cnt++];
            }
        }
        for(int i=1;i<=M2;i++)
        {
            int tmp=e[i];
            int cnt=n;
            while(tmp<T&&cnt>1){
            has_train[tmp][cnt][1]=true;
            tmp+=t[--cnt];
            }
        }

        dp[T][n]=0;
        for(int i=1;i<n;i++)
            dp[T][i]=1e9;

        for(int i=T-1;i>=0;i--)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=1+dp[i+1][j];
                if(j<n&&has_train[i][j][0]==true&&t[j]<=T-i)
                    dp[i][j]=min(dp[i+t[j]][j+1],dp[i][j]);
                if(j>1&&has_train[i][j][1]==true&&t[j-1]<=T-i)
                    dp[i][j]=min(dp[i+t[j-1]][j-1],dp[i][j]);
            }
        }
        cout<<"Case Number "<<cas++<<": ";
        if(dp[0][1]>=T)
            cout<<"impossible"<<endl;
        else cout<<dp[0][1]<<endl;
    }
    return 0;
}

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

int dp[12][110];
int mp[12][110];
int n,m,cnt;
void print_ans(int val,int row)
{
    int dd[3];
    if(row>0&&row<m-1){
        dd[0]=-1;dd[1]=0;dd[2]=1;
    }else if(row==0)
    {
        dd[0]=0;dd[1]=1;dd[2]=-1;
    }else{
        dd[0]=1;dd[1]=-1;dd[2]=0;
    }
    for(int i=0;i<3;i++)
    {
        if(dp[(row+dd[i]+m)%m][cnt]==val)
        {
            if(cnt<n-1)
            cout<<(row+dd[i]+m)%m+1<<" ";
            else cout<<(row+dd[i]+m)%m+1<<endl;
            val-=mp[(row+dd[i]+m)%m][cnt];
            cnt++;
            if(cnt==n)
                return ;
            print_ans(val,(row+dd[i]+m)%m);
            return ;
        }
    }
}
int main()
{
    iosfalse
    while(cin>>m>>n)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                {
                    cin>>mp[i][j];
                    dp[i][j]=1e9;
                }
        }
        cnt=0;
        for(int i=0;i<m;i++)
            dp[i][n-1]=mp[i][n-1];
        for(int j=n-2;j>=0;j--)
        {
            for(int i=0;i<m;i++)
            {
                dp[i][j]=min(dp[i][j],mp[i][j]+dp[(i-1+m)%m][j+1]);
                dp[i][j]=min(dp[i][j],mp[i][j]+dp[i][j+1]);
                dp[i][j]=min(dp[i][j],mp[i][j]+dp[(i+1)%m][j+1]);
            }
        }

        int ans=1e9;
        int row;
        for(int i=0;i<m;i++)
        {
            if(dp[i][0]<ans)
            {
                ans=dp[i][0];
                row=i;
            }
        }
        print_ans(ans,row);
        cout<<ans<<endl;
    }
    return 0;
}

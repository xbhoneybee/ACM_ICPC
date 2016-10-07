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
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

int mp[40][40];
int main()
{
    int t;
    cin>>t;
    for(int it=1;it<=t;it++)
    {
        int n,m;
        int flag=0;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cin>>mp[i][j];
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(mp[i][0]==mp[j][0])
                {
                    flag=1;
                    goto there;
                }
                if(mp[i][m-1]==mp[j][m-1])
                {
                    flag=1;
                    goto there;
                }
            }
        }
        for(int i=0;i<m;i++)
            for(int j=i+1;j<m;j++)
            {
                if(mp[0][i]==mp[0][j])
                {
                    flag=1;
                    goto there;
                }
                if(mp[n-1][i]==mp[n-1][j])
                {
                    flag=1;
                    goto there;
                }
            }
         for(int i=1;i<n-1;i++)
            for(int j=1;j<m-1;j++)
            {
                if(mp[i][j]==mp[i+1][j]||mp[i-1][j]==mp[i][j]||mp[i][j]==mp[i][j-1]||mp[i][j]==mp[i][j+1])
                {
                    flag=1;
                    goto there;
                }
            }


        there:
        if(flag==1)
        cout<<"Case #"<<it<<": Yes"<<endl;
        else cout<<"Case #"<<it<<": No"<<endl;
    }
    return 0;
}
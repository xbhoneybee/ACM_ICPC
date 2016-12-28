#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<cstdlib>
#include <sstream>
#include <deque>
#include<list>
#include<ctime>
#define ll long long
#define LL long long
#define inf 10000.00
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

//poj1068
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int p[30]={0};
        string par="";
        for(int i=0;i<n;i++)
            {
                par+="(";
                cin>>p[i];
            }
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<par.size();j++)
            {
                if(par.at(j)=='(')
                    cnt++;
                if(cnt==p[i])
                    {
                        par=par.substr(0,j+1)+")"+par.substr(j+1,par.size());
                        break;
                    }
            }
        }
        int use[50]={0};
        int w[30]={0};
        int ww=0;
        for(int i=0;i<par.size();i++)
        {
            if(par.at(i)==')')
            {
                for(int j=i-1,left=1;j>=0;j--)
                    if(par[j]=='('&&use[j]==0)
                        {
                            w[ww++]=left;
                            use[j]=1;
                            break;
                        }
                    else if(par[j]=='(')
                            left++;
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<w[i];
            if(i<n-1)cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}

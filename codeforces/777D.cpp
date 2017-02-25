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
#define ll long long
#define LL long long
#define inf 1000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

string str[500005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>str[i];
    for(int i=n-1;i>0;i--)
    {
        int len=min(str[i].size(),str[i-1].size());
        int st=0;//equal
        for(int j=1;j<len;j++)
        {
            if(str[i][j]<str[i-1][j])
                {
                    str[i-1]=str[i-1].substr(0,j);
                    st=1;
                    break;
                }
            else if(str[i][j]>str[i-1][j])
            {
                st=1;
                break;
            }
        }
        if(st==0&&str[i-1].size()>str[i].size())
            str[i-1]=str[i-1].substr(0,str[i].size());
    }
    for(int i=0;i<n;i++)
        cout<<str[i]<<endl;

    return 0;
}

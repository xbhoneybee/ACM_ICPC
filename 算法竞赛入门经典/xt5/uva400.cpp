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
#define ll long long
#define LL long long
#define inf 1000000000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

//uva  400
int main()
{
    //freopen("output.txt","w",stdout);
    int n;
    string gap(60,'-');
    while(cin>>n)
    {
        cout<<gap<<endl;
        string str;
        int len=0;
        vector<string>vec;
        for(int i=0;i<n;i++)
        {
            cin>>str;
            vec.push_back(str);
            len=max((int)str.size(),len);
        }
        sort(vec.begin(),vec.end());
        int rc=62/(len+2);
        while((rc-1)*(len+2)+len<=60)
            rc++;
        rc--;
        int updown= n%rc==0?n/rc:n/rc+1;
        for(int i=0;i<updown;i++)
        {
            for(int j=0;j<rc;j++)
                {
                    if(i+j*updown<n)
                    {
                        string black(len+2-vec[i+j*updown].size(),' ');
                        cout<<vec[i+j*updown];
                        if(j<rc-1)
                        cout<<black;
                        else cout<<endl;
                    }else
                    cout<<endl;
                }
        }
    }
    return 0;
}
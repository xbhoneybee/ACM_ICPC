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
//codeforces 416div2

int a[10004];
int main()
{
    iosfalse
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
    {
        int l,r,x;
        cin>>l>>r>>x;
        if(x<l||x>r)
            cout<<"Yes"<<endl;
        else {
            int cnt=0;
            for(int k=l;k<=r;k++)
            {
                if(a[k]<a[x])
                    cnt++;
            }
            if(l+cnt!=x)
                cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
    }
    return 0;
}

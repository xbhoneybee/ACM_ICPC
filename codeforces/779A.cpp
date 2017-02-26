#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<set>1
#include<vector>
#include<map>
#include<sstream>
#define ll long lo`ng
#define LL long long
#define inf 1000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

int main()
{
    string str;
    int k;
    cin>>str>>k;
    int ans=0;
    int len=str.size();
    if(len<=k){
        ans=len-1;
    }else {
    int cnt=0;
    for(int i=len-1;i>=0;i--)
    {
        if(str[i]!='0')
            ans++;
        else {
            cnt++;
            if(cnt>=k)
                break;
        }
    }
    if(cnt<k)     ///hacked
        ans=len-1;
        }
    cout<<ans<<endl;
    return 0;
}

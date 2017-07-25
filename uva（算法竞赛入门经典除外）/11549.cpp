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


int main()
{
    iosfalse
    long long n,T,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        long long mmd=(long long)pow(10,n);
        long long maxnum=k;
        int cnt=0;
        while(cnt<500000)
        {
            k=k*k;
            while(k>=mmd)
                k/=10;
            if(k>maxnum)
            {
                cnt=0;maxnum=k;
            }else{
                cnt++;
            }
        }
        cout<<maxnum<<endl;
    }
    return 0;
}

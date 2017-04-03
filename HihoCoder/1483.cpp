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

//hiho 1483
//离散化 二分 尺取法
int a[200005];
int b[200005];
int vis[200005];
long long val=0;
long long mid;
bool judge(int r)
{
    val+=vis[b[r]]++;
    if(val<=mid)
        return true;
    else return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,k;
        cin>>n>>k;
        long long l=0,r=n*(n-1)/2+1;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
        }
        sort(a,a+n);
        int sizes=unique(a,a+n)-a; //sizes为离散化后元素个数
        for(int i=0;i<n;i++)
            b[i]=lower_bound(a,a+sizes,b[i])-a + 1;//b[i]为经离散化后对应的值
        while(l<r)
        {
            mid=(l+r)/2;
            val=0;
            memset(vis,0,sizeof vis);
            long long num=0,st=0;
            for(int i=0;i<n;i++)
            {
                if(judge(i))//st-i 区间值<=mid
                    ;
                else {
                    // 删去b[st]影响
                    while(val>mid){
                    num+=i-st;
                    vis[b[st]]--;
                    val-=vis[b[st]];
                    st++;
                    }
                }
            }
            num+=(n-st)*(n-st+1)/2;
            if(num>=k)
                r=mid;
            else l=mid+1;
        }
        cout<<l<<endl;
    }
    return 0;
}

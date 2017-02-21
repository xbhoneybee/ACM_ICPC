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
#define inf 10000000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

///C 发现值域很小，而且怎么异或都不会超过1024 而且每次都排序了。
int a[1030],copy_a[1030],n;
int main()
{
    int k,x;
    cin>>n>>k>>x;
    for(int i=0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            a[tmp]++;
        }
    for(int ik=0;ik<k;ik++)
    {
        memset(copy_a,0,sizeof copy_a);
        int odd=0;
        for(int j=0;j<1025;j++)
        {
            if(a[j]==0)
                continue;
            if(a[j]&1)
            {
                odd++;
                if(odd&1)
                {
                    copy_a[j^x]=(a[j]/2+1);
                    a[j]=a[j]/2;
                }else {
                    copy_a[j^x]=a[j]/2;
                    a[j]=a[j]/2+1;
                }
            }else
            {
                a[j]=copy_a[j^x]=a[j]/2;
            }
        }
        for(int j=0;j<=1024;j++)
            a[j]+=copy_a[j];
    }
    for(int i=1024;i>=0;i--)
        if(a[i]!=0)
        {
            cout<<i<<" ";
            break;
        }
    for(int i=0;i<=1024;i++)
        if(a[i]!=0)
        {
            cout<<i<<endl;
            break;
        }
    return 0;
}

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

/**直接暴力O N*N TLE
    由于a[i]<1e5 考虑用空间换时间
    对每个a[i]的约数进行标记,到下一个a[i]，若无标记则b(c)[i]=a[i],否则为标记
*/
int n,a[100005],b[100005],c[100005],mark[100005];
vector<int> vec[100005];
int main()
{
    for(int i=1;i<=100000;i++)
    {
        for(int j=1;j*j<=i;j++)
        {
            if(i%j==0)
            {
                vec[i].push_back(j);
                if(j*j!=i)
                vec[i].push_back(i/j);
            }
        }
    }
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(mark,0,sizeof mark);
        for(int i=1;i<=n;i++)
        {
            if(mark[a[i]]==0)
                b[i]=a[i];
            else b[i]=mark[a[i]];
            for(int j=0;j<vec[a[i]].size();j++)
            {
                mark[vec[a[i]][j]]=a[i];
            }
        }
        memset(mark,0,sizeof mark);
        for(int i=n;i>=1;i--)
        {
            if(mark[a[i]]==0)
                c[i]=a[i];
            else c[i]=mark[a[i]];
            for(int j=0;j<vec[a[i]].size();j++)
            {
                mark[vec[a[i]][j]]=a[i];
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
            ans+=1LL*b[i]*c[i];
        printf("%I64d\n",ans);
    }

    return 0;
}

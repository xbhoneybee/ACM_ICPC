#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define inf 100000000
using namespace std;

int a[100005];
int main()
{
    int n,m;
    int l=1,r=1e8;  //wa 点 第一次做时l取a[i]最小,r取a[i]最大WA
                    // data: 10 3 
                    //1 2 3 4 5 6 7 8 9 10
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    while(l<r)
    {
        int mid=(r+l)/2;
        long long sum_m=0,tot=1;
        for(int i=0;i<n;)
        {
            if(a[i]>mid) tot=m+1;
            if(tot>m) break;
            if(sum_m+a[i]<=mid)
                sum_m+=a[i++];
            else tot++,sum_m=0;
        }
        if(tot<=m) r=mid;
        else l=mid+1;
    }
    printf("%d\n",l);
    return 0;
}

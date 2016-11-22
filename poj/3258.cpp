#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define inf 100000000
using namespace std;

//3258
//refer to pre tag
long long a[50005];
int main()
{
    long long L;
    int n,m;
    scanf("%I64d %d %d",&L,&n,&m);
    long long l=1e10,r=L;
    for(int i=1;i<=n;i++)
        {
            scanf("%I64d",&a[i]);
        }
    a[0]=0;
    a[n+1]=L;
    sort(a,a+n+2);
    for(int i=1;i<=n+1;i++)
        {
            l=min(l,a[i]-a[i-1]);//二分一般要注意初始边界
        }
    while(l<r)
    {
        long long mid=(l+r)/2;
        long long pre=0,stone=0;
        for(int i=1;i<=n+1;i++)
        {
            if(a[i]-a[pre]<=mid)//=  这里一定要取 = wa无数次TAT why？
                {
                    stone++;
                    //数据 10 8 3 
                }   // 1 2 3 4 5 6 7 8 
            else{
            pre=i;
            }
        }
        if(stone>m) r=mid;
        else l=mid+1;
    }
    printf("%I64d\n",l);
    return 0;
}

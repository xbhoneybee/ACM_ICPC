#include <iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int isin(int ans)
{
    int bit=0;
    int copy=ans;
    int num[20]={0};
    while(copy>0)
    {
        num[bit++]=(copy%10);
        copy/=10;
    }
    if(bit==1)
    return 1;
    if(bit>1)
    {
        for(int i=0;i<bit-1;i++)
        {
            if(num[i]!=num[i+1]+1)
            return 0;
        }
        return 1;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[1005]={0};
    int maxn=-1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
    {
        if(i!=j)
        {
        int ans=a[i]*a[j];
        if(isin(ans))
        {
            maxn=max(ans,maxn);
        }
        }
    }
    cout << maxn << endl;
    return 0;
}

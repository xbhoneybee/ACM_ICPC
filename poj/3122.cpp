#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define inf 100000000
using namespace std;

//3122
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
        int n,f;
        scanf("%d %d",&n,&f);
        f+=1;
        int a[10005]={0};
        int mina=inf,maxa=-inf;
        for(int i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
                mina=min(mina,a[i]);
                maxa=max(maxa,a[i]);
            }
        const double eps=1e-8;
        double l=0,r=maxa*maxa;
        while(r-l>eps)
        {
            double m=(l+r)/2;
            int peo=0;
            for(int i=0;i<n;i++)
            {
                peo+=(int)((a[i]*a[i])/m);
            }
            if(peo>=f)
                l=m;
            else r=m;
        }
        printf("%f\n",l*acos(-1.0));
    }
	return 0;
 }

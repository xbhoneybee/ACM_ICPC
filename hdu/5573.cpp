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
#include<set>
#include<vector>
#include<map>
#include<sstream>
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);

using namespace std;


//B构造 左边2条路一定可以构造所有1<<(k)的数

int addormin[100];
long long val[100];
int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        long long n;
        int k;
        scanf("%I64d %d",&n,&k);
        long long L=1LL<<(k-1);
        for(int t=0;t<=1;t++)
        {
            long long sum;
            if(t==0)
                sum=L;
            else sum=L+1;
            memset(addormin,0,sizeof addormin);
            long long ned=n;
            for(int i=k-1;i>=0;i--)
            {
                val[i]=sum;
                if(ned>0)
                {
                    addormin[i]=1;
                    ned-=sum;
                    sum>>=1LL;
                }else if(ned==0)
                {
                    ned=1;
                    break;
                }else {
                    addormin[i]=-1;
                    ned+=sum;
                    sum>>=1LL;
                }
            }
            if(ned==0)
                break;
        }
        printf("Case #%d:\n",cas++);
        for(int i=0;i<k;i++)
        {
            char ch='-';
            if(addormin[i]==1)
                ch='+';
            printf("%I64d %c\n",val[i],ch);
        }
    }
    return 0;
}

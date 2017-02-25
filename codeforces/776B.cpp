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
#define inf 1000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;
//cin cout TLE
const int N = 100001;
int prime[N] = {0},num_prime = 0;
int isNotPrime[N] = {1, 1};
int color[N];
int main()
{
    //prime[n] store prime number ;num_prime is the number of prime;
    int n;
    scanf("%d",&n);
	for(long i = 2 ; i < N ; i ++)
       	{
		if(! isNotPrime[i])
	 		prime[num_prime ++]=i;
		for(long j = 0 ; j < num_prime && i * prime[j] <  N ; j ++)
    		{
		      	isNotPrime[i * prime[j]] = 1;
	  		if( !(i % prime[j] ) ) //select prime[j]<i;
				break;
            }
        }
    for(int i=1;i<=n;i++)//每件物品1-n
        color[i]=1;
    for(int i=1;i<=n;i++)
    {
        int pri=i+1;
        for(int j=0;j<num_prime&&prime[j]<pri;j++)
        {
            if(color[i]==color[prime[j]-1]&&pri%prime[j]==0)
                color[i]++;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(color[i],ans);
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
        printf("%d ",color[i]);
    printf("\n");
    return 0;
}

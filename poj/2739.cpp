#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<cstdlib>
#include <sstream>
#include <deque>
#include<list>
#include<time.h>
#define ll long long
#define LL long long
#define inf 10000.00
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;

const long N = 10000;
long prime[N] = {0},num_prime = 0;
//prime[n] store prime number ;num_prime is the number of prime;
int isNotPrime[N] = {1, 1};
int main()
{
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

    int n;
    while(~scanf("%d",&n))
    {
        if(n==0)
            break;
        int ans=0,sum=0;
        for(int i=0;prime[i]<=n;i++)
        {
            sum=0;
            for(int j=i;sum<n;j++)
            {
                sum+=prime[j];
                if(sum==n)
                {
                    ans++;break;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

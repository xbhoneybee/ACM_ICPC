#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string.h>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#define inf 1000000000000000000
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

//线性筛法素数结合欧拉函数
const long long  N = 1000006;
long long oulaf[N]={0,0};
long long prime[N] = {0},num_prime = 0;
//prime[n] store prime number ;num_prime is the number of prime;
int isNotPrime[N] = {1, 1};
void oula()
{
	for(long long i = 2 ; i < N ; i ++)
       	{
		if(! isNotPrime[i])
	 		{prime[num_prime ++]=i;oulaf[i]=i-1;}
		for(long long j = 0 ; j < num_prime && i * prime[j] <  N ; j ++)
    		{
		      	isNotPrime[i * prime[j]] = 1;
		      	if(i%prime[j]!=0)
		      	oulaf[i*prime[j]]=(prime[j]-1)*oulaf[i];
                else //select prime[j]<i;
				{oulaf[i*prime[j]]=oulaf[i]*prime[j];break;}
            }
        }
    return ;

}
ll ans[1000006]={0};
int main()
{
    ll n;
    oula();

    for(int i=1;i<N;i++)
        ans[i]=ans[i-1]+oulaf[i];
    while(scanf("%I64d",&n)&&n)
    {
        printf("%I64d\n",ans[n]);
    }
    return 0;
}
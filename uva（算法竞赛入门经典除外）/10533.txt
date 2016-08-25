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
#define mod 1000000007
#define iosfalse ios::sync_with_stdio(false);
using namespace std;
const int MAXN=1024;

//注意是不是digit prime也要打表
int c[1000005];
int lowbit(int x)//计算lowbit
{
     return x&(-x);
}
 void add(int i,int val)//将第i个元素增加val注意i不可为零
 {
     while(i<=1000005)//n为所开数组上界
     {
         c[i]+=val;
         i+=lowbit(i);
     }
 }
 int sum(int i)//求前i项和
 {
     int s=0;
     while(i>0)
     {
         s+=c[i];
         i-=lowbit(i);
     }
     return s;
 }
const long N = 1000005;
long prime[N] = {0},num_prime = 0;
long prime_xu[N]={0};
//prime[n] store prime number ;num_prime is the number of prime;
int isNotPrime[N] = {1, 1};
int main()
{
    for(long i = 2 ; i < N ; i ++)
       	{
		if(! isNotPrime[i])
	 		{
	 		    prime_xu[i]=num_prime;
	 		    prime[num_prime ++]=i;
	 		}
		for(long j = 0 ; j < num_prime && i * prime[j] <  N ; j ++)
    		{
		      	isNotPrime[i * prime[j]] = 1;
	  		if( !(i % prime[j] ) ) //select prime[j]<i;
				break;
            }
        }
        for(long i=0;i<num_prime;i++)
        {
            int tem=prime[i],sum=0;
            while(tem)
            {
                sum+=tem%10;
                tem/=10;
            }
            if(isNotPrime[sum]==0)
               add(prime[i],1);
        }
    int t,a,b,i,ans;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d %d",&a,&b);
        ans=sum(b)-sum(a-1);
        printf("%d\n",ans);
    }
    return 0;
}

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
//H u(n)是莫比乌斯函数,当n==1或n为k个不同素数积时,u(n)=(-1)^k k为素数个数
/**
考虑到n^k太大了,不可能加起来,思考无果打表发现规律结果为n^k
const int N = 200000;
int prime[N] = {0},num_prime = 0;
//prime[n] store prime number ;num_prime is the number of prime;
int isNotPrime[N] = {1, 1};
bool isok(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            x/=i;
            if(x%i==0)
                return false;
        }
    }
    return true;
}
int powint[10][10];
void print()
{
    for(int i = 2 ; i < N ; i ++)
       	{
		if(! isNotPrime[i])
	 		prime[num_prime ++]=i;
		for(int j = 0 ; j < num_prime && i * prime[j] <  N ; j ++)
    		{
		      	isNotPrime[i * prime[j]] = 1;
	  		if( !(i % prime[j] ) )
				break;
            }
        }
    int n=1,k=1;
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
        {
        int ret=1;
        for(int k=1;k<=j;k++)
            ret*=i;
        powint[i][j]=ret;
        }
    for(n=1;n<=5;n++)
        for(k=1;k<=5;k++)
        {
            long long ans=0;
            for(int i=1;i<=powint[n][k];i++)
            {
            if(isNotPrime[i]==0||i==1||isok(i))
            {
            ans=((ll)(sqrt(powint[n][k]*1./(i*1.)))+ans)%mmd;
            }
            }
            cout<<n<<" "<<k<<" "<<ans<<endl;
        }
}
*/
const long long mmd =1e9+7;
long long PowerMod(long long a, long long  b, long long c)
{
    long long ans = 1;
    a = a % c;
    while(b>0)
    {
    if(b % 2 == 1)
    ans = (ans * a) % c;
    b = b/2;
    a = (a * a) % c;
    }
    return ans;
}
int main()
{
    iosfalse
	long long n,k;
	int id=1;
	while(cin>>n>>k)
    {
        cout<<"Case #"<<id++<<": "<<PowerMod(n,k,mmd)<<"\n";
    }
    return 0;
}

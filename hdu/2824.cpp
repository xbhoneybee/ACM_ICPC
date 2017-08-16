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

using namespace std;

const int  N = 3000006;
int oulaf[N]={0,0};//存每个数的欧拉函数1 除外 输入1 直接输出1
int prime[N] = {0},num_prime = 0;
//prime[n] store prime number ;num_prime is the number of prime;
bool isNotPrime[N] = {1, 1};
void oula()
{
	for(int i = 2 ; i < N ; i ++)
       	{
		if(! isNotPrime[i])
	 		{prime[num_prime ++]=i;oulaf[i]=i-1;}
		for(int j = 0 ; j < num_prime && i * prime[j] <  N ; j ++)
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
int main()
{
    oula();
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        long long ans=0;
        while(a<=b)
        {
            ans+=oulaf[a];
            a++;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

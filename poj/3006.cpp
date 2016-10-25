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
const int N=1000006;
int prime[N]={0},isNotPrime[N]={1,1};
int prime_num=0;
int main()
{
    for(int i=2;i<N;i++)
        {
            if(!isNotPrime[i]) prime[prime_num++]=i;
            for(int j=0;i*prime[j]<N&&j<prime_num;j++)
            {
            isNotPrime[prime[j]*i]=1;
            if(i%prime[j]==0)
                break;
            }
        }
    int a,d,n;
    while(~scanf("%d %d %d",&a,&d,&n))
    {
        if(a==0&&d==0&&n==0)break;
        for(int i=0;i<n;)
        {
            while(isNotPrime[a]==1)
            {
                a+=d;
            }
            i++;a+=d;
        }
        printf("%d\n",a-d);
    }
    return 0;
}

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
int prime[N]={0},prime_num=0;
int isNotPrime[N]={1,1};
int main()
{
    for(int i=2;i<N;i++)
    {
        if(!isNotPrime[i])
            prime[prime_num++]=i;
        for(int j=0;j<prime_num&&i*prime[j]<N;j++)
        {
            isNotPrime[i*prime[j]]=1;
            if(!(i%prime[j]))
                break;
        }
    }
    int n;
    while(cin>>n){
        if(n==0)
            break;
        int a=-1,b=-1;
        int id=0;
        for(int id=0;prime[id]<=n/2;id++)
        {
            if(isNotPrime[n-prime[id]]==0)
            {
                a=prime[id];b=n-a;
                break;
            }
        }
        if(a==-1&&b==-1)
            cout<<"Goldbach's conjecture is wrong."<<endl;
        else cout<<n<<" = "<<a<<" + "<<b<<endl;

    }
       return 0;
}

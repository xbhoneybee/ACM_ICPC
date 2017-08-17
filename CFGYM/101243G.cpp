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

const int N =(10467397)/6+100;
int prime[N] = {0},num_prime = 0;
//prime[n] store prime number ;num_prime is the number of prime;
int isNotPrime[N] = {1, 1};
int main()
{
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);

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
    int x;
    scanf("%d",&x);

        bool ok=true;
        vector<int>vec;
        for(int cnt=0;cnt<num_prime;cnt++)
        {
            while(x%prime[cnt]==0)
            {
                x/=prime[cnt];
                vec.push_back(prime[cnt]);
            }
        }
        if(vec.size()==3&&vec[0]<vec[1]&&vec[1]<vec[2])
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    return 0;
}

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
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;


//math 
int main()
{
    long long  n,m;
    cin>>n>>m;
    if(n<=m)
        cout<<n<<endl;
    else{
        long long b=8*(n-m)+1;
        long long sqb=sqrt(b);
        long long ans=(2*m-1+sqb)/2;
        while((ans*2+1-2*m)*(ans*2+1-2*m)<b)
            ans++;
        cout<<ans<<endl;
    }
    return 0;
}

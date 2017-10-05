#include <bits/stdc++.h>
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
//D


int gcd(int x , int y) //当1方为0 返回另一方
{
if(!y)
return x;
else return gcd(y , x%y);
}
string name[2];
int main()
{
    name[0]="Iaka";
    name[1]="Yuwgna";
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        int n,a,b;
        scanf("%d %d %d",&n,&a,&b);
        int ans=0;
        int cd=gcd(a,b);
        for(int t=1;t<=n;t++)
        {
            if(t%cd==0)
            ans++;
        }
        if(ans&1)
        printf("Case #%d: %s\n",cas++,name[1].c_str());
        else
        printf("Case #%d: %s\n",cas++,name[0].c_str());
    }
    return 0;
}

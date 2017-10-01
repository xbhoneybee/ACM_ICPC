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
#define iosfalse ios::snync_with_stdio(false);

using namespace std;

/**
数学题，推出gcd(x,y)==gcd(a,b),解方程
*/
int gcd(int x , int y) //当1方为0 返回另一方
{
if(!y)
return x;
else return gcd(y , x%y);
}
int main(){
	int a,b;
	while(~scanf("%d%d",&a,&b)){
		int g=gcd(a,b);
		long long A=a/g;
		long long B=b/g;
		bool ok=true;
		long long delta=A*A-4*B;
		if(delta>=0){
            long long sdt=sqrt(delta)+0.5;
			if(sdt*sdt==delta&&(A-sdt)%2==0)
				ok=true;
            else ok=false;
		}else ok=false;
		if(ok){
            long long sdt=sqrt(delta)+0.5;
			cout<<g*(A-sdt)/2<<' '<<g*(A+sdt)/2<<endl;
		}else{
			printf("No Solution\n");
		}
	}
    return 0;
}

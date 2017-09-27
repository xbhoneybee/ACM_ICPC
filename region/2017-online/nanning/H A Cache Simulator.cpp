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
#define iosfalse ios::snync_with_stdio(false);

using namespace std;

/*
sb计组题
*/
vector<int> num;
int cat[66];
int sizes=0;

void solve(){
	for(int i=0;i<=64;i++)cat[i]=-1;
	int cnt=0;
	for(int i=0;i<num.size();i++){
		int r=num[i]/16;
		if(cat[r%64]==r){
			cnt++;
			printf("Hit\n");
		}else{
			cat[r%64]=r;
			printf("Miss\n");
		}
	}
	printf("Hit ratio = %.2f%%\n",(double)cnt*100.0/(1.*sizes));
}
int main(){
    char s[10];
    int tem;
	while(~scanf("%s",s)){
		if(s[1]=='N')
            break;
        sizes++;
	    sscanf(s,"%x",&tem);
		num.push_back(tem);
	}
	solve();
	return 0;
}

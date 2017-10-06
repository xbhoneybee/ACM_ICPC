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


int a[1001];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int res=(a[0]+a[1])^a[2];
        int t;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                for(int k=0;k<n;k++){
                    if(k==i||k==j)continue;
                    t=(a[i]+a[j])^a[k];
                    if(t>res)res=t;
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}

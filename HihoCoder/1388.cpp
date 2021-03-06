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

///NTT
const int MAXN=280100;
const long long P=50000000001507329LL; // 190734863287 * 2 ^ 18 + 1
//const int P=1004535809; // 479 * 2 ^ 21 + 1
//const int P=998244353; // 119 * 2 ^ 23 + 1
const int G=3;

long long mul(long long x,long long y){
  return (x*y-(long long)(x/(long double)P*y+1e-3)*P+P)%P;
}
long long qpow(long long x,long long k,long long p){
  long long ret=1;
  while(k){
    if(k&1) ret=mul(ret,x);
    k>>=1;
    x=mul(x,x);
  }
  return ret;
}

long long wn[30];
void getwn(){
  for(int i=1; i<21; ++i){
    int t=1<<i;
    wn[i]=qpow(G,(P-1)/t,P);
  }
}

int len;
void NTT(long long y[],int op){
  for(int i=1,j=len>>1,k; i<len-1; ++i){
    if(i<j) swap(y[i],y[j]);
    k=len>>1;
    while(j>=k){
      j-=k;
      k>>=1;
    }
    if(j<k) j+=k;
  }
  int id=0;
  for(int h=2; h<=len; h<<=1) {
    ++id;
    for(int i=0; i<len; i+=h){
      long long w=1;
      for(int j=i; j<i+(h>>1); ++j){
        long long u=y[j],t=mul(y[j+h/2],w);
        y[j]=u+t;
        if(y[j]>=P) y[j]-=P;
        y[j+h/2]=u-t+P;
        if(y[j+h/2]>=P) y[j+h/2]-=P;
        w=mul(w,wn[id]);
      }
    }
  }
  if(op==-1){
  for(int i=1; i<len/2; ++i) swap(y[i],y[len-i]);
  long long inv=qpow(len,P-2,P);
  for(int i=0; i<len; ++i) y[i]=mul(y[i],inv);
  }
}
void Convolution(long long A[],long long B[],int n){
  for(len=1; len<(n<<1); len<<=1);
  for(int i=n; i<len; ++i){
    A[i]=B[i]=0;
  }

  NTT(A,1); NTT(B,1);
  for(int i=0; i<len; ++i){
    A[i]=mul(A[i],B[i]);
  }
  NTT(A,-1);
}

long long A[MAXN],B[MAXN];
int main(){
  getwn();
  int t,n;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    long long ans=0;
    for(int i=0; i<n; ++i){
      scanf("%lld",&A[i]);
      ans+=A[i]*A[i];
    }
    for(int i=0; i<n; ++i){
      scanf("%lld",&B[n-i-1]);
      ans+=B[n-i-1]*B[n-i-1];
    }
    for(int i=0; i<n; ++i){
      A[i+n]=A[i];
      B[i+n]=0;
    }
    Convolution(A,B,2*n);
    long long mx=0;
    for(int i=n; i<2*n; ++i){
      mx=max(mx,A[i]);
    }
    printf("%lld\n",ans-2*mx);
  }
  return 0;
}

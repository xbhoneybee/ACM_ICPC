
#include<bits/stdc++.h>  
using namespace std;  
const int MX = 5e6 + 5;  
const int mod = 100000073;  
/****** 
f[x]：有x层楼时需要测试的次数 
p[x]：从第P[x]楼开始需要至少测试x次 
cnt[x]：有x层楼时的方案数 
sum[x]：cnt的前缀和 
http://blog.csdn.net/qq_31759205/article/details/75238761
******/  
int f[MX],p[MX],cnt[MX],sum[MX];  
int main(){  
    for(int x=0,index=1;index<MX;){  
        if(x*(x+1)/2<index) p[++x]=index;  
        f[index++]=x;  
    }  
    cnt[1]=sum[0]=1;sum[1]=2;  
  
    /****** 
    设现在有x层楼,需要进行f[x]次测试，那么它的方案一定是从f[x]-1转移过来的， 
    我们设变量y，有f[y]=f[x]-1，很明显p[f[x]-1]<=y<p[f[x]] 
    通过上面的分析可知：如果测试次数有k次，那么第一次测试可以选择第k层， 
    因此第x层可以由第[x-k,x-1]层转移过来，但由于策略要选取最优的，因此上界为p[f[i]]-1 
    ******/  
    for(int i=2;i<MX;i++){  
        int st=i-f[i],ed=p[f[i]]-1;  
        cnt[i]=(sum[ed]-sum[st-1]+mod)%mod;  
        sum[i]=(sum[i-1]+cnt[i])%mod;  
    }  
    int L,R;  
    while(~scanf("%d%d",&L,&R)) printf("%d %d\n",f[R-L+1],cnt[R-L+1]);  
    return 0;  
}  

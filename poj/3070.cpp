#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>
#include<string.h>
#include<set>
#include<queue>
#include<cctype>
#include<map>
#include<stack>
#define inf 1000000000
#define ll long long
#define mod 10000//  这里不要写成100000000+7 define是替换！！！
using namespace std;
#define iosfalse ios::sync_with_stdio(false);


//  矩阵快速幂 不会写二分操作,尴尬

ll rec[2][2]={{1,1},{1,0}};
ll fb[2][2]={{1,1},{1,0}};
ll ansfb[2][2]={{1,1},{1,0}};
void multifb()
{
    {
    ansfb[0][0]=fb[0][0]*rec[0][0]+fb[0][1]*rec[1][0];
    ansfb[0][1]=fb[0][0]*rec[0][1]+fb[0][1]*rec[1][1];
    ansfb[1][0]=fb[1][0]*rec[0][0]+fb[1][1]*rec[1][0];
    ansfb[1][1]=fb[1][0]*rec[0][1]+fb[1][1]*rec[1][1];
    fb[0][0]=ansfb[0][0]%mod;
    fb[0][1]=ansfb[0][1]%mod;
    fb[1][0]=ansfb[1][0]%mod;
    fb[1][1]=ansfb[1][1]%mod;
    }
    return ;
}
void multirec()
{
    {
    ansfb[0][0]=rec[0][0]*rec[0][0]+rec[0][1]*rec[1][0];
    ansfb[0][1]=rec[0][0]*rec[0][1]+rec[0][1]*rec[1][1];
    ansfb[1][0]=rec[1][0]*rec[0][0]+rec[1][1]*rec[1][0];
    ansfb[1][1]=rec[1][0]*rec[0][1]+rec[1][1]*rec[1][1];
    rec[0][0]=ansfb[0][0]%mod;
    rec[0][1]=ansfb[0][1]%mod;
    rec[1][0]=ansfb[1][0]%mod;
    rec[1][1]=ansfb[1][1]%mod;
    }
    return ;
}
int main ()
{

    ll n;
    while(cin>>n&&n!=-1)
    {
        if(n==0) {
            cout<<0<<endl;
            continue;
        }
        n--; //这里思考一下
        while(n)  //2分套路
        {
            if(n&1)
            {
               multifb();
            }
            n/=2;
            multirec();
        }
        cout<<(fb[1][0])%10000<<endl;
        fb[0][0]=1;
        fb[1][0]=1;
        fb[0][1]=1;
        fb[1][1]=0;
        rec[0][0]=1;
        rec[1][0]=1;
        rec[0][1]=1;
        rec[1][1]=0;
    }
    return 0;
}
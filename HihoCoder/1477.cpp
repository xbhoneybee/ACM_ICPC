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
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;


long long add[30]={
78796799,
94694399,
126230399,
157766399,
189302399,
220924799,
252460799,
283996799,
315532799,
362793599,
394329599,
425865599,
489023999,
567993599,
631151999,
662687999,
709948799,
741484799,
773020799,
820454399,
867715199,
915148799,
1136073599,
1230767999,
1341100799,
1435708799,
1483228799};
long long today(int y,int m,int d){
    long long ans = 0;
    for(int i = 1970 ; i < y ; i++){
        if(((i%4==0)&&(i%100!=0))||(i%400==0))
            ans += 366;
        else ans += 365;
    }
    for(int i = 1 ; i < m ; i++){
        if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
            ans += 31;
        else if(i==2){
            if(((y%4==0)&&(y%100!=0))||(y%400==0))
                ans += 29;
            else ans += 28;
        }
        else ans += 30;
    }
    ans += d-1;
    return ans;
}
int main()
{
    int y1,y2,mon1,mon2,d1,d2,h1,h2,m1,m2,s1,s2;
    scanf("%d-%d-%d %d:%d:%d",&y1,&mon1,&d1,&h1,&m1,&s1);
    scanf("%d-%d-%d %d:%d:%d",&y2,&mon2,&d2,&h2,&m2,&s2);
    long long ans1=s1+m1*60+h1*60*60+today(y1,mon1,d1)*60*60*24;
    long long ans2=s2+m2*60+h2*60*60+today(y2,mon2,d2)*60*60*24;
    int up1=0,up2=0;
    for(int i=0;i<40;i++)
    {
        if(add[i]==0)
            break;
        if(ans1>add[i]+1)
            up1++;
        if(ans1==add[i]+1&&s1==0)
            up1++;
        if(ans2>add[i]+1)
            up2++;
        if(ans2==add[i]+1&&s2==0)
            up2++;
    }
    long long out=ans2-ans1+up2-up1;
    cout<<out<<endl;
    return 0;
}

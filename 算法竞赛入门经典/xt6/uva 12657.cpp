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
#define inf 100000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

int n,op,Left[100005],Right[100005];
void init()
{
    for(int i=1;i<=n;i++)
    {
        Left[i]=i-1;
        Right[i]=i+1;
    }
    Right[n]=0;//the left of one is zero, the right of n is zero
}
void one (int x,int y)
{

    if(Left[x]!=0)
        Right[Left[x]]=Right[x];
    Left[Right[x]]=Left[x];
    Right[Left[y]]=x;
    Left[x]=Left[y];
    Left[y]=x;
    Right[x]=y;
}
void two(int x,int y)
{
    if(Left[x]!=0)
        Right[Left[x]]=Right[x];
    Left[Right[x]]=Left[x];
    if(Right[y]!=0)
        Left[Right[y]]=x;
    Right[x]=Right[y];
    Left[x]=y;
    Right[y]=x;
}
void three(int x,int y)//不要默认x与y间隔
{
    if(Right[x]==y)
    {
        if(Left[x]!=0)
            Right[Left[x]]=y;
        if(Right[y]!=0)
            Left[Right[y]]=x;
        Right[x]=Right[y];
        Left[y]=Left[x];
        Left[x]=y;Right[y]=x;
    }else if(Left[x]==y)
    {
        if(Left[y]!=0)
            Right[Left[y]]=x;
        if(Right[x]!=0)
            Left[Right[x]]=y;
        Right[y]=Right[x];
        Left[x]=Left[y];
        Left[y]=x;Right[x]=y;
    }else {
        int tl=Left[y];
        int tr=Right[y];
        if(Left[x]!=0)
            Right[Left[x]]=y;
        Left[Right[x]]=y;
        if(Right[y]!=0)
            Left[Right[y]]=x;
        Right[Left[y]]=x;
        Left[y]=Left[x];
        Right[y]=Right[x];
        Left[x]=tl;
        Right[x]=tr;
    }
}
void four()
{
    if(op==0)
        op=1;
    else op=0;
}
int main()
{
    //freopen("output.txt","w",stdout);
    int m,id=1;
    while(scanf("%d%d",&n,&m)!=EOF){
    op=0;
    init();
    for(int i=0;i<m;i++)
    {
        int ord,x,y;
        scanf("%d",&ord);
        if(ord==4)
        {
            four();
        }else {
        scanf("%d%d",&x,&y);
        if(ord==3)
            three(x,y);
        else if(ord==2)
        {
            if(op==1)
                one(x,y);
            else two(x,y);
        }else {
            if(op==1)
                two(x,y);
            else one(x,y);
        }
        }
    }
    ll ans=0;
    int st,seq=1;
    for(int i=1;i<=n;i++)
    {
        if(Left[i]==0)
        {
            st=i;break;
        }
    }
    if(n%2==0&&op==1)//even
    {
        while(seq<n)
        {
            ans+=Right[st];
            st=Right[Right[st]];
            seq+=2;

        }
    }else //odd
    {
        while(seq<=n)
        {
            ans+=st;
            st=Right[Right[st]];
            seq+=2;
        }
    }
    cout<<"Case "<<id++<<": "<<ans<<endl;
    }
    return 0;
}

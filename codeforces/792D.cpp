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
#define lowbit(x) x&-x

using namespace std;

//D

long long POW[100];
long long n,q,head;
void up(long long &x)
{
    if(x==head)
        return;
    if(x&1)
    {
        if((x+1)%4==0)
            x=x-1;
        else x=x+1;
    }else{
        for(int i=2;i<=59;i++)
        {
            if(x%POW[i]==POW[i-1])
            {
                if(x/POW[i]==0)
                {
                    x=POW[i];
                }else x=x/POW[i+1]*POW[i+1]+POW[i];
                return ;
            }
        }
    }
}
void lef(long long &x)
{
    if(x&1)
    {
        return;
    }else{
        for(int i=2;i<=59;i++)
        {
            if(x%POW[i]==POW[i-1])
            {
                x=x-POW[i-2];
                return;
            }
        }
    }
}
void rig(long long &x)
{
    if(x&1)
    {
        return;
    }else{
        for(int i=2;i<=59;i++)
        {
            if(x%POW[i]==POW[i-1])
            {
                x=x+POW[i-2];
                return;
            }
        }
    }
}
int main()
{
    cin>>n>>q;
    POW[0]=1;
    for(int i=1;POW[i-1]<=1e18/2;i++)
        {
            POW[i]=POW[i-1]*2;
            //0-59
        }
    for(int i=1;i<=59;i++)
        {
            if((n+1)==POW[i])
            {
                head=POW[i-1];
                break;
            }
        }
    for(int i=0;i<q;i++)
    {
        long long st=0;
        string cmd;
        cin>>st>>cmd;
        for(int j=0;j<cmd.size();j++)
        {
            if(cmd[j]=='U')
            {
                up(st);
            }else if(cmd[j]=='L')
            {
                lef(st);
            }else{
                rig(st);
            }
        }
        cout<<st<<endl;
    }
    return 0;
}

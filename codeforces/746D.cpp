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
#define ll long long
#define LL long long
#define inf 1000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

int main()
{
    int n,k,g,b;
    cin>>n>>k>>g>>b;
    k++;
    if(g==0||b==0)
    {
        if(g<k&&b<k)
        {
            if(g==0)
                cout<<string(b,'B')<<endl;
            else cout<<string(g,'G')<<endl;
        }
        else cout<<"NO"<<endl;
    }else{
    int change=0;
    if(b>=g) {
        swap(b,g);
        change=1;//swap the color
    }
    b++;
    string ans="";
    int base =g/b;
    int no=0;
    char cbig='G',csmall='B';
    if(change)
        swap(cbig,csmall);
    if(g%b==0)
    {
        if(base>=k)
            no=1;
        else{
            for(int i=0;i<b;i++)
            {
            ans+=string(base,cbig);
            if(i<b-1) ans+=csmall;
            }
        }
    }else{
        b--;
        base=g/b;
        if(g%b>base)
            base++;
        if(base>=k)
            no=1;
        else {
            if(g%b<=g/b)
            {
            ans+=string(g%b,cbig);
            for(int i=0;i<b;i++)
            {
            ans+=csmall;
            ans+=string(base,cbig);
            }
            }else {
            int add=g%b;
            for(int i=0;i<b;i++)
            {
            ans+=csmall;
            if(i<add)
            ans+=string(base,cbig);
            else ans+=string(base-1,cbig);
            }
            }
        }
    }
    if(no==1)
        cout<<"NO"<<endl;
    else cout<<ans<<endl;
    }
    return 0;
}

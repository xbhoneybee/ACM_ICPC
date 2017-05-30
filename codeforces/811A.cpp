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


int main()
{
    long long  a,b;
    long long tot=1;
    cin>>a>>b;
    bool one=true;
    while(true)
    {
        if(one)
        {
            if(a>=tot)
            {
              a-=tot;
              tot++;
              one=false;
            }else break;
        }else {
            if(b>=tot)
            {
                b-=tot;
                tot++;
                one=true;
            }else break;
        }
    }
    if(one)
        cout<<"Vladik"<<endl;
    else cout<<"Valera"<<endl;
    return 0;
}

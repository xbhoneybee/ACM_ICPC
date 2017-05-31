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


//碰撞=相互穿越
int main()
{
    int T,t,L;
    cin>>L>>t>>T;
    if(T<=t)
    {
        cout<<(L-T%L)<<endl;
    }else {
        int cp1,cp2;
        if((T/L)%2==0)
            cp1=T%L;
        else cp1=L-T%L;
        T-=t;
        if((T/L)%2==1)
            cp2=T%L;
        else cp2=L-T%L;
        cout<<abs(cp1-cp2)<<endl;
    }
    return 0;
}

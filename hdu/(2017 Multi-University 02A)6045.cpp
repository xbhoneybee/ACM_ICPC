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

int n,T,x,y;
string Derek,Alifa;
int main()
{
    iosfalse
    cin>>T;
    while(T--)
    {
        cin>>n>>x>>y;
        cin>>Derek>>Alifa;
        int sam=0;
        for(int i=0;i<n;i++)
        {
            if(Derek[i]==Alifa[i])
                sam++;
        }
        if(x<y)
            swap(x,y);
        if(x-y>n-sam)
            cout<<"Lying"<<endl;
        else {
            if(y<=sam)
            {
                cout<<"Not lying"<<endl;
            }else {
                x-=sam;
                y-=sam;
                n=n-sam;
                if(x+y>n)
                    cout<<"Lying"<<endl;
                else  cout<<"Not lying"<<endl;
            }
        }
    }
    return 0;
}

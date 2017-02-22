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
    int n;
    string coded;
    cin>>n>>coded;
    string code(n,'.');
    for(int i=0;i<n;i++)
    {
        if(!(i&1))//i even
        {
        if(n&1)
            code.at(n/2+i/2)=coded[i];
        else code.at(n/2-1-i/2)=coded[i];
        }else {//i odd
        if(n&1)
            code.at(n/2-(i+1)/2)=coded[i];
        else code.at(n/2-1+(i+1)/2)=coded[i];
        }
    }
    cout<<code<<endl;
    return 0;
}

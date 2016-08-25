#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string.h>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#define inf 1000000000
#define ll long long
#define mod 1000000007//  这里不要写成100000000+7 define是替换！！！
#define iosfalse ios::sync_with_stdio(false);
using namespace std;
const int MAXN=1025;



int main()
{
    int n;
    int m[105];
    int c[105];
    int mw=0,cw=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m[i]>>c[i];
        if(m[i]>c[i]) mw++;
        else if(m[i]<c[i]) cw++;
    }
    if(mw>cw)
        cout<<"Mishka"<<endl;
    else if(mw<cw)
        cout<<"Chris"<<endl;
    else cout<<"Friendship is magic!^^"<<endl;

    return 0;
}
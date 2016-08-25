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
#define inf 1000000000000000000
#define ll long long
#define mod 1000000007
#define iosfalse ios::sync_with_stdio(false);
using namespace std;
const int MAXN=1024;

char alpha[100]="A,b,d,H,I,M,O,o,p,q,T,U,V,v,W,w,X,x,Y";  //wa µã
char alphb[100]="A,d,b,H,I,M,O,o,q,p,T,U,V,v,W,w,X,x,Y";
char alphc[100]="A,H,I,M,O,o,T,U,V,v,W,w,X,x,Y";
int isina(char x)
{
    int n=strlen(alpha),i=0;
    for(;i<n;i++)
    {
        if(x==alpha[i])
            return i;
    }
    return -1;
}
int isinc(char x)
{
    int n=strlen(alphc),i=0;
    for(;i<n;i++)
    {
        if(x==alphc[i])
            return i;
    }
    return -1;
}
int main()
{

    string s;
    cin>>s;
    int flag=1;
    int n=s.size();
    for(int i=0;i<n/2;i++)
    {
        if(isina(s[i])==-1)
            {flag=0;break;}
        int tem=isina(s[i]);
        if(s[n-1-i]!=alphb[tem])
        {
            flag=0;break;
        }
    }
    if(n&1)
    {
        if(isinc(s[n/2])==-1)
        flag=0;
    }
    if(flag)
        cout<<"TAK"<<endl;
    else cout<<"NIE"<<endl;
    return 0;
}
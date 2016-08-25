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


int main()
{
    int n,a[1004],numzero=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n==1)
    {
        if(a[0]==1)
        {
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }else{
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
                numzero++;
            if(numzero>=2)
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        if(numzero==1)  //wa µã
        cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
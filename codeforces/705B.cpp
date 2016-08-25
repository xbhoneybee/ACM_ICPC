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


int a[100005];
int main()
{
    iosfalse
    int n;
    cin>>n;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>1) sum+=a[i]-1;
        if(sum%2==0) cout<<2<<endl;
        else cout<<1<<endl;
    }
    return 0;

}
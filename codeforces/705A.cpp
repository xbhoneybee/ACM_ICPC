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
    cin>>n;
    string s,s1,s2,s3;
    s="I hate";
    s3=" it";
    s1=" that I love";
    s2=" that I hate";
    cout<<s;
    for(int i=1;i<=n;i++)
    {
        if(i>1&&i%2==0) cout<<s1;
        else  if(i>1)cout<<s2;
    }
    cout<<s3;
    return 0;
}
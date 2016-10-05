#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<cstdlib>
#include <sstream>
#include <deque>
#include<list>
#include<time.h>
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

int isok(int i,int n)
{
    int sumn=0,sumi=0;
    while(n)
    {
        sumn+=(n%10);
        n/=10;
    }
    while(i)
    {
        sumi+=(i%10);
        i/=10;
    }
    if(sumi==sumn-1)
        return 1;
    else return 0;
}
int main()
{
    string s;
    while(cin>>s)
    {
        int n=0;
        stringstream ss;
        if(s=="END") break;
        ss<<s;
        ss>>n;
        for(int i=n-1;i>=0;i--)
        {
            if(isok(i,n))
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}

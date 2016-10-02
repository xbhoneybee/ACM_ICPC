#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<stdlib.h>
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

//A
int main()
{
    int n;
    int h,m;
    char ch;
    scanf("%d",&n);
    scanf("%d:%d",&h,&m);
    if(m>59)
    {
        m=m%10;
    }
    if(n==12)
    {
        if(h>12)
        {
            h=h%10;
        }//被hack 点 之前先判断为0 后取个位数会在h==30 时，令h=0;  wa
        if(h==0) h=10;
        if(1<=h&&h<=12)
        {
            if(h<10)
                cout<<0;
            cout<<h<<':';
            if(m<10)
                cout<<0;
            cout<<m<<endl;
            return 0;
        }
    }
    else {
        if(h>23)
        {
            h=h%10;
        }
        if(0<=h&&h<=23)
        {
            if(h<10)
                cout<<0;
            cout<<h<<':';
            if(m<10)
                cout<<0;
            cout<<m<<endl;
            return 0;
        }
    }
    return 0;
}

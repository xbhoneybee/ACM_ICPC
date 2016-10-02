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


//D
int y[50005];
int main()
{
    set<int> sty;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&y[i]);
        sty.insert(y[i]);
    }
    set<int>::iterator ip;
    while(1)
    {
        ip=sty.end();
        ip--;
        int maxel=*ip;
        while(sty.count(maxel)==1&&maxel>0)//贪心，即使找到之前的出现maxel>>1继续找下去。
        {
            maxel>>=1;
            //cout<<maxel<<endl;
        }
        if(maxel==0)
            break;
        sty.erase(ip);
        sty.insert(maxel);
    }
    for(ip=sty.begin();ip!=sty.end();ip++)
        cout<<*ip<<" ";
    cout<<endl;
    return 0;
}

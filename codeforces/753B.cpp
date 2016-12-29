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
#include<ctime>
#define ll long long
#define LL long long
#define inf 10000.00
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

int main()
{
    int i=0;
    int four[4]={0};
    int cnt=0;
    while(true)
    {
        if(i<=9)
        {
            for(int mm=0;mm<4;mm++)
            cout<<i;
            cout<<endl;
            fflush(stdout);
        }
        else{
            for(int mm=0;mm<4;mm++)
            cout<<four[mm];
            cout<<endl;
            fflush(stdout);
            next_permutation(four,four+4);
        }
        int x,y;
        cin>>x>>y;
        if(i<=9&&x==1&&y==0)
            {
                four[cnt++]=i;
                if(cnt==4)
                    sort(four,four+4);
            }
        else if(x==4&&y==0)
            break;
        i++;
    }
    return 0;
}

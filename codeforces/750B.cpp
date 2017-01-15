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
    int n;
    cin>>n;
    int y=0;
    int state=1;
    for(int i=0;i<n;i++)
    {
        int dis=0;
        string dir;
        cin>>dis>>dir;
        if(dir=="North")
        {
            if(y>=dis)
                y-=dis;
            else state=0;
        }else if(dir=="South")
        {
            if(y+dis<=20000)
                y+=dis;
            else state=0;
        }else
        {
            if(y==0||y==20000)
                state=0;
        }
    }
    if(y!=0)
        state=0;
    if(state==1)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

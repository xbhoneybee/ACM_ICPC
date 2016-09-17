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
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

int t[100005];
int main()
{
    int n,c;
    int tot=1;
    cin>>n>>c;
    for(int i=0;i<n;i++)
        {
            cin>>t[i];
            if(i){
                if(t[i]-t[i-1]<=c)
                    tot++;
                else
                tot=1;
            }
        }
    cout<<tot<<endl;
    return 0;
}

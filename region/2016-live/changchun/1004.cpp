#include <iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#include<cstring>
#include<set>
#include<queue>
#include<cctype>
#include<map>
#include<stack>
#include<cstdlib>
#include<sstream>
#include<deque>
#include<list>
#define ll long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;
int ans[]={0,0,0,0,1,1,
2,3,3,4,5,
6,7,7,8,9,
10,11,12,13,14};
int main()
{
    int  t;
    cin>>t;
    for(int it=1;it<=t;it++)
    {
        int n;
        cin>>n;

        cout<<"Case #"<<it<<": ";
        cout<<ans[n]<<endl;
    }
    return 0;
}

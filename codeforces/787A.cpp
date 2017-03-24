#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<vector>
#include<map>
#include<sstream>
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(falllllse);
#define lowbit(x) x&-x
using namespace std;


int main()
{

    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a<c)
    {
        swap(a,c);
        swap(b,d);
    }
    for(int i=0;a*i+b-d<1e8;i++)
    {
            {
                cout<<a*i+b<<endl;
                return 0;
            }
    }
    cout<<-1<<endl;
    return 0;
}

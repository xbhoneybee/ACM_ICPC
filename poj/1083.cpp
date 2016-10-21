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
#define inf 10000.00
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;

//被细节处理坑了，大水题
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ap[505]={0};
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            int x,y;
            cin>>x>>y;
            if(x>y) swap(x,y);//
            if(x%2==0)x=x/2-1;//细节
            else x/=2;
            if(y%2==0)y=y/2-1;//detail
            else y/=2;        //
            for(int j=x;j<=y;j++)
                ap[j]++;
        }
        for(int i=0;i<300;i++)
        {
            //cout<<ap[i]<<" ";
            //if((i+10)%20==0) cout<<endl;
            ans=max(ap[i],ans);
        }
        cout<<ans*10<<endl;
    }
    return 0;
}

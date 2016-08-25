#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>
#include<string.h>
#include<set>
#include<queue>
#include<cctype>
#include<map>
#include<stack>
#define inf 1000000000
#define ll long long
#define mod 1000000007//  这里不要写成100000000+7 define是替换！！！
using namespace std;
#define iosfalse ios::sync_with_stdio(false);

struct P {
    int x;
    int y;
}point[4];
int cmp( P a,P b)
{
    if(a.x!=b.x) return a.x<b.x;
    else return a.y<b.y;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
          cin>>point[i].x>>point[i].y;
        }
        if(n==1) {
            cout<<-1<<endl;
            continue;
        }
        if(n==2)
        {
            if((point[0].x==point[1].x)||(point[0].y==point[1].y))
                cout<<-1<<endl;
            else
                cout<<abs((point[0].x-point[1].x)*(point[0].y-point[1].y))<<endl;
                continue;
        }
        if(n==3)
        {
            sort(point,point+n,cmp);
            if((point[1].y-point[2].y)!=0)
            cout<<abs((point[0].x-point[2].x)*(point[1].y-point[2].y))<<endl;
            else
            cout<<abs((point[0].x-point[2].x)*(point[0].y-point[2].y))<<endl;
        }
        if(n==4)
        {
             sort(point,point+n,cmp);
             cout<<abs((point[0].x-point[3].x)*(point[0].y-point[3].y))<<endl;
        }
    }

    return 0;
}
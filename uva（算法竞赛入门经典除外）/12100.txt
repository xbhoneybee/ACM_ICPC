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
#define inf 1000000000.000
#define ll long long
#define mod 1000000007//  这里不要写成100000000+7 define是替换！！！
using namespace std;

struct placequeue
{
    int p;
    int v;
}place[105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int needc=0;
        int n,m;
        cin>>n>>m;
        queue <placequeue> q;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            place[i].p=i;
            place[i].v=x;
            q.push(place[i]);
        }
        int ans=0;
        while(!q.empty())
        {
            placequeue tem=q.front();
            place[tem.p].v=0;
            q.pop();
            int flag=1;
            for(int i=0;i<n;i++)
            {
                if(place[i].v>tem.v)
                {
                    flag=0;
                    break;
                }
            }
            if(flag){
                ans++;
                if(tem.p==m)
                {
                    cout<<ans<<endl;
                    needc=1;
                }
            }
            else{
                q.push(tem);
                place[tem.p].v=tem.v;
            }
            if(needc) break;
        }
    }

    return 0;
}
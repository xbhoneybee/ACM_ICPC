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
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e18
#define lowbit(x) x&-x
using namespace std;

//用队列/set 维护模拟(app的queue 和notification 的set分开维护 不用及时同步 )降低复杂度
queue <int> app[300005];
set < pair<int ,int > >noti;
int vis[300005];
int main()
{
    int n,qt;
    int tot=0,ans=0;
    scanf("%d %d",&n,&qt);
    for(int i=1;i<=qt;i++)
      {
          int kind,x;
        scanf("%d %d",&kind,&x);

        if(kind==1) {
            tot++;
            app[x].push(tot);
            noti.insert(make_pair(tot,x));
            ans++;
            printf("%d\n",ans);
        }
        else if(kind==2)
        {
            while(!app[x].empty())
            {
                int tmp=app[x].front();
                app[x].pop();
                vis[tmp]=1;//标记为已读
                ans--;
            }
            printf("%d\n",ans);
        }
        else {
            while(!noti.empty()&&(*noti.begin()).first<=x)
            {
                if(!vis[(*noti.begin()).first])//如果未读 
                    app[(*noti.begin()).second].pop(),ans--;
                noti.erase(noti.begin());//消去已读 ，同步

            }
            printf("%d\n",ans);
        }
      }
    return 0;
}

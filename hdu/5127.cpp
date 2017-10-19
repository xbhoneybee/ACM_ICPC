#include <bits/stdc++.h>
#include<sstream>
#include<ctime>
#define iosfalse ios::sync_with_stdio(false);

using namespace std;

struct P
{
    long long x,y;
    bool eated;
}p[500500];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
    if(n==0)
    break;
    memset(p,0,sizeof p);
    int cnt=0;
    while(n--)
    {
        int cmd,x,y;
        scanf("%d %d %d",&cmd,&x,&y);
        if(cmd==0)
        {
            long long ans=-9000000000000000000LL;
            for(int i=0;i<cnt;i++)
            {
                if(p[i].eated==false)
                {
                    ans=max(ans,p[i].x*x+p[i].y*y);
                }
            }
            cout<<ans<<endl;
        }else if(cmd==1)
        {
            p[cnt].x=x;
            p[cnt].y=y;
            p[cnt].eated=false;
            cnt++;
        }else {
            for(int i=0;i<cnt;i++)
                {
                    if(p[i].x==x&&p[i].y==y&&p[i].eated==false)
                        {
                            p[i].eated=true;
                            break;
                        }
                }
        }
    }
    }
    return 0;
}

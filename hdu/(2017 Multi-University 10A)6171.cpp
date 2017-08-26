//#include <bits/stdc++.h>
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
#define iosfalse ios::sync_with_stdio(false);

using namespace std;


//每一步只能把0移动到上方、左上方、下方、右下方
struct State {
int curmp[7][7];
int step,posi,posj;
bool froms;
unsigned long long hs;
};
int dy[]={0,0,-1,1};
int dx[]={-1,1,-1,1};
map<unsigned long long ,int>stst[2];
int DoubleBFS(State sst,State edd)
{
    queue<State>que;
    que.push(sst);
    que.push(edd);
    stst[0][edd.hs]=edd.step;
    stst[1][sst.hs]=sst.step;
    while(!que.empty())
    {
        State head=que.front();
        que.pop();
        if(stst[!head.froms].count(head.hs))
        {
            int stepp=stst[!head.froms][head.hs];
            if(head.step+stepp<=20)
                return stepp+head.step;
        }
        if(head.step>=10)
            continue;
        State ns;
        for(int t=0;t<4;t++)
        {
            ns=head;
            ns.posi=head.posi+dx[t];
            ns.posj=head.posj+dy[t];
            if(ns.posi<0||ns.posi>=6||ns.posj>ns.posi||ns.posj<0)
                continue;
            swap(ns.curmp[head.posi][head.posj],ns.curmp[ns.posi][ns.posj]);
            ns.hs=0;
            for(int i=0;i<6;i++)
                for(int j=0;j<=i;j++)
                ns.hs=ns.hs*6+ns.curmp[i][j];
            ns.step++;
            if(stst[ns.froms].count(ns.hs)==0)
            {
                stst[ns.froms][ns.hs]=ns.step;
                que.push(ns);
            }
        }
    }
    return -1;
}
int main()
{
    int T;
    scanf("%d",&T);
    State ed;
    ed.hs=0;
    ed.posi=ed.posj=0;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<=i;j++)
        {
            ed.curmp[i][j]=i;
            ed.hs=ed.hs*6+i;
        }
    }
    ed.froms=false;
    ed.step=0;
    while(T--)
    {
        stst[0].clear();
        stst[1].clear();
        State start;
        start.froms=true;
        start.step=0;
        start.hs=0;
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<=i;j++)
            {
                scanf("%d",&start.curmp[i][j]);
                start.hs=start.hs*6+start.curmp[i][j];
                if(start.curmp[i][j]==0)
                {
                    start.posi=i;
                    start.posj=j;
                }
            }
        }
        int ans=DoubleBFS(start,ed);
        if(ans==-1)
            printf("too difficult\n");
        else printf("%d\n",ans);
    }
    return 0;
}

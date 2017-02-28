#include <bits/stdc++.h>
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
#define ll long long
#define LL long long
#define inf 1000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

int mfindw[205];
int wmatchm[205];
struct P{
double x,y,z;
int contain;
};
struct Q{
int id;
double dist;
int contain;
};
int cmp(Q a,Q b)
{
    if(fabs(a.dist-b.dist)<1e-10)
        return a.contain>b.contain;
    return a.dist<b.dist;
}
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        P man[205];
        P woman[205];
        int n;
        scanf("%d",&n);
        memset(wmatchm,0,sizeof wmatchm);
        memset(mfindw,0,sizeof mfindw);
        for(int id=1;id<=n;id++)
            scanf("%d%d%lf%lf%lf",&id,&man[id].contain,&man[id].x,&man[id].y,&man[id].z);
        for(int id=1;id<=n;id++)
            scanf("%d%d%lf%lf%lf",&id,&woman[id].contain,&woman[id].x,&woman[id].y,&woman[id].z);
        vector<Q>mlikew[205],wlikem[205];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                Q q;
                //cout<<man[i].x<<" "<<man[i].y<<man[i].z<<endl;
                //cout<<woman[j].x<<" "<<woman[j].y<<" "<<woman[j].z<<endl;
                q.dist=sqrt((man[i].x-woman[j].x)*(man[i].x-woman[j].x)+(man[i].y-woman[j].y)*(man[i].y-woman[j].y)+(man[i].z-woman[j].z)*(man[i].z-woman[j].z));
               // cout<<i<<" "<<j<<" "<<q.dist<<endl;
                q.id=j;
                q.contain=woman[j].contain;
                mlikew[i].push_back(q);
                q.id=i;
                q.contain=man[i].contain;
                wlikem[j].push_back(q);
            }
        queue<int>que;
        for(int i=1;i<=n;i++)
        {
            sort(mlikew[i].begin(),mlikew[i].end(),cmp);
            sort(wlikem[i].begin(),wlikem[i].end(),cmp);
            que.push(i);
        }
        while(!que.empty())
        {
            int nan=que.front();
            que.pop();
            while(true){
            int nv=mlikew[nan][mfindw[nan]].id;
            if(wmatchm[nv]==0)
                {wmatchm[nv]=nan;break;}
            else {
                int nom_match_man= wmatchm[nv];
                bool change=false;
                for(int i=0;i<n;i++)
                {
                    if(wlikem[nv][i].id==nom_match_man)
                        break;
                    if(wlikem[nv][i].id==nan)
                    {
                        change=true;break;
                    }
                }
                if(change)
                {
                    wmatchm[nv]=nan;que.push(nom_match_man);
                    break;
                }else {
                    mfindw[nan]++;
                    continue;
                }
            }
            }
        }
        for(int i=1;i<=n;i++)
            printf("%d %d\n",wmatchm[i],i);
       
    }

    return 0;
}

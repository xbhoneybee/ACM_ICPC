//#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<map>
#define ll long long
#define LL long long
#define inf 1000000000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

//uva  540
int main()
{
    //freopen("output.txt","w",stdout);
    int id=1,n;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        printf("Scenario #%d\n",id++);
        vector <int>vec[1001];
        queue<int>que;
        queue<int>q[1001];
        int inqueue[1001]={0};
        for(int i=0;i<n;i++)
        {
            int x,inn;
            scanf("%d",&x);
            for(int j=0;j<x;j++)
            {
            scanf("%d",&inn);
            vec[i].push_back(inn);
            }
            sort(vec[i].begin(),vec[i].end());
        }
        char cmd[10];
        int num;
        while(scanf("%s",cmd))
        {
            if(cmd[0]=='S')
                {
                    printf("\n");
                    break;
                }
            if(cmd[0]=='E')
            {
                scanf("%d",&num);
                int queid=0;
                for(int i=0;i<n;i++)
                {
                    int p=lower_bound(vec[i].begin(),vec[i].end(),num)-vec[i].begin();
                    if(p>=0&&p<vec[i].size()&&vec[i][p]==num)//p µÄ·¶Î§,detail
                    {
                        queid=i;break;
                    }
                }
                if(inqueue[queid]==1)
                {
                    q[queid].push(num);
                }else{
                    inqueue[queid]=1;
                    que.push(queid);
                    q[queid].push(num);
                }
            }
            else
            {
                int qid=que.front();
                int numout=q[qid].front();
                printf("%d\n",numout);
                q[qid].pop();
                if(q[qid].empty())
                {
                    que.pop();
                    inqueue[qid]=0;
                }
            }
        }
    }
    return 0;
}

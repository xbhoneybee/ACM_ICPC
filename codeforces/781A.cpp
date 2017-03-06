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
#include<ivector>
#include<map>
#include<sstream>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x

using namespace std;


int n;
vector<int>mp[200005];
int color[200005];
int father[200005];
int solve()
{
    queue<int>que;
    int ret=0;
    int cl=1;
    color[1]=cl++;
    int len=mp[1].size();
    for(int i=0;i<len;i++)
    {
        if(mp[mp[1][i]].size()>1)
        {que.push(mp[1][i]);father[mp[1][i]]=1;}
        color[mp[1][i]]=cl++;
    }
    ret=cl-1;
    while(!que.empty())
    {
        int cur=que.front();
        que.pop();
        int k=1;
        len=mp[cur].size();
        for(int i=0;i<len;i++)
        {
            if(color[mp[cur][i]]!=0)
                ;
            else{
                father[mp[cur][i]]=cur;
                if(mp[mp[cur][i]].size()>1)
                que.push(mp[cur][i]);
                while(k==color[cur]||k==color[father[cur]])//每次使用颜色不要和本身和父节点相同即可
                    k++;
                color[mp[cur][i]]=k;
                ret=max(ret,k);
                k++;//下次直接使用此color
            }
        }
    }
    return ret;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    int ans=solve();
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
        printf("%d ",color[i]);
    printf("\n");
    return 0;
}

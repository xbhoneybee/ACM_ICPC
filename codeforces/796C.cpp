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
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x

using namespace std;

//C
int n;
vector<int> G[300005];
int strength[300005];
multiset<int,greater<int> >st;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        {
            scanf("%d",&strength[i]);
            st.insert(strength[i]+2);
        }
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans=2000000000;
    for(int i=1;i<=n;i++)
    {
        int cur_max=-1000000009;
        st.erase(st.find(strength[i]+2));
        cur_max=max(cur_max,strength[i]);
        for(int j=0;j<G[i].size();j++)
        {
            int to=G[i][j];
            st.erase(st.find(strength[to]+2));
            cur_max=max(cur_max,strength[to]+1);
        }
        if(!st.empty())
            cur_max=max(cur_max,*st.begin());
        ans=min(ans,cur_max);
        st.insert(strength[i]+2);
        for(int j=0;j<G[i].size();j++)
        {
            int to=G[i][j];
            st.insert(strength[to]+2);
        }
    }
    printf("%d\n",ans);
    return 0;
}
//多点删除插入就会TLE

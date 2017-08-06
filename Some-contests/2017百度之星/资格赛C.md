### 完全背包变形
思路，写出dp分别对每个怪dp，复杂度1e5* 1e3 * 1e3 TLE

由于n=1E5>1e3*10明显有重复，遂打表复杂度1e3 * 10 * 1e3 * 1e3 TLE

换种dp思路 复杂度再降1e3*10*1e3 AC

```

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
#define lowbit(x) x&-x

using namespace std;



int n,m;
int a[100005],b[100005],k[1010],p[1010];
int ansrec[1010][11];//表示血量i,防御j 的怪物需要的最少魔力
int  main()
{
    iosfalse
    while(scanf("%d %d",&n,&m)!=EOF)
    {
    for(int i=0;i<n;i++)
        scanf("%d %d",&a[i],&b[i]);
    for(int i=0;i<m;i++)
        scanf("%d %d",&k[i],&p[i]);
    for(int HP=0;HP<=1000;HP++)
    {
        for(int B=0;B<=10;B++)
        {
            if(HP==0)
            {
                ansrec[HP][B]=0;
                continue;
            }else ansrec[HP][B]=1e9;
            for(int sk=0;sk<m;sk++)
            {
            if(p[sk]<=B)
                continue;
            ansrec[HP][B]=min(ansrec[HP][B],ansrec[max(HP-(p[sk]-B),0)][B]+k[sk]);
            }
        }
    }
    long long ans=0;
    bool killed=true;
    for(int mons=0;mons<n;mons++)
        {
            ans+=ansrec[a[mons]][b[mons]];
            if(ansrec[a[mons]][b[mons]]==1e9)
            {
                killed=false;
                break;
            }
        }
        if(killed==false)
            ans=-1;
        printf("%lld\n",ans);
    }
    return 0;
}
```

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

/**
思维题：这种题我们充分体现了组队的好处，大家各开脑洞找博弈的规律。
最后可以发现Ailce先走Bob后走，Bob想赢必须走Alice旁边将Alice走过的白色覆盖成黑色。
因此Alice可以倒逼Bob跟着他走。Bob必须能将图分成2个点单独连一起的连通块才能赢。于是又一次在
树上找最大匹配数
*/
int pip;
vector<int>son[505];
bool dfs(int rt)
{
    bool isnpp=false;
    for(int i=0;i<son[rt].size();i++)
    {
        if(dfs(son[rt][i]))
        {
            isnpp=true;
        }
    }
    if(isnpp==true)
    {
        pip++;
        return false;
    }
    return true;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        for(int i=0;i<=n;i++)
            son[i].clear();
        pip=0;
        for(int i=2;i<=n;i++)
        {
            int f;
            scanf("%d",&f);
            son[f].push_back(i);
        }
        dfs(1);
        if(n&1){
            printf("Alice\n");
        }else {
            if(pip*2==n&&pip-1<=k)
                printf("Bob\n");
            else printf("Alice\n");
        }
    }
    return 0;
}

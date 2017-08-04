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
/**
由于给出的区间是一个1-n置换
思路对于每一个i，要找到他前面k个大的，要找到后面k个大的。这样，i就是这些区间中第k大的（其实就是最小的）。
但是这种操作你需要枚举每一个数。复杂度为On。这样就不行，然后骚操作来了。
对于每一个数，记录比要查的数大的前一个位置，记录比要查的数大的数后一个位置，这样每次最多跳k次，这样复杂度就够了。
然后这就是链表，然后就是用数组来模拟链表。
pre表示上一个位置，nextp表示下一个位置。先算小的，算完后删掉，这样就不会影响到大的了。更新pre和nextp。
*/
int n,k;
int pos[500005];//pos[i],表示i在数组a[]中的位置。
int nextp[500005],pre[500005];//p..[i],n..[i]分别表示比i大的数的前一个位置和后一个位置(因为i从小开始枚举，用完删除，所以链表内都是比其大的)。
int ppre[100],nnt[100];
long long ans;
void init()
{
    for(int i=0;i<=n+1;i++)
    {
        nextp[i]=i+1;
        pre[i]=i-1;
    }
}
void del(int x)
{
    int nx=nextp[x];
    int pr=pre[x];
    nextp[pr]=nx;
    pre[nx]=pr;
}

void solve()
{
    for(int i=1;i<=n;i++)
    {
        int L,R,p;
        for(L=0,p=pos[i];L<=k&&p>=1;p=pre[p])
            ppre[++L]=p-pre[p];
        for(R=0,p=pos[i];R<=k&&p<=n;p=nextp[p])
            nnt[++R]=nextp[p]-p;
        for(int num_left=1;num_left<=L;num_left++)
        {
            //当左边num_left个比i大，右边要有k-num_left-1个比i大，这样保证i为第k大，为了计算这样区间的个数，左右各+1
            if(k-num_left+1>R)
                continue;//不够
            ans+=1LL*i*(ppre[num_left])*(nnt[k-num_left+1]);
        }
        del(pos[i]);
    }
    printf("%I64d\n",ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            pos[tmp]=i;
        }
        ans=0;
        init();
        solve();
    }
    return 0;
}

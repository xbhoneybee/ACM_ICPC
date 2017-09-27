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
#define iosfalse ios::snync_with_stdio(false);

using namespace std;



int a[(1<<17)+50];
int maxv[1<<20];
int minv[1<<20];
inline void build(int L,int R,int rt)
{
    if(L==R)
    {
        maxv[rt]=minv[rt]=a[L];
        return ;
    }
    int M=(L+R)/2;
    build(L,M,rt<<1);
    build(M+1,R,rt<<1|1);
    maxv[rt]=max(maxv[rt<<1],maxv[rt<<1|1]);
    minv[rt]=min(minv[rt<<1],minv[rt<<1|1]);
}
//修改A[p] = v
inline void update(int rt, int L, int R, int p, int v)
{
	int M = L + ((R - L) >> 1);
	if (L == R) maxv[rt]=minv[rt] = v; // 叶结点，直接更新
	else {
		// 先递归更新左子树或右子树
		if(p <= M) update(rt<<1, L, M, p, v);
		else update(rt<<1|1, M+1, R, p, v);
		// 然后计算本结点的minv
		minv[rt] = min(minv[rt<<1], minv[rt<<1|1]);
		maxv[rt]=max(maxv[rt<<1],maxv[rt<<1|1]);
	}
}
inline pair<int,int> query(int o, int L, int R, int qL, int qR)
{
	int M = L + ((R - L) >> 1);
	pair<int,int>ans;
	ans.first=-(1<<20);
	ans.second=1<<20;
	if (qL <= L && R <= qR) return make_pair(maxv[o],minv[o]); // 当前结点完全包含在查询区间内
	if (qL <= M) {
        pair<int,int>ansl;
        ansl=query(o<<1, L, M, qL, qR);// 往左走
        ans.first=max(ans.first,ansl.first);
        ans.second=min(ans.second,ansl.second);
	}
	if (M < qR) {
        pair<int,int>ansr;
        ansr=query(o<<1|1, M+1, R, qL, qR);// 往右走
        ans.first=max(ans.first,ansr.first);
        ans.second=min(ans.second,ansr.second);
	}
	return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int k;
        scanf("%d",&k);
        int n=1<<k;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        build(1,n,1);
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            int cmd,l,r;
            scanf("%d %d %d",&cmd,&l,&r);
            if(cmd==1)
            {
                l++;r++;
                //query(l,r)min
                pair<int,int>ppap;
                ppap=query(1,1,n,l,r);
                if(ppap.first<=0)
                    printf("%lld\n",ppap.first*1LL*ppap.first);
                else if(ppap.second>=0)
                    printf("%lld\n",ppap.second*1LL*ppap.second);
                else printf("%lld\n",ppap.second*1LL*ppap.first);
            }else {
                l++;
            //update al=r;
            update(1,1,n,l,r);
            }
        }
    }
    return 0;
}

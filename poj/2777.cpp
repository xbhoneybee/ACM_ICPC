#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<stdlib.h>
#include <sstream>
#include <deque>
#include<list>
#include<time.h>
#define ll long long
#define LL long long
#define inf 1e18
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

//线段树+位运算
//不要在query中输出
const int MXN = 100000 + 10;
int color=0;
struct SEG {
	int l, r, m, lazy;//m位运算存颜色数
	SEG( int _l=0 , int _r =0 )
	{l = _l, r = _r;m=1;lazy=0;}
} SGT[MXN << 2 | 1];
void fresh( SEG &T, SEG &L, SEG &R ) {
    //合并区间操作
    T.m=L.m|R.m;
}
void build( int id, int l, int r ) {//对结点id进行建立，区间为l~r
	SGT[id].l=l;
	SGT[id].lazy=0;
	SGT[id].m=1;
	SGT[id].r=r;
	int mid = ( l + r ) / 2;
	if ( l != r ) {
		build( id <<1, l, mid );
		build( id <<1| 1, mid + 1, r );
	} else return ;
}
void update( int id, int l, int r, int w ) {//根id 在区间l~r上更新m的状态w
	SEG &T = SGT[id];
	int mid = ( T.l +T.r ) / 2;
	if ( T.l == l && T.r == r ) {//如果找到区间l~r 则修改m
		T.m=1<<(w-1);
		T.lazy=1;
		return;
	}
	if ( T.lazy ==1) {
        SGT[(id<<1)].lazy=1;
        SGT[(id<<1|1)].lazy=1;
        SGT[(id<<1)].m=T.m;
        SGT[id<<1|1].m=T.m;
		T.lazy = 0;
	}
	if ( r <= mid )update( id << 1, l, r, w );//只对左儿子更新
	else if ( l > mid )update( id << 1 | 1, l, r, w );//只对右儿子更新
	else {
		update( id << 1, l, mid, w );//区间横跨左右儿子区间，对其两者均进行更新
		update( id << 1 | 1, mid + 1, r, w );//区间横跨左右儿子区间，对其两者均进行更新
	}
	fresh( T, SGT[id << 1], SGT[id << 1 | 1] );//合并区间
}
void query( int id, SEG  A ) {
	if ( SGT[id].lazy ||(SGT[id].l == A.l && SGT[id].r == A.r)) {
		color|=SGT[id].m;
		return ;
	}
	int mid = ( SGT[id].l + SGT[id].r ) / 2;
	if ( A.r <= mid )query( id << 1, A );
	else if ( A.l > mid )query( id << 1 | 1, A );
	else {
		SEG L( A.l, mid ), R( mid + 1, A.r );
		query( id << 1, L );
		query( id << 1 | 1, R );
	}
}
int main()
{
    iosfalse;//数据量大，不开就TLE
    int L,T,O;
    cin>>L>>T>>O;
    build(1,1,L);
    for(int i=0;i<O;i++)
    {
        char opt;
        cin>>opt;
        if(opt=='C')
        {
            int l,r,col;
            cin>>l>>r>>col;
            if(l>r)
                swap(l,r);
            update(1,l,r,col);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            if(l>r)
            swap(l,r);
            color=0;
            SEG ans;
            ans.l=l,ans.r=r;
            query(1,ans);
            int answer=0;
            for(int i=0;i<T;i++)
            {
            if(color&(1<<i))
                    answer++;
            }
            printf("%d\n",answer);
            //__builtin_popcount(color)
        }
    }
    return 0;
}

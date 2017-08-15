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

const int maxn=30044;
int a[maxn],b[maxn];
int pos[maxn];
int ans[200005];
int c[maxn];
int n;
void add(int i,int val)//将第i个元素增加val注意i不可为零
 {
    while(i<=n)//n为所开数组上界
    {
        c[i]+=val;
        i+=lowbit(i);
    }
 }
int sum(int i)//求前i项和
{
    int s=0;
    while(i>0)
    {
        s+=c[i];
        i-=lowbit(i);
    }
    return s;
}
struct QJ
{
    int l,r,id;
    QJ (int L,int R,int I){
    l=L;r=R;id=I;
    }
};
bool cmp(QJ a,QJ b)
{
    if(a.r!=b.r)
        return a.r<b.r;
    return a.l>b.l;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
    memset(c,0,sizeof c);
    for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
    sort(a+1,a+n+1);
    int size=unique(a+1,a+n+1)-a-1; //size为离散化后元素个数
    for(int i=1;i<=n;i++)
    b[i]=lower_bound(a+1,a+size+1,b[i])-a ;//b[i]为经离散化后对应的
    int q;
    scanf("%d",&q);
    vector<QJ>vec;
    for(int i=1;i<=q;i++)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        vec.push_back(QJ(l,r,i));
    }
    memset(pos,-1,sizeof pos);
    sort(vec.begin(),vec.end(),cmp);
    int lef=1;
    for(int qj=0;qj<vec.size();qj++)
    {
        for(int i=lef;i<=vec[qj].r;i++)
        {
            if(pos[b[i]]!=-1)
            {
                add(pos[b[i]],-1);
            }
            pos[b[i]]=i;
            add(i,1);
        }
        lef=vec[qj].r+1;
        ans[vec[qj].id]=sum(vec[qj].r)-sum(vec[qj].l-1);
    }
    for(int i=1;i<=q;i++)
        printf("%d\n",ans[i]);
    }
    return 0;
}

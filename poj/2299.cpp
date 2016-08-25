#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string.h>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#define inf 1000000000000000000
#define ll long long
#define mod 1000000007
#define iosfalse ios::sync_with_stdio(false);
using namespace std;
const int MAXN=1024;


//树状数组+离散化  
//每读入一个数就更新树状数组，查看它前面比它小的已出现过的有多少个数sum，
//然后用当前位置减去该sum，就可以得到当前数导致的逆序对数了
//把所有的加起来就是总的逆序对数。
//val数据范围较大 离散化处理
//val存放原数组的元素，pos存放原始位置，即node[i].pos = i。
//把这些结构体按照val的大小排序。
//reflect数组存放离散化后的值，即reflect[node[i].pos] = i。
int n;
struct Node{
int pos;
ll val;
}node[500005];
ll tree[500005];//Cn = A(n – 2^k + 1) + ... + An
int lowbit(int x)
{
    return x&-x;
}
void add(int k,int num)
{
    while(k<=n)
    {
        tree[k]+=num;
        k+= k&-k;
    }
}
bool cmp(const Node& a, const Node& b)
{
    return a.val < b.val;
}
void update(int x)//update tree x
{
    while(x<=n)
    {
        tree[x]+=1;
        x+=lowbit(x);
    }
}
int getsum (int k)
{
    int sum=0;
    while(k)
    {
        sum+=tree[k];
        k-=k&-k;
    }
    return sum;
}
ll reflect[500005];
int main()
{
    while(cin>>n&&n){
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&node[i].val);
        node[i].pos=i;
    }
    ll  ans=0;
    sort(node+1,node+n+1,cmp);
    for(int i=1;i<=n;i++)
        reflect[node[i].pos]=i;
    for(int i=1;i<=n;i++)
    {
        update(reflect[i]);
        ans+=i-getsum(reflect[i]);
    }
    cout<<ans<<endl;
    memset(tree,0,sizeof tree);
    }
    return 0;
}
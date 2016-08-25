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


//题意可以无限操作，相当于连通图，想到并查集
//用并查集分出可以交换位置的下标集合，然后用vector装每个集合的下标和元素，
//然后对每个集合的元素排序一下就好了。
vector<int> num[1000005];
vector<int> vid[1000005];
int a[1000005],ans[1000005];
int father[1000005];
int find(int x)   
{
    if(x==father[x]) return x;
    return father[x]=find(father[x]);
}
void join(int x,int y)
{
    x=find(x);y=find(y);
    if(x==y) return ;
    father[x]=y;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) //注意交换（a,b）的次序从1开始，所以i=1开始
    {
        father[i]=i;
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        join(a,b);
    }
    for(int i=1;i<=n;i++)
    {
        int x=find(i); //wa点 find是用来查位置的连通不用查a[i]
        num[x].push_back(a[i]);
        vid[x].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        sort(num[i].begin(),num[i].end(),greater<int>());//降序
        for(int j=0;j<vid[i].size();j++)
        ans[vid[i][j]]=num[i][j];
    }
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}
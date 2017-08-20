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
注意c++ ac G++ TLE 输入有坑 花式多组数据
*/

int n;
int numson[2000005];
int parent[200005];
int ranks[200005];
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        numson[i]=1;
        parent[i]=i;
        ranks[i]=0;   // 初始树的高度为0
    }
}
int Find(int x)
{
    int k, j, r;
    r = x;
    while(r != parent[r])     //查找跟节点
        r = parent[r];      //找到跟节点，用r记录下
    k = x;
    while(k != r)             //非递归路径压缩操作
    {
        j = parent[k];         //用j暂存parent[k]的父节点
        parent[k] = r;        //parent[x]指向跟节点
        k = j;                    //k移到父节点
    }
    return r;         //返回根节点的值
}

// 合并x和y所属的集合
void Unite(int x,int y)
{
    x=Find(x);
    y=Find(y);
    if(x==y) {
        printf("%d\n",numson[x]);
        return ;
    }
    if(ranks[x]<ranks[y])
        {
            parent[x]=y;
            numson[y]+=numson[x];
            numson[x]=0;
            printf("%d\n",numson[y]);
        }// 合并是从ranks小的向ranks大的连边
    else
    {
        parent[y]=x;
        numson[x]+=numson[y];
        printf("%d\n",numson[x]);
        numson[y]=0;
        if(ranks[x]==ranks[y]) ranks[x]++;
    }
}
int main()
{
    iosfalse
    int T;
    while(scanf("%d",&T)!=EOF){//花式多组数据
    while(T--)
    {
        scanf("%d",&n);
        init(2*n+3);
        map<string,int>mp;
        int cnt=1;
        for(int i=1;i<=n;i++)
        {
            string str1,str2;
            cin>>str1>>str2;
            int nid1,nid2;
            nid1=mp[str1];
            if(nid1==0)
            {
                nid1=cnt;
                mp[str1]=cnt++;
            }
            nid2=mp[str2];
            if(nid2==0)
            {
                nid2=cnt;
                mp[str2]=cnt++;
            }
            Unite(nid1,nid2);
        }
    }
    }
    return 0;
}

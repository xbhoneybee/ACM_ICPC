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
单纯计算入度，无法处理环
求出强连通分量，对每个强连通分量求入度，入度为0，ans++;
注意输入坑
*/
const int  Maxv =100005;              //题目中可能的最大点数
int STACK[Maxv],top=0;          //Tarjan 算法中的栈
bool InStack[Maxv];             //检查是否在栈中
int DFN[Maxv];                  //深度优先搜索访问次序
int Low[Maxv];                  //能追溯到的最早的次序
int ComponetNumber;        //有向图强连通分量个数
int Index,ans;                 //索引号
vector <int> Edge[Maxv];        //邻接表表示
int belong[Maxv];
int indegree[Maxv];
void Tarjan(int i)
{
    int j;
    DFN[i]=Low[i]=Index++;
    InStack[i]=true;
    STACK[++top]=i;
    for (int e=0;e<Edge[i].size();e++)
    {
        j=Edge[i][e];
        if (DFN[j]==-1)
        {
            Tarjan(j);
            //父节点是子节点的子节点则改变
            Low[i]=min(Low[i],Low[j]);
        }
        else if (InStack[j])
            Low[i]=min(Low[i],DFN[j]);
    }
    if (DFN[i]==Low[i])
    {
        ComponetNumber++;
        do
        {
            j=STACK[top--];
            InStack[j]=false;
            belong[j]=ComponetNumber;
        }
        while (j!=i);
    }
}

void solve(int n)     //此图中点的个数，注意是[0-indexed)！
{
    memset(STACK,-1,sizeof(STACK));
    memset(InStack,0,sizeof(InStack));
    memset(DFN,-1,sizeof(DFN));
    memset(Low,-1,sizeof(Low));
    memset(belong,0,sizeof belong);
    top=0;
    for(int i=0;i<n;i++)
        if(DFN[i]==-1)
            Tarjan(i);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<Edge[i].size();j++)
        {
            if(belong[i]!=belong[Edge[i][j]])
                indegree[belong[Edge[i][j]]]++;
        }
    }
    for(int i=1;i<=ComponetNumber;i++)
    {
        if(indegree[i]==0)
            ans++;
    }
}
int main()
{
    int T;
    while(scanf("%d",&T)!=EOF){
    while(T--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        memset(indegree,0,sizeof indegree);
        for(int i=0;i<=n;i++)
            {
                Edge[i].clear();
            }
        Index=0;
        ComponetNumber=0;
        ans=0;
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            Edge[x-1].push_back(y-1);
        }
        solve(n);
        printf("%d\n",ans);
    }
    }
    return 0;
}

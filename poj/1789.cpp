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
#define mod 1000000007
#define ll long long
#define LL long long
#define inf 100000000
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

#define maxn 2010
#define INF 1000    //预定于的最大值
int n;   //顶点数、边数
int g[maxn][maxn];      //邻接矩阵表示
char truck[2010][9];
struct node     //保存key值的结点
{
    int v;
    int key;
    friend bool operator<(node a, node b)   //自定义优先级，key小的优先
    {
        return a.key > b.key;
    }
};
node vx[maxn];      //保存每个结点与其父节点连接边的权值
int parent[maxn];   //每个结点的父节点
bool visited[maxn]; //是否已经加入树种
void Prim()    //s表示根结点
{

    priority_queue<node> q; //优先队列stl实现
    for(int i = 1; i <= n; i++) //初始化
    {
        vx[i].v = i;
        vx[i].key = INF;
        parent[i] = -1;
        visited[i] = false;
    }
    vx[1].key = 0;
    q.push(vx[1]);
    while(!q.empty())
    {
        node nd = q.top();  //取队首，记得赶紧pop掉
        q.pop();
        if(visited[nd.v] == true)   //深意，因为push机器的可能是重复但是权值不同的点，我们只取最小的
            continue;
        int st = nd.v;
        //cout << nd.v << " " << nd.key << endl;
        visited[nd.v] = true;
        for(int j = 1;  j <= n; j++)
        {
            if(j!=st && !visited[j] && g[st][j] < vx[j].key)    //判断
            {
                parent[j] = st;
                vx[j].key = g[st][j];
                q.push(vx[j]);

            }
        }
    }
}
int main()
{
    while(~scanf("%d",&n)&&n)
    {for(int i=1;i<=n;i++)
        scanf("%s",truck[i]);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
    {
        int tdis=0;
        for(int k=0;k<7;k++)
        {
            if(truck[i][k]!=truck[j][k])
                tdis++;
        }
       g[i][j]=g[j][i]=tdis; //2个
    }
    Prim();
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=vx[i].key;
    printf("The highest possible quality is 1/%d.\n",ans);
    }
    return 0;
}

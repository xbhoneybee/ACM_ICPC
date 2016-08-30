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
#include<deque> //双端队列
#define mod 1000000007
#define ll long long
#define LL long long
#define inf 10000000000000
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

const int maxv=550;
const int maxe=6000;
const int INF=0x3f3f3f3f;
int n,m,k;
struct Edge
{
    int v;
    int wight;
    int next;
}e[maxe];
int head[maxv]; //头结点
int dist[maxv];
int flag[maxv];
int cnt[maxv];
int idx;
void Init() //初始化的操作也是很必须的! 而且一起封装起来也是很不错的选择,以后,初始化的工作还是放在Init()
{           //里面完成吧,看着封装性很好!
    memset(head, -1, sizeof(head));
    memset(flag,0,sizeof flag);
    memset(cnt,0,sizeof cnt);
    idx = 0;
}
void Addedge(int a, int b, int value) //分别为起点a,终点b,以及边的权值value
{
     e[idx].wight = value;
     e[idx].v = b;
     e[idx].next = head[a];
     head[a] = idx++;  //head [a]的值表示以a为起点的某条边的数组下标，若其next！=-1 则next 为以a为起点的另一条边的数组下标
}
bool spfa(const int beg)
{
    const int NODE=n;
    for(int i=1;i<=n;i++) dist[i]=INF;
    dist[beg]=0;
    queue <int > que;
    que.push(beg);
    dist[beg]=0;//出发点到自身路径长度为0
    ++cnt[beg];//开始计数
    flag[beg]=1;//入队
    while(!que.empty())
    {
        const int now=que.front();//当前处理的点，由于后面被删除，不可定义成常量引用
        que.pop();
        flag[now]=0;//将该点拿出队列
        for(int i=head[now]; i!=-1;i=e[i].next)//遍历所有与当前点有路径的点
        {
            int v=e[i].v;
            if(dist[v]>dist[now]+e[i].wight)//不满足三角不等式
            {
                dist[v]=dist[now]+e[i].wight;//更新
                if(!flag[v])//若未在处理队列中
                {
                    if(++cnt[v]>=NODE)return 1;//计数后出现负权回路
                    que.push(v);
                    flag[v]=1;//入队
                }
            }
        }
    }
    return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    cin>>n>>m>>k;
    int a,b,l;
    Init();
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>l;
        Addedge(a,b,l);
        Addedge(b,a,l);
    }
    for(int i=0;i<k;i++)
    {
        cin>>a>>b>>l;
        Addedge(a,b,-l);
    }
    if(spfa(1))
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    }
    return 0;
}

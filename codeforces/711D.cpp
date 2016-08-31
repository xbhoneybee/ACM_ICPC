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
#define INF 1e18
using namespace std;
// 求一个图 对每条边赋方向后边 形成一个无环图的方法总数
//注意这个图的特殊性在于每个点只向另一点引出一条边 所以不会有环共用边；而且如果无向图有环，则原图给出的方向一定有环。
//思路 一个图由链和环组成  由链组成的边怎么赋方向都不会成环 有2^n种，由环组成的边 有2^n-2种方法 相乘即可。
const int maxv=200005;
int to[maxv],id[maxv],tim[maxv],T,sum;
vector<int> vec;//记录每个环的节点数
void dfs(int i,int t)
{
    id[i]=t;//标记每次dfs内部调用dfs的 次序  用于求边数
    tim[i]=T;//标记是第几次的在主函数调用dfs 同一个环上tim相同
    if(id[to[i]]!=-1&&tim[to[i]]==T) //找到环
    {
        vec.push_back(-id[to[i]]+id[i]+1);
        sum+=-id[to[i]]+id[i]+1;
    }
    else if(id[to[i]]==-1)
    {
        dfs(to[i],t+1);
    }
}
ll PowerMod(ll a, ll b, ll c)
{
    ll ans = 1;
    a = a % c;
    while(b>0)
    {
    if(b % 2 == 1)
    ans = (ans * a) % c;
    b = b/2;
    a = (a * a) % c;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>to[i];
    }
    memset(id,-1,sizeof id);
    for(int i=1;i<=n;i++)
    if(id[i]==-1)
    {
        ++T;
        dfs(i,1);
    }
    ll ans=1;
    for(int i=0;i<vec.size();i++)
        ans=(ans*(PowerMod(2,vec.at(i),mod)-2))%mod;
    ans=(ans*PowerMod(2,n-sum,mod))%mod;
    cout<<ans<<endl;

    return 0;
}

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



using namespace std;

const int MAXN=1010;
const int inf=0x3f3f3f3f;
int dist[MAXN]; //**dist[i]记录此时源点到i的最短距离
bool vis[MAXN]; //***标记点是否在队列中
int cnt[MAXN]; //***cnt[i]记录i节点入队次数，判断是否存在负权环
vector<pair<int, int> >mp[MAXN*100], mp2[MAXN*100];//mp储存原图，mp2存储反向图
struct node{
    int point;
    int g, f;
    friend bool operator<(node a, node b){
        return a.f==b.f?a.g>b.g:a.f>b.f;
    }
};
int A_star(int s, int e, int n, int k){
    priority_queue<node> q;
    int cnt=0;//***当前为第cnt短路
    if(s==e){//**本题题要求一定要经过其他点，即若终点和起点相同的话即为求第k+1短路
        k++;
    }
    if(dist[s]==inf){//***终点点不可达
        return -1;
    }
    node node1;
    node1.point=s;
    node1.g=0;
    node1.f=dist[s]+node1.g;
    q.push(node1);

    while(!q.empty()){
        node cc=q.top(); //***将估价值最小的节点出队
        q.pop();
        if(cc.point==e){//**求出第cnt短路
            cnt++;
        }
        if(cnt==k){//***已求出第k短路
            return cc.g;
        }
        for(int i=0; i<mp[cc.point].size(); i++){//**遍历当前节点的所有邻节点
            node node2;
            node2.point=mp[cc.point][i].first;
            node2.g=cc.g+mp[cc.point][i].second;
            node2.f=node2.g+dist[node2.point];
            q.push(node2);
        }
    }
    return -1;
}
bool spfa(int n, int s){ //**注意这里的n的实参是e，求出反向图中所有节点到n的最短距离，即所有节点到e的最短距离,即求出 h(x)
    memset(dist, 0x3f, sizeof(dist));
    queue<int> q;
    while(!q.empty()){
        q.pop();
    }
    q.push(s);
    dist[s]=0;
    cnt[s]+=1;
    vis[s]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=0; i<mp2[u].size(); i++){
            int point=mp2[u][i].first;
            if(dist[point]>dist[u]+mp2[u][i].second){ //**松驰操作
                dist[point]=dist[u]+mp2[u][i].second;
                if(!vis[point]){ //***若此点不在队列中则将其入队
                    vis[point]=true;
                    q.push(point);
                    cnt[point]++;
                    if(cnt[point]>n){ //***判断是否存在负权环
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
int main(void){
    int n, m;
    int x, y, z;
    cin >> n >> m;
    while(m--){
        cin >> x >> y >> z;
        mp[x].push_back(make_pair(y, z));
        mp2[y].push_back(make_pair(x, z)); //**建立反向图
    }
    int s, e, k;
    cin >> s >> e >> k;
    spfa(n, e);
    int res=A_star(s, e, n, k);
    cout << res << endl;
    return 0;
}

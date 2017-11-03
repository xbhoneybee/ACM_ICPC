#include <bits/stdc++.h>
#include<sstream>
#include<ctime>
#define iosfalse ios::sync_with_stdio(false);
using namespace std;


#define N 200005

#define lson rt << 1
#define rson rt << 1 | 1
#define Pair pair<long long, Node>
#define Sqrt2(x) (x) * (x)

int n, m, T, idx;

struct Node
{
    int id;
    int feature[3];     //定义属性数组
    bool operator < (const Node &u) const
    {
        return feature[idx] < u.feature[idx];
    }
}_data[N];   //_data[]数组代表输入的数据

//priority_queue<Pair> Q;     //队列Q用于存放离p最近的m个数据
Pair res;
class KDTree{

    public:
        void Build(int, int, int, int);     //建树
        void Query(Node, int, int);    //查询

    private:
        Node data[4 * N];    //data[]数组代表K-D树的所有节点数据
        int flag[4 * N];      //用于标记某个节点是否存在，1表示存在，-1表示不存在
}kd;

//建树步骤，参数dept代表树的深度
void KDTree::Build(int l, int r, int rt, int dept)
{
    if(l > r) return;
    flag[rt] = 1;                   //表示编号为rt的节点存在
    flag[lson] = flag[rson] = -1;   //当前节点的孩子暂时标记不存在
    idx = dept % 2;                 //按照编号为idx的属性进行划分
    int mid = (l + r) >> 1;
    nth_element(_data + l, _data + mid, _data + r + 1);   //nth_element()为STL中的函数
    data[rt] = _data[mid];
    Build(l, mid - 1, lson, dept + 1);  //递归左子树
    Build(mid + 1, r, rson, dept + 1);  //递归右子树
}

//查询函数，寻找离p最近的m个特征属性
void KDTree::Query(Node p, int rt, int dept)
{
    if(flag[rt] == -1) return;   //不存在的节点不遍历
    Pair cur(0, data[rt]);       //获取当前节点的数据和到p的距离
    for(int i = 0; i < 2; i++)
        cur.first += Sqrt2(cur.second.feature[i] - p.feature[i]+0LL);
    int dim = dept % 2;          //跟建树一样，这样能保证相同节点的dim值不变
    bool fg = 0;                 //用于标记是否需要遍历右子树
    int x = lson;
    int y = rson;
    if(p.feature[dim] >= data[rt].feature[dim]) //数据p的第dim个特征值大于等于当前的数据，则需要进入右子树
        swap(x, y);
    if(~flag[x]) Query(p, x, dept + 1);      //如果节点x存在，则进入子树继续遍历

    //以下是回溯过程，维护一个优先队列
    if(res.first==-1)   //如果队列没有满，则继续放入
    {
        if(cur.second.feature[2]<=p.feature[2])
        {
            res.first=cur.first;
            res.second=cur.second;
        }
        fg = 1;
    }
    else
    {
        if(((cur.first < res.first)||(cur.first==res.first&&cur.second.id<res.second.id))
           &&cur.second.feature[2]<=p.feature[2])  //如果找到更小的距离，则用于替换队列Q中最大的距离的数据
        {
            res.first=cur.first;
            res.second=cur.second;
        }
        if(Sqrt2(p.feature[dim] - data[rt].feature[dim]) < res.first)
        {
            fg = 1;
        }
    }
    if(~flag[y] && fg)
        Query(p, y, dept + 1);
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < 3; j++)
                    scanf("%d", &_data[i].feature[j]);
                _data[i].id=i;
            }
        kd.Build(0, n - 1, 1, 0);
        while(m--)
        {
            Node p;
            for(int i = 0; i < 3; i++)
                scanf("%d", &p.feature[i]);
            res.first=-1;
            kd.Query(p, 1, 0);
            printf("%d %d %d\n",res.second.feature[0],res.second.feature[1],
                   res.second.feature[2]);
        }
    }
    return 0;
}

#### 最大子段和
```
int maxlen=-1e8;
for(int i=1;i<n;i++)
{
    dp[i]=max(dp[i-1]+minuss[i],minuss[i]);
     maxlen=max(maxlen,dp[i]);
}
```
#### LIS最长上升子序列
#####    O n*logn

d[i]存长度为i的上升子序列的最小末元素    可以推出d[i]中的元素师按从小到大排列的

若d[i-1]比d[i]大，则上述中的长度为i-1的序列的末元素可以更新它
若当前元素最大，则长度增加
否则找到一个他可以更新的，更新之

**题意**：针脚之间有一些连线，有的交叉，现在不允许交叉，求最多能留下几根线
以某一边为序，求一个最长上升子序列的长度即可
```
    d[1]=a[1];
    int len=1,l,r,mid;
    for(int i=2;i<=n;i++)
    {
        if(d[len]<a[i])
            {
                d[++len]=a[i];
                continue;
            }
            l=1,r=len;
            while (l<=r)
            {
                mid=(l+(r-l)/2);
                if(d[mid]<a[i])
                    l=mid+1;
                else     r=mid-1;
            } 
            d[l]=a[i];
    }
    printf("%d\n",len);
```
#### 最大递增子段和
dp[i]=max(dp[j])+a[i];

dp[i]表示以i为结尾的最大子段和,满足 1<=j<i
#### 最小回文代价
对每个字母insert[],delete[i],求回文最小代价。

DAG图求最长路径
先拓扑排序，然后dp

### 最优矩阵链乘 (区间dp)
```
    for(int i=1;i<=n;i++)//第i个matrix的行列为a[i],a[i+1]
    {
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            dp[i][j]=1e9;
        }
    for(int len=2;len<=n-1;len++)//length
    {
        for(int i=1;i+len-1<n;i++)//start
        {
            for(int k=i;k<i+len-1;k++)
            {
                dp[i][i+len-1]=min(dp[i][k]+dp[k+1][i+len-1]+a[i]*a[k+1]*a[i+len],dp[i][i+len-1]);
            }
        }
    }

```
#### 区间dp减少时间复杂度
dp[i]表示以i结束的区间的最优值

接着for()一遍找到dp[i]中的最优值 可以将3维变2维for循环
### 三角剖分
注意如果中间三角形i-k-j中有其他的点,这样的三角形是不可以剖分的

三角形面积注意精度

fabs((x[k] - x[i]) * (y[j] - y[i]) - (x[j] - x[i]) * (y[k] - y[i])) / 2.0 ;

## 树上dp
树上动态规划常由儿子推老子，但写法上可以由老子找儿子常递归写法
### 树的最大独立集
```
//uva 1220
int n;
vector<int>son[201];
int f[210][2];
//dp[u][0]表示以u为root,不选u最多节点数 f[u][0]==1表示 解唯一
//dp[u][1] root u contain u的节点数  f[u][1]==1 表示 含u解唯一
int dp(int root,int have)
{
    if(son[root].size()==0)
    {
        f[root][have]=1;
        if(have==1)
            return 1;
        else return 0;
    }
    if(have==1)
    {
        int sum=0;
        f[root][1]=1;
        for(int i=0;i<son[root].size();i++)
            {
                sum+=dp(son[root][i],0);
                if(f[son[root][i]][0]==0)
                    f[root][1]=0;
            }
        return sum+1;
    }
    if(have==0)
    {
        int sum=0;
        f[root][0]=1;
        for(int i=0;i<son[root].size();i++)
            {
                int t0=dp(son[root][i],0);
                int t1=dp(son[root][i],1);
                sum+=max(t0,t1);
                if(t1==t0)
                    f[root][0]=0;
                if(t1<t0)
                {
                    if(f[son[root][i]][0]==0)
                        f[root][0]=0;
                }else{
                    if(f[son[root][i]][1]==0)
                        f[root][0]=0;
                }
            }
        return sum;
    }
}
```
### 树的重心

树的重心为 去掉此点后，树形成子树各个最多节点数最小
d(u) 表示以u为根的树含节点数
重心为 节点c 删除c后 最多节点数为max(d(son of c),n-d(c));
直接dfs一遍

### 树的最长路径

#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>
#include<string.h>
#include<set>
#include<queue>
#include<cctype>
#include<map>
#define inf 1000000000.000
#define ll long long
#define mod 1000000007//  这里不要写成100000000+7 define是替换！！！
using namespace std;

// DFS+剪枝

int cmp(int x,int y)
{
    return x>y;
}
int len[100];
bool used[100];
int n,lenth;
int dfs(int i,int l,int t)
//i为当前试取的棍子序号,l为要拼成一根完整的棍子还需要的长度,t初值为所有棍子总长度
{
    if(l==0)
    {
        t-=lenth;
    if(t==0) return 1;
    for( i=0;used[i];i++);
    //剪枝1：搜索下一根大棍子的时候，找到第一个还没有使用的小棍子开始
    used[i]=1;
    if(dfs(i+1,lenth-len[i],t))
        return 1;
    used[i]=0;//找不到,前一次匹配失败，返回上次值
    t+=lenth;
    }
    else{
        for(int j=i;j<n;j++)
        {
             if(j>0&&(len[j]==len[j-1]&&!used[j-1]))
            //剪枝2：前后两根长度相等时，如果前面那根没被使用，也就是由前面那根
            //开始搜索不到正确结果，那么再从这根开始也肯定搜索不出正确结果，此剪枝威力较大
                continue;
          if(!used[j]&&l>=len[j])
            //剪枝3：最简单的剪枝，要拼成一根大棍子还需要的长度L>=当前小棍子长度，才能选用
          {
              l-=len[j];
              used[j]=1;
              if(dfs(j,l,t))
                return 1;
              l+=len[j];//没找到返回上层
              used[j]=0;
              if(len[j]==l)
            //剪枝4：威力巨大的剪枝，程序要运行到此处说明往下的搜索失败，
            //若本次的小棍长度刚好填满剩下长度，但是后面的搜索失败，则应该返回上一层
                break;
          }
        }
    }
    return 0;
}
//将输入的输入从大到小排序，这么做是因为一支长度为 K
//的完整木棍，总比几支短的小木棍拼成的要好。
//形象一些：
//如果我要拼 2 支长为8的木棍，第一支木棍我拼成
// 5 + 3
//然后拼第二支木棍但是失败了，而我手中还有长为 2 和 1
//的木棍，我可以用 5 + 2 + 1 拼好第一支，再尝试拼第二
//支，仔细想一想，就会发现这样做没意义，注定要失败的。
//我们应该留下 2+1 因为 2+1 比 3 更灵活。
int main()
{
    while(cin>>n&&n){
    int suml=0;
    for(int i=0;i<n;i++)
    {
          cin>>len[i];
          suml+=len[i];
          used[i]=0;
    }
    sort(len,len+n,cmp);
    int flag=0;
    for(lenth=len[0];lenth<=suml/2;lenth++)
    //剪枝6：大棍长度一定是所有小棍长度之和的因数，且最小因数应该不小于小棍中最长的长度
    {
        if(suml%lenth==0){
            if(dfs(0,lenth,suml))
            {
            flag=1;
            cout<<lenth<<endl;
            break;
            }
        }
    }
    if(!flag)
        cout<<suml<<endl;
    }
    return 0;
}

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
//刘大爷解法1
int n;
int tot;
int node[110][110];
void dfs(int cur)
{
    if(cur==n) tot++;
    else for(int i=0;i<n;i++)
    {
        if(!node[0][i]&&!node[1][cur+i]&&!node[2][cur-i+n])
        {
            node[0][i]=node[1][cur+i]=node[2][cur-i+n]=1;
            dfs(cur+1);
            node[0][i]=node[1][cur+i]=node[2][cur-i+n]=0;
        }
    }
}
int main()
{
    int ans[11]={0};
    for(int i=0;i<11;i++)   //一直TLE
    {                       // 数据很大
         n=i;               //要预处理
         dfs(0);
         ans[i]=tot;
         tot=0;
    }
    while(scanf("%d",&n)!=EOF&&n)
    {
    cout<<ans[n]<<endl;
    }
    return 0;
}

//刘大爷解法2



int n;
int tot;
int C[11];
void  dfs(int cur)
{
    if(cur==n) tot++ ;
    else
    {
      for(int i=0;i<n;i++)
      {
          int flag=1;
          C[cur]=i;
          for(int j=0;j<cur;j++)
            if(C[cur]==C[j]||cur-C[cur]==j-C[j]||cur+C[cur]==j+C[j])
          {
              flag=0;
              break;
          }
          if(flag) dfs(cur+1);
      }
    }

}
int main()
{
    int ans[11]={0};
    for(int i=0;i<11;i++)   //一直TLE
    {                       // 数据很大
         n=i;               //要预处理
         dfs(0);
         ans[i]=tot;
         tot=0;
    }
    while(scanf("%d",&n)!=EOF&&n)
    {
    cout<<ans[n]<<endl;
    }
    return 0;
}
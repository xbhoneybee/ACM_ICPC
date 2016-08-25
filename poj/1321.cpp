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
//K<n时就让人有点迷糊不知怎样处理了

char pan[10][10];
int n,k,c;
int vistor[10];//列标记
void dfs(int cur,int num)
{
    if(num==k)
        {
            c++;
            return ;
        }

    if(cur>n) return;
    //配合下面DFS(row+1,num); 语句使用,避免搜索越界
    for(int i=0;i<n;i++)
    {
        if(pan[cur][i]=='#'&&vistor[i]==0)
            {
                vistor[i]=1;//放置棋子的列标记
                dfs(cur+1,num+1);
                vistor[i]=0;//回溯后，说明摆好棋子的状态已记录，当前的列标记还原
            }
    }
    dfs(cur+1,num);
    //这里是难点，当k<n时，row在等于n之前就可能已经把全部棋子放好
    //又由于当全部棋子都放好后的某个棋盘状态已经在前面循环时记录了
    //因此为了处理多余行，令当前位置先不放棋子，搜索在下一行放棋子的情况
}
int main()
{
    while(cin>>n>>k)
    {
        if(n==-1&&k==-1)
            return 0;
            getchar();
        memset(vistor,0,sizeof(vistor));
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                cin>>pan[i][j];
                getchar();
            }
        dfs(0,0);
        cout<<c<<endl;
        c=0;
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string.h>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include <sstream>
#define inf 100000000
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
using namespace std;
//C  dfs  写不出来QAQ
int n,m;
char a[1005][1005];
int used[1005][1005];
int ans[1005][1005];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
char name[10]="DIMA";
int dfs(int i,int j)
{
    if(ans[i][j]+1>0) return ans[i][j];
    if(used[i][j]&&a[i][j]=='D')  return inf;//表示infinite
    used[i][j]=1;
    int maxdfs=0;
    for(int idt=0;idt<4;idt++)
    {
        int temx=i+dx[idt];
        int temy=j+dy[idt];
        int id=(find(name,name+4,a[i][j])-name+1)%4;//注意到A 需要取模
        if(temx>=0&&temx<n&&temy>=0&&temy<m&&a[temx][temy]==name[id])
        {
                maxdfs=max(maxdfs,dfs(temx,temy));
        }
    }
    if(a[i][j]=='A'&&maxdfs!=inf)
        {
               maxdfs+=1;
        }

    return  ans[i][j]= maxdfs;//0 表示没得
}
int main()
{
    int answer=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
        memset(ans,-1,sizeof ans);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(a[i][j]=='D')
    {
        int tem=dfs(i,j);
        if(tem==inf)
           {
            cout<<"Poor Inna!"<<endl;
            return 0;
           }
        answer=max(answer,tem);
    }
    if(answer==0)
        cout<<"Poor Dima!"<<endl;
    else
        cout<<answer<<endl;
    return 0;
}
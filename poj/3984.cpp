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

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int pan[10][10];
int front=0,rear=1;
struct point {
int x,y,pre;
}q[50];

void print_ans(int i){//利用递归输出结果
    if(q[i].pre!=-1)
    {
        print_ans(q[i].pre);
        cout<<'('<<q[i].x<<", "<<q[i].y<<')'<<endl;
    }
}
void bfs(int x1,int y1)
{
   q[front].x=x1;
   q[front].y=y1;
   q[front].pre=-1;

    while(front<rear)//queue!=empty
    {
        for(int i=0;i<4;i++)
        {
            int tx=q[front].x+dx[i];
            int ty=q[front].y+dy[i];
            if(tx<0||tx>=5||ty<0||ty>=5||pan[tx][ty]==1)
                continue;
            pan[tx][ty]=1;//走过的做标记
            q[rear].x=tx;
            q[rear].y=ty;
            q[rear].pre=front;
            rear++;// go into queue
        if(tx==4&&ty==4) print_ans(front);
        }
     front++;//出队
    }
}
int main()
{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
        {
            cin>>pan[i][j];
        }
    cout<<"(0, 0)"<<endl;
    bfs(0,0);
    cout<<"(4, 4)"<<endl;

    return 0;
}
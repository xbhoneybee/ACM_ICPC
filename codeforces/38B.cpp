#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>

using namespace std;

int main()
{
    int pan[10][10]={0};
    int ans=0;
    string s1,s2;
    cin>>s1>>s2;
    int x1,y1,x2,y2;
    x1=s1[0]-'a';
    x2=s2[0]-'a';
    y1=s1[1]-'1';
    y2=s2[1]-'1';
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
    {
        if(i==x1||j==y1)
        pan[i][j]=1;
    }
    pan[x2][y2]=1;
    if(x2-2>=0&&y2-1>=0)
        pan[x2-2][y2-1]=1;
    if(x2-2>=0&&y2+1<8)
        pan[x2-2][y2+1]=1;
    if(x2-1>=0&&y2+2<8)
        pan[x2-1][y2+2]=1;
    if(x2+1<8&&y2+2<8)
        pan[x2+1][y2+2]=1;
    if(x2+2<8&&y2+1<8)
        pan[x2+2][y2+1]=1;
    if(x2+2<8&&y2-1>=0)
        pan[x2+2][y2-1]=1;
    if(x2+1<8&&y2-2>=0)
        pan[x2+1][y2-2]=1;
    if(x2-1>=0&&y2-2>=0)
        pan[x2-1][y2-2]=1;
//wa reason ：ignore add knight beat rook
    if(x1-2>=0&&y1-1>=0)
        pan[x1-2][y1-1]=1;
    if(x1-2>=0&&y1+1<8)
        pan[x1-2][y1+1]=1;
    if(x1-1>=0&&y1+2<8)
        pan[x1-1][y1+2]=1;
    if(x1+1<8&&y1+2<8)
        pan[x1+1][y1+2]=1;
    if(x1+2<8&&y1+1<8)
        pan[x1+2][y1+1]=1;
    if(x1+2<8&&y1-1>=0)
        pan[x1+2][y1-1]=1;
    if(x1+1<8&&y1-2>=0)
        pan[x1+1][y1-2]=1;
    if(x1-1>=0&&y1-2>=0)
        pan[x1-1][y1-2]=1;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
    {
        if(pan[i][j]==0)
            ans++;
    }
    cout<<ans<<endl;
    //cout<<x1<<' '<<y1<<endl;
    //cout<<x2<<' '<<y2<<endl;
    //for(int i=0;i<8;i++)
    //    for(int j=0;j<8;j++)
    //{
    //    cout<<pan[i][j];
    //    if(j==7)cout<<endl;
    //}
    return 0;
}

//技巧，在acm中长使用两个数组进行再二维数组中的移动
eg：
int vx[]={1,0,-1,0};
int vy[]={0,1,0,-1};
for(int i=0;i<4;i++)
{
	x+=vx[i];
	y++vy[i];
	...
}
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct face{
int x;
int y;
}f[6];
int cmp(face f1,face f2)
{
    if(f1.x!=f2.x) return f1.x>f2.x;
    else return f1.y>f2.y;
}
int main()
{
   int h,w;
   while(scanf("%d %d",&w,&h)!=EOF)
   {
       if(w>h)
        {
            f[0].x=w;f[0].y=h;
        }
        else{
            f[0].x=h;f[0].y=w;
        }
       int i=1;
       while(i<6)
       {
           scanf("%d %d",&w,&h);
            if(w>h)
            {
                f[i].x=w;f[i].y=h;
            }
            else{
            f[i].x=h;f[i].y=w;
            }
            i++;
       }
    sort(f,f+6,cmp);
    int flag=1;
    for(int i=0;i<6;i+=2)
    {
        if(f[i].x!=f[i+1].x||f[i].y!=f[i+1].y)
            flag=0;
    }
    if(flag==0)
    {
        cout<<"IMPOSSIBLE"<<endl;
        continue;
    }
   // for(int i=0;i<6;i++)
     //   cout<<f[i].x<<' '<<f[i].y<<endl;
    if(f[1].x==f[3].x&&f[0].y==f[5].x&&f[3].y==f[5].y)//判断3个面是否构成立方体
        cout<<"POSSIBLE"<<endl;
	else cout<<"IMPOSSIBLE"<<endl;
   }
	return 0;
}
//uva1587
//learn the thinking from the internet

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
//wa
int main()
{
    int width[6],height[6];
    int i=0,j=0,w,h;
    while(scanf("%d %d",&w,&h)!=EOF)
    {
        if(w>h){
        width[i++]=w;
        height[j++]=h;
        }
        else{
            width[i++]=h;height[j++]=w;
        }
        for(;i<6;){
            scanf("%d %d",&w,&h);
            if(w>h){
                     width[i++]=w;
                     height[j++]=h;
                    }
            else{
                width[i++]=h;height[j++]=w;
                }
            }

        if(i==6) {
            i=0;
            j=0;
            sort(width,width+6);
            sort(height,height+6);
            if(width[0]==width[1]&&width[2]==width[3]&&width[4]==width[5]&&
            height[0]==height[1]&&height[2]==height[3]&&height[4]==height[5])
                 printf("POSSIBLE\n");
            else printf("IMPOSSIBLE\n");

        }
    }
	return 0;
}
//uva1587
//wa原因,未判断3个面是否能接在一起

//ac大改：

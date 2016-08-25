#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>

using namespace std;

//英文阅读能力,认真读题，看错成两个相邻平行四边形有2个相邻边...
//坑点：给出2边坐标位置不一定按顺序，调整一下


int main()
{
    double x[4]={0},y[4]={0};
    while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf",
                &x[0],&y[0],&x[1],&y[1],&x[2],&y[2],&x[3],&y[3])!=EOF){
    if(x[2]==x[0]&&y[2]==y[0]){      //点相等，xy都要比较
        swap(x[0],x[1]);
        swap(y[0],y[1]);
    }
    else if(x[3]==x[0]&&y[3]==y[0]){
        swap(x[2],x[3]);
        swap(x[0],x[1]);
        swap(y[2],y[3]);
        swap(y[0],y[1]);
    }
    else if(x[3]==x[1]&&y[3]==y[1]){
        swap(x[2],x[3]);
        swap(y[2],y[3]);
    }
    double xd=x[0]+x[3]-x[2];
    double yd=y[0]+y[3]-y[2];
    printf("%.3f %.3f\n",xd,yd);
    }
    return 0;
}                               //注意加else,输入遇到EOF结束



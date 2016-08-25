#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<time.h>
using namespace std;
int ss[50][50];
int main()
{
    int n;
    cin>>n;
    int num=1,vn=n;//使用数组储存数据
    while(vn--){
        for(int i=n-vn-1, j=vn;i<=vn;i++)//下
        {
            ss[i][j]=num++;
        }
        for(int i=vn, j=vn-1;j>=n-vn-1;j--)//左
        {
            ss[i][j]=num++;
        }
        for(int i=vn-1, j=n-vn-1;i>=n-vn-1;i--)//上
        {
            ss[i][j]=num++;
        }
        for(int i=n-vn-1, j=n-vn;j<vn;j++)//右
        {
            ss[i][j]=num++;
        }
    }
        //打印
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
    {
        cout<<ss[i][j]<<' ';
        if(j==n-1)
            cout<<endl;
    }
    //printf("Time used = %.8f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

//#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<vector>
#include<map>
#include<sstream>
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);

using namespace std;

/**
可以设每个门调整的状态为xi 取值范围 0,1
ai1 * x1 xor  ai2 * x2 xor   ain * xn xor bi =ei;
列出线性方程组求解的个数
由于x取值为 0,1 答案就是2的自由变元个数次方。
注意对a[i][i] =1;还有题目把 i，j 顺序给反了。。。。。
*/
int b[40],e[40],x[40];
int a[40][40];
int ans;
int Gauss(int n)
{
    int res=0,r=0;//res 为自由变元个数
    bool freex[40];
    for(int i=0;i<n;i++)
        freex[i]=true;
    for(int i=0;i<n;i++)//处理n行
    {
        for(int j=r;j<n;j++)//当前以第r行为基础进行消元,考虑到自由变元r可能小于i
        {
            if(a[j][i]>0){//寻找首项非0的行
                //如果需要交换则交换
                if(j!=r)
                {
                    for(int k=i;k<=n;k++)
                        swap(a[j][k],a[r][k]);
                }
                break;
            }
        }
        if(a[r][i]==0)
        {
            res++;
            continue;
        }
        for(int j=r+1;j<n;j++)
        {
            if(a[j][i]==0)
                continue;
            for(int k=i;k<=n;k++)
            {
                //消元 第 j 行 和 第 r 行
                a[j][k] =a[j][k]^a[r][k];
            }
        }
        r++;
    }
    for(int i=r;i<n;i++)
    {
        if(a[i][n]!=0)
            return -1;
    }
    return res;
}

int main()
{
    int K,n;
    scanf("%d",&K);
    while(K--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&b[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&e[i]);
        int i,j;
        memset(a,0,sizeof a);
        while(scanf("%d %d",&i,&j)&&(i||j))
        {
            a[j-1][i-1]=1;
        }
        for(int i=0;i<n;i++)
        {
            a[i][i]=1;///!!!
            a[i][n]=e[i]^b[i];
        }

        //高斯消元
        ans= Gauss(n);
        if(ans==-1)
            printf("Oh,it's impossible~!!\n");
        else
        printf("%d\n",1<<ans);
    }
    return 0;
}

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
#define iosfalse ios::snync_with_stdio(false);

using namespace std;
/**
弱智英语题
*/
double a[5][5];
int seq1[1000],seq2[1000];
int num1,num2;
int main()
{
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
        {
        scanf("%lf",&a[i][j]);
        }

    while(scanf("%d",&seq1[num1++]))
    {
        char ch=getchar();
        if(ch=='\n')
            break;
    }
    double ans=1;
    for(int i=1;i<num1;i++)
    {
        ans*=a[seq1[i-1]][seq1[i]];
    }
    printf("%.8f\n",ans);
    ans=1;
    while(scanf("%d",&seq2[num2++]))
    {
        char ch=getchar();
        if(ch=='\n')
            break;
    }
    for(int i=1;i<num2;i++)
    {
        ans*=a[seq2[i-1]][seq2[i]];
    }
    printf("%.8f\n",ans);
    int cons1;
    scanf("%d",&cons1);
    printf("%.8f\n",1./(1-a[cons1][cons1]));
    scanf("%d",&cons1);
    printf("%.8f\n",1./(1-a[cons1][cons1]));
    return 0;
}

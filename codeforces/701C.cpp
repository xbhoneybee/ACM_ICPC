#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>
#include<string.h>
#include<set>
#define inf 100000000.000
using namespace std;


//two point 尺取法
//初始化左右起点,右起点不断向右移动，直到满足条件,计算区间长度
//左起点向右移动,直到满足条件停止再次计算区间长度,右起点接触边界为止。
int main()
{
    int n;
    cin>>n;
    char s[1000005];
    cin>>s;
    int  alpha[200]={0};
    int  usealpha[200]={0};
    int alphnum=0;
    for(int i=0;i<n;i++)
    {
        if(alpha[s[i]]==0)
            {
                alpha[s[i]]=1;
                alphnum++;
            }
    }
    int l=0,r=0,nownum=0;
    int ans=inf;
    while(l<=r&&r<n){

        while(nownum<=alphnum)
        {
                if(usealpha[s[r]]==0)
                {
                    nownum++;
                }
                usealpha[s[r]]++;
                r++;
                if(r==n||nownum==alphnum) break;
        }
        while(usealpha[s[l]]>1)
            {
                usealpha[s[l]]--;
                l++;
            }
        if(r-l<ans&&nownum==alphnum) ans=r-l;
                                               //这里未减去nownum,而是利用右起点继续向右，减去多余。
    }
    cout<<ans<<endl;
    return 0;
}
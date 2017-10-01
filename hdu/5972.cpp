#include <bits/stdc++.h>
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
本质思想 ShiftAnd匹配算法
思路：使用bitset<N> b[10] ，b[i][j]表示值为i的数可以出现在子串的那些位置，
即下标，那么对主串进行遍历 i=0:len-1 。另外定义一个变量bitset<N> ans ,
每次先将ans左移一位，然后将最低位置1，然后令k=当前输入的数，将ans=ans&b[k],
 如果当前ans[N-1]==1,那么主串s[i-N+1]~s[i]就是合法子串，输出；
*/
const int maxn=5e6+50;
char str[maxn];
bitset<1005>b[10],ans;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<10;i++)
            b[i].reset();
        ans.reset();
        for(int i=0;i<n;i++)
        {
            int t;
            scanf("%d",&t);
            for(int j=0;j<t;j++)
            {
                int x;
                scanf("%d",&x);
                b[x].set(i);
            }
        }
        getchar();
        gets(str);//scanf TLE
        int len=strlen(str);//strlen(str)  O N !!! string .size() O 1 !!!
        for(int i=0;i<len;i++)
        {
            ans=ans<<1;
            ans[0]=1;
            ans=ans&b[str[i]-'0'];
            if(ans[n-1]==1)
            {
                char ch=str[i+1];
                str[i+1]='\0';
                puts(str+i-n+1); //printf TLE
                str[i+1]=ch;
            }
        }
    }
    return 0;
}

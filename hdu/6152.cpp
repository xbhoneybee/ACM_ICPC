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
//CCPC 2017 online 1003
/**
队友现场推结论 n>=6一定不成立，赛后知道这是拉姆齐染色定理R(3,3)=6 ,队友666
*/
int mp[6][6];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        if(n>=6)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    int tmp;
                    scanf("%d",&tmp);
                }
            }
        }else{
            memset(mp,0,sizeof mp);
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    scanf("%d",&mp[i][j]);
                }
            }
        }
        if(n>=6)
            printf("Bad Team!\n");
        else {
            bool good=true;
            for(int a=0;a<n;a++)
            {
                for(int b=a+1;b<n;b++)
                {
                    for(int c=b+1;c<n;c++)
                    {
                        if(mp[a][b]==0&&mp[b][c]==0&&mp[a][c]==0)
                            good=false;
                        if(mp[a][b]==1&&mp[b][c]==1&&mp[a][c]==1)
                            good=false;
                    }
                }
            }
            if(good)
                printf("Great Team!\n");
            else printf("Bad Team!\n");
        }

    }
    return 0;
}

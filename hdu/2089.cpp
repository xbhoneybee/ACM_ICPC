#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>
#include<string.h>
#include<set>
#include<queue>
#include<cctype>
#include<map>
#include<stack>
#define inf 1000000000
#define ll long long
#define mod 10000//  这里不要写成100000000+7 define是替换！！！
using namespace std;
#define iosfalse ios::sync_with_stdio(false);
//暴力打表 也可数位dp
int sb[1000000];
int tot=0;
void db()
{
       for(int i=4;i<=1000000;i++)
    {
        char numberc[10];
        sprintf(numberc,"%d",i);
        int len=strlen(numberc);
        for(int j=0;j<len;j++)
        {
            if(numberc[j]=='4')
            {
                sb[tot++]=atoi(numberc);
                break;
            }
            if(numberc[j]=='6'&&j+1<len&&numberc[j+1]=='2')
            {
                sb[tot++]=atoi(numberc);
                break;
            }
        }
    }
}
int main()
{
    int n,m;
    db();
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0&&m==0) break;
        int ans=m-n+1;
        for(int i=0;i<tot;i++)
        {
            if(sb[i]>=n&&sb[i]<=m)
                ans--;
            if(sb[i]>m)
                break;  //少了就TLE
        }
        cout<<ans<<endl;
    }
    return 0;
}

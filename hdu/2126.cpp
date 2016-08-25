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
#define mod 1000000007//  这里不要写成100000000+7 define是替换！！！
using namespace std;
#define iosfalse ios::sync_with_stdio(false);


//这道题我傻逼的将ans 和S 的顺序搞反了，交了10多次 /(ㄒoㄒ)/~~
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int sou[35]={0};
        for(int i=1;i<=n;i++)
            scanf("%d",&sou[i]);
        sort(sou+1,sou+n+1);
        int S=0,sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=sou[i];
            if(sum<=m) S++;
            else break;
        }
        if(S==0) {
            cout<<"Sorry, you can't buy anything."<<endl;
            continue;
        }
        int dp[505][35]={0};
        dp[0][0]=1;        //求和初始化1
        for(int i=1;i<=n;i++)
            for(int j=m;j>=sou[i];j--) //逆序滚动数组
                for(int k=S;k>0;k--)
                {
                dp[j][k]+=dp[j-sou[i]][k-1];//求方案数求和
                }
        int ans=0;
        for(int i=0;i<=m;i++)
            ans+=dp[i][S];      //题目问的是买s件而不是买s件花m元
        cout<<"You have "<<ans<<" selection(s) to buy with "<<S<<" kind(s) of souvenirs."
        <<endl;

    }
    return 0;
}
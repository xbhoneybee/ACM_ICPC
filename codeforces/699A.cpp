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
#define inf 1000000000
#define ll long long
#define mod 1000000007//  这里不要写成100000000+7 define是替换！！！
using namespace std;
#define iosfalse ios::sync_with_stdio(false);

int main()
{
    int n;
    cin>>n;
    char cha[200005];
    ll val[200005];
    scanf("%s",cha);
    int flag=0,ans=inf;
    for(int i=0;i<n;i++)
        scanf("%I64d",&val[i]);
    for(int i=0;i<n;i++)
        //for(int j=0;j<n;j++)
        {
            if(cha[i]=='L') continue;
            if(i+1<n){
                if(cha[i+1]=='R') continue;
                ll tem=(val[i+1]-val[i])/2;
                if(tem<ans) ans=tem;
                i++;
                flag=1;
            }
        }
        if(flag)
        cout<< ans   <<endl;
        else cout<<-1<<endl;
    return 0;
}
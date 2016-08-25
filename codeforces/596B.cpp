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

int b[200005];
int main()
{
    int n;

    while(scanf("%d",&n)!=EOF){
    ll sum=0;
    for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
            sum+=abs(b[i]-b[i-1]);
        }
    cout<<sum<<endl;
    }
    return 0;
}
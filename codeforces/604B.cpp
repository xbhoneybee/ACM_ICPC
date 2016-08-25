#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <math.h>
#include <string.h>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#define inf 1000000000
#define ll long long
#define mod 1000000007//  这里不要写成100000000+7 define是替换！！！
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

int a[100005];
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    vector <int> vec;
    int i,num=0;
    for(i=n;num<2*k-n&&i>=1;i--,num++) //少i>=1 wa点
    vec.push_back(a[i]);
    num=1;
    for(;i>num;i--,num++)
            vec.push_back(a[i]+a[num]);
    sort(vec.begin(),vec.end());
    int ans=*(vec.end()-1);
    printf("%d\n",ans);
    return 0;
}
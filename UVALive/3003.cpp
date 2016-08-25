#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
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
const int MAXN=1025;


//傻逼了，结构体排个序多快
struct  P{
char na[15];
int val;
}p[105];
int cmp(P a,P b)
{
    return a.val<b.val;
}
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        getchar();
        int a[105],b[105],c[105];
        for(int i=0;i<n;i++)
        {
            scanf("%s",p[i].na);
            scanf("%d %d %d",&a[i],&b[i],&c[i]);
            p[i].val=a[i]*b[i]*c[i];
            getchar();
        }
        sort(p,p+n,cmp);
        if(p[0].val==p[n-1].val)
        cout<<"No child has lost jelly."<<endl;
        else cout<<p[0].na<<" has lost jelly to "<<p[n-1].na<<"."<<endl;
    }
    return 0;
}
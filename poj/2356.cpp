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
#define inf 1000000000000000000
#define ll long long
#define mod 1000000007
#define iosfalse ios::sync_with_stdio(false);
using namespace std;
const int MAXN=1024;

//抽屉模型
/*几个数之和是n的倍数，就是对n求余是0。通常大家会想把这些数随机组合，得到的和存放在一个数组里，
但遇到很多数，这就不好办了。由于问题只要找出一组即可，所以我们就是要找到一组。所以建立个抽屉模型，
为什么可以用抽屉模型？有n个数，这些数的连续和分别对n取余得到的余数范围是0~n-1, 不相同的余数个数不超过n，
当个数为n时， 那其中肯定有一组数的和满足条件，若小于n,这当中至少有两组数的余数相同，举个
例子，1，3，5，9，2  ，5个数， 我把它们连续相加变成， 1，4， 9， 18， 20， 仍然是5个数。 
使他们一一对5取余，得到 1， 4， 4， 3， 0。 我把余数当作抽屉，和作为物体， 这里有5个物体，4个抽屉，
第一组数是1,3，第二组数是1,3,5。 用后者减前者便是答案*/

int a[10005];
ll pre[10005];
int main()
{
    int n;
    scanf("%d",&n);
    map<ll ,int> ma;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
         pre[i]%=n;
         if(pre[i]==0){
            printf("%d\n",i);
            for(int j=1;j<=i;j++)
            {
               printf("%d\n",a[j]); 
            }
            break;
         }
        if(ma.count(pre[i])==0)
            ma[pre[i]]=i;
        else{
                printf("%d\n",i-ma[pre[i]]);
            for(int j=ma[pre[i]]+1;j<=i;j++)
                printf("%d\n",a[j]);
            break;
        }
    }
    return 0;
}
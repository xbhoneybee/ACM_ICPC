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

int a,b;
char gap;
int main()
{
    while(1){
    int sum=1;
    while(scanf("%d",&a))
    {
        if(a==0) return 0;
        gap=getchar();
        scanf("%d",&b);
        gap=getchar();
        while(b--) sum*=a;   //注意精度问题，不要用pow(a,b)
        if(gap=='\n')
            break;
    }
    sum--;
    vector<int> factor;
    int mi[32790]={0};
    for(int i=2;i<=sum;i++)
    {
        if(sum%i==0)
            {
                factor.push_back(i);
                mi[i]++;
                sum/=i;
                while(sum%i==0&&sum)
                    {
                        mi[i]++;
                        sum/=i;
                    }
            }
    }
    if(sum!=1) {factor.push_back(sum);mi[sum]++;}//important！！！
    sort(factor.begin(),factor.end(),greater<int>());
    int len=factor.size();
    for(int i=0;i<len-1;i++)
    {
        cout<<factor[i]<<' '<<mi[factor[i]]<<' ';
    }
    cout<<factor[len-1]<<' '<<mi[factor[len-1]]<<endl;
    }
    return 0;
}

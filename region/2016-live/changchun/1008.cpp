#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<cstdlib>
#include <sstream>
#include <deque>
#include<list>
#include<time.h>
#define ll long long
#define LL long long
#define inf 1e8
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
//这道题队友读错题目将出现次数看错成数字即找位置然后一直wa。。。。。
//是个字符串匹配问题，可用kmp不用也过了
int a[1000006],b[1000006];
int KMP_Index(int *a,int *b,int n,int m,int p)
{
    int i=0,j=0;
    int ans=0;
    while(i<n)
    {
        if(a[i]==b[j])
        {
            j++;
            if(j==m)
                {ans++;i=i-((j-1)*p-1);j=0;}
            else i+=p;
        }
        else {
            i=i-(j)*p+1;
            j=0;
        }
    }
    return ans;

}
int main()
{
    iosfalse
    int t;
    cin>>t;
    for(int it=1;it<=t;it++)
    {
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    int n,m,p;
    cin>>n>>m>>p;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    int ans=KMP_Index(a,b,n,m,p);
    cout<<"Case #"<<it<<": "<<ans<<endl;
    }
    return 0;
}

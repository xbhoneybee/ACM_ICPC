#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include<stdlib.h>
#include <sstream>
#include <deque>
#include<list>
#include<time.h>
#define ll long long
#define LL long long
#define inf 1e5
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
using namespace std;

vector<int> vec;
LL two[40]={1};
LL three[40]={1};
LL five[30]={1};
LL seven[30]={1};
void init()
{
    ll ans=1;
    for(int i=1;i<=30;i++)
    {
        ans*=2;
        two[i]=ans;
    }
    ans=1;
    for(int j=1;j<20;j++)
    {
        ans*=3;
        three[j]=ans;
    }
    ans=1;
    for(int q=1;q<15;q++)
    {
        ans*=5;
        five[q]=ans;
    }
    ans=1;
    for(int p=1;p<15;p++)
    {
        ans*=7;
        seven[p]=ans;
    }
    ans=1;
    for(int i=0;i<=30;i++)
        for(int j=0;j<=19;j++)
            for(int q=0;q<=13;q++)
                for(int p=0;p<=11;p++)
    {
        if(1e9>=(two[i]*three[j])*five[q]*seven[p]&&(two[i]*three[j])*five[q]*seven[p]>0)//wa点>0
        {
            ans=(two[i]*three[j]*five[q]*seven[p]);
            vec.push_back(ans);
        }
    }
    sort(vec.begin(),vec.end());
    //vector<int>::iterator ip;
    //int i=0;
    //for(ip=vec.begin();ip!=vec.end();ip++)
    //  {cout<<*ip<<"  ";
    //if((i++)%20==0)
    // cout<<endl;
    //}
}
void solve(int n)
{
    int ans=lower_bound(vec.begin(),vec.end(),n)-vec.begin();
    printf("%d\n",vec[ans]);
}
int main()
{
    int t;
    scanf("%d",&t);
    init();
    while(t--)
    {
        int n;
        scanf("%d",&n);
        solve(n);
    }
    return 0;
}

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

//codeforces 10.3

//B

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int maxn=0;
    int longest=0;
    int num=0;
    int pre=-1,bac=-1;
    s+="_";//方便对于以字母结尾的计数
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
           pre=i;
        if(s[i]==')')
            bac=i;
        if(pre!=-1&&bac!=-1)
        {
            int flag=0;
            for(int j=pre;j<=bac;j++)
            {
                if((s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z'))
                    flag=1;
                else if(flag)
                    num++,flag=0;
            }
            pre=-1;bac=-1;
        }
        if(pre==-1)
        {
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
                maxn++;
            else {
                longest=max(maxn,longest);
                maxn=0;
            }
        }

    }
    cout<<longest<<" "<<num<<endl;
    return 0;
}

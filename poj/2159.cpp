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
#define inf 10000.00
#define iosfalse ios::sync_with_stdio(false);
#define INF 1e8
#define lowbit(x) x&-x
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;

int main()
{
    int ap1[200]={0},ap2[200]={0};
    char ch1[200],ch2[200];
    scanf("%s %s",ch1,ch2);
    int len1=strlen(ch1);
    int len2=strlen(ch2);
    for(int i=0;i<len1;i++)
    {
        ap1[ch1[i]]++;
    }
    for(int i=0;i<len2;i++)
    {
        ap2[ch2[i]]++;
    }
    vector<int> vec1,vec2;
    for(int i=0;i<200;i++)
    {
        if(ap1[i]) vec1.push_back(ap1[i]);
        if(ap2[i]) vec2.push_back(ap2[i]);
    }
    sort(vec1.begin(),vec1.end());
    sort(vec2.begin(),vec2.end());
    if(vec1.size()!=vec2.size())
        printf("NO\n");
    else {
        int flag=1;
        for(int i=0;i<vec1.size();i++)
        {
            if(vec1[i]!=vec2[i])
            {
                flag=0;
                break;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}

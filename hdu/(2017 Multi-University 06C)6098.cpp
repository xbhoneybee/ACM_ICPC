//#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<vector>
#include<map>
#include<sstream>
#include<ctime>
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);

using namespace std;

vector<int>vec[100005];
int a[100005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            {
                scanf("%d",&a[i]);
                vec[i].clear();
            }
        for(int i=2;i<=n;i++)
        {
            int size_n=n/i;
            for(int j=1;j<=size_n;j++)
            {
                vec[i].push_back(a[j*i]);
            }
            sort(vec[i].begin(),vec[i].end());
        }
        sort(a+1,a+n+1);
        for(int i=2;i<=n;i++)
        {
            int cnt=0;
            for(int ed=vec[i].size()-1;cnt<vec[i].size();cnt++)
            {
                if(a[n-cnt]!=vec[i][ed-cnt])
                {
                    printf("%d",a[n-cnt]);
                    if(i<n)
                    printf(" ");
                    else printf("\n");
                    break;
                }
            }
            if(cnt==vec[i].size())
            {
                printf("%d",a[n-cnt]);
                if(i<n)
                printf(" ");
                else printf("\n");
            }
        }
    }
    return 0;
}

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
using namespace std;
const int maxn = 5005;
long long soup[maxn];
long long dish[maxn];
long long dessert[maxn];
long long beverage[maxn];
int main()
{
    int l,s,m,d,b;

    while (~scanf("%d %d %d %d %d",&l,&s,&m,&d,&b))
    {
        long long ans=0;
        if (l == 0&&s==0&&m==0&&d==0&&b==0) {
            break;
        }
     for (int i = 0; i < s; i++) {
            scanf("%I64d",&soup[i]);
        }
        for (int i = 0; i < m; i++) {
           scanf("%I64d",&dish[i]);
        }
        for (int i = 0; i < d; i++) {
            scanf("%I64d",&dessert[i]);
        }
        for (int i = 0; i < b; i++) {
            scanf("%I64d",&beverage[i]);
        }
        vector<long long> vq;
        vector<long long> vh;
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < m; j++) {
            long long cnt = soup[i] + dish[j];
                vq.push_back(cnt);
            }
        }
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < b; j++) {
            long long cnt = dessert[i] + beverage[j];
                vh.push_back(cnt);
        }
    }
    sort(vh.begin(), vh.end());
    sort(vq.begin(), vq.end());
    int en = lower_bound(vq.begin(), vq.end(), l) - vq.begin();
    en--;
    for (int i = 0; i <= en; i++) {
        long long ant = l - vq[i];
            ll j = upper_bound(vh.begin(), vh.end(), ant) - vh.begin();
            ans+=j;
    }
    printf("%I64d\n",ans);
    }
    return 0;
}

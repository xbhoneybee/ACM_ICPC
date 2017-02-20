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
#define ll long long
#define LL long long
#define inf 10000000000000
#define iosfalse ios::sync_with_stdio(false);
#define lowbit(x) x&-x
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll a[20004];
        int one=0,none=0;
        for(int i=0;i<n;i++)
            {
                cin>>a[i];
                if(a[i]==1)
                    one++;
                else none++;
            }
        if(one&1||(one%2==0&&none!=0))
            cout<<"poopi"<<endl;
        else cout<<"piloop"<<endl;
    }
    /*先手有优势，可以控制后手行动
     *若1的数量为奇数：
     *依次把每个不是1的数取成1，这样对手只能把这堆取完，这样两人合作把所有不是1的数取完，先手胜。
     *若1的数量为偶数：
     *同上，强迫对手与自己合作取完不是1的数直到最后一个不是1的数，先手直接取完这个数，这样后手先取是1的那些数，先手胜。
     *因此，只有一种情况后手胜，即全为1且1的数量为偶数。
     */
    return 0;
}

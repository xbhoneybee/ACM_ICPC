#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <math.h>
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

int main()
{
    int n;
    int a[30];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
    sort(a,a+n);
    set<int >st;
    ll sum=0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]!=a[i+1])
            {
                sum+=a[i];
                st.insert(a[i]);
            }
        else {
            while(a[i]>=1)
            {
                if(st.count(a[i]-1)==0)
                {
                    st.insert(a[i]-1);
                    sum+=a[i]-1;
                    break;
                }
                else {a[i]--;}
            }
        }
    }
    if(st.count(a[n-1])==0)
        {
            sum+=a[n-1];
        }
    else{
            while(a[n-1]>=1)
            {
                if(st.count(a[n-1]-1)==0)
                {
                    st.insert(a[n-1]-1);
                    sum+=a[n-1]-1;
                    break;
                }
                else {a[n-1]--;}
            }
    }
    printf("%I64d\n",sum);
    return 0;
}
#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>
#include<string.h>
#include<set>
#include<queue>
#include<cctype>
#include<map>
#include<stack>
#define inf 1000000000
#define ll long long
#define mod 10000//  这里不要写成100000000+7 define是替换！！！
using namespace std;
#define iosfalse ios::sync_with_stdio(false);

//LIS  n log n

int main()
{
    iosfalse
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[40004]={0};
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int b[40004]={0};
        b[1]=a[1];
        int l,r,mid,len=1;
        for(int i=2;i<=n;i++)
        {
           if( b[len]<a[i])
           {
               b[++len]= a[i];
               continue;
           }
           l=1,r=len;
           while(l<=r)
           {
               mid=l+(r-l)/2;
               if(b[mid]<a[i])
                l=mid+1;
               else r=mid-1;
           }
           b[l]=a[i];
        }
        cout<<len<<endl;
    }
    return 0;
}
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
#define inf 1000000000.000
#define ll long long
#define mod 1000000007//  这里不要写成100000000+7 define是替换！！！
using namespace std;


//使用gcd判断是否互质，暴力枚举，不要找质数，不要分解质因数
int gcd(int x , int y)
{
    if(x<y) swap(x,y);
    if(!y)
    return x;
    else return gcd(y , x%y);
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b,c,d;
        cin>>a>>b;
        d=a/b;
        for(int j=2;;j++)
        {
            if(gcd(j,d)==1)
            {
                c=j*b;
                break;
            }
        }
     cout<<c<<endl;
    }
}
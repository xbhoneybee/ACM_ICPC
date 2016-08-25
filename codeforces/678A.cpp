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

int main()
{
    int n,k;
    cin>>n>>k;
    long long  x;
    for(int i=n/k+1;;i++)  //i=n/k+1 优化
    {
        x=i*k;
        if(x>n)
            break;
    }
    cout<<x<<endl;
    return 0;
}

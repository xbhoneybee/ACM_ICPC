#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string.h>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#include <sstream>
#define inf 100000000
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
using namespace std;




//A  可能跳出去 ,就是在一方需要跳动但另一方向限制不能跳动

int main()
{
    int n,m,i,j,a,b;
    cin>>n>>m>>i>>j>>a>>b;
    if(n==1||m==1)
    {
        if((i==1&&j==1)||(i==1&&j==m)||(i==n&&j==1)||(i==n&&j==m))
        cout<<0<<endl;
        else cout<<"Poor Inna and pony!"<<endl;
        return 0;
    }
    int dx=n-i;
    int dy=m-j;
    int ansx1=inf,ansx2=inf,ansy1=inf,ansy2=inf;
    if((i-1)%a==0) ansx1=(i-1)/a;
    if((j-1)%b==0) ansy1=(j-1)/b;
    if(dx%a==0)ansx2=dx/a;
    if(dy%b==0) ansy2=dy/b;
    int ans=inf;
    if((ansx1-ansy1)%2==0&&ansx1!=inf&&ansy1!=inf)
       {
        if(ansx1==0&&ansy1==0)
        {
            cout<<0<<endl;return 0;
        }else if(ansx1==0||ansy1==0)
        {
            if((i+a>n&&i-a<1)||(j+b>m&&j-n<1))
            {
                cout<<"Poor Inna and pony!"<<endl;
                return 0;
            }
        }
        int tem=max(ansx1,ansy1);
        ans=min(ans,tem);
       }
    if((ansx1-ansy2)%2==0&&ansx1!=inf&&ansy2!=inf)
       {
        if(ansx1==0&&ansy2==0)
        {
            cout<<0<<endl;return 0;
        }else if(ansx1==0||ansy2==0)
        {
            if((i+a>n&&i-a<1)||(j+b>m&&j-n<1))
            {
                cout<<"Poor Inna and pony!"<<endl;
                return 0;
            }
        }
        int tem=max(ansx1,ansy2);
        ans=min(ans,tem);
       }
    if((ansx2-ansy1)%2==0&&ansx2!=inf&&ansy1!=inf)
       {
        if(ansx2==0&&ansy1==0)
        {
            cout<<0<<endl;return 0;
        }else if(ansx2==0||ansy1==0)
        {
            if((i+a>n&&i-a<1)||(j+b>m&&j-n<1))
            {
                cout<<"Poor Inna and pony!"<<endl;
                return 0;
            }
        }
        int tem=max(ansx2,ansy1);
        ans=min(ans,tem);
       }
    if((ansx2-ansy2)%2==0&&ansx2!=inf&&ansy2!=inf)
       {
        if(ansx2==0&&ansy2==0)
        {
            cout<<0<<endl;return 0;
        }else if(ansx2==0||ansy2==0)
        {
            if((i+a>n&&i-a<1)||(j+b>m&&j-n<1))
            {
                cout<<"Poor Inna and pony!"<<endl;
                return 0;
            }
        }
        int tem=max(ansx2,ansy2);
        ans=min(ans,tem);
       }
    if(ans!=inf)
        cout<<ans<<endl;
    else cout<<"Poor Inna and pony!"<<endl;
    return 0;
}